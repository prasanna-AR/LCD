/**************************************************************************/
/* Author 	: Prasanna */
/* Date   	: 20-11-2022 */
/* Filename     : LCD_ULTRASONIC_SENSOR_AND_PIR_SENSOR*/
/* Description  : ULTRASONIC_SENSOR_HC_SR04(0 CM_To_200 CM)_AND_PIR_SENSOR */
/***************************************************************************/
#include<htc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define PIR RD7                   //PIR SENSOR OUTPUT 
#define RS RD0                    //REGISTER SELECT SIGNAL
#define RW RD1                    //ENABLE SIGNAL
#define EN RD2                    //ENABLE SIGNAL

void Lcd_Cmd(unsigned char Cmd)
{
	RS = 0;
	RW = 0;
	EN = 1;
	PORTC = Cmd;
	__delay_ms(10);
	EN = 0;
}

void lcd_print(unsigned char data )
{
	RS = 1;
	RW = 0;
	EN = 1;
	PORTC = data;
	__delay_ms(10);
	EN = 0;
}

void Lcd_Init()
{
	TRISC = 0X00;
	Lcd_Cmd(0X38);             //Init5x8-FONT TYPE, 2-DISPLAY LINE, 8- BITE
	Lcd_Cmd(0X01);             //CLEAR DISPLAY
	Lcd_Cmd(0X0F);             //DISPLAY ON D-SET DISPLAY, C-CURSOR,B-BLINK ON/OFF
	Lcd_Cmd(0X0C);
	Lcd_Cmd(0X02);             //RETURN TO HOME
	Lcd_Cmd(0X06);             //ENTRY MODE SET-ID-INCREMENT/DECREMENT,SH-SHIFT OF ENTRI DISPLAY
	Lcd_Cmd(0X80);             //DDRAM/FRIST LINE PRINT
}

void Lcd_Write(unsigned char *s)
{
	while(*s)
	{
		lcd_print(*s++);      //FOR WRITING A LETTER
	}
}

int main()
{ 
  int a,b,c,d,f,g,h,i=1;
  TRISD0 = 0;
  TRISD1 = 0;
  TRISD2 = 0;                //FOR RS,RW,EN PIN
  TRISB = 0b00010000;         //RB4 as Input PIN (ECHO)
  TRISC = 0x00;               //LCD Pins as Output
  TRISA = 0;
  TRISD7 = 1;                 //FOR ULTRASONIC SENSOR AND RD7 AS OUTPUT PIN FOR PIR SENSOR
  
 
  
  while(1)
	
	{
		if(RD7 == 1)                  //FOR PIR OUTPUT PIN
		
		{ 
			RB3 = 1;                  //LED ON PIN
			
		}	
	  
		   Lcd_Init();
           T1CON = 0x10;               //Initialize Timer Module
   	
           TMR1H = 0;                //Sets the Initial Value of Timer
           TMR1L = 0;                //Sets the Initial Value of Timer

           RB0 = 1;                  //TRIGGER HIGH
           __delay_us(10);           //10uS Delay 
           RB0 = 0;                  //TRIGGER LOW

           while(!RB4);              //Waiting for Echo
           TMR1ON = 1;               //Timer Starts
           while(RB4);               //Waiting for Echo goes LOW
           TMR1ON = 0;               //Timer Stops
  
           a = (TMR1L | (TMR1H<<8)); //Reads Timer Value
           b = a/156.71;              //Converts Time to Distance
           c = b +1;                 //Distance Calibration
          if(c>=0 && c<=200)         //Check whether the result is valid or not
      { 
	  
          Lcd_Cmd(0x80);             //WERE WE NEED TO PRINT IN LCD
          Lcd_Write("Distance = ");  //PRINTING IN LCD
          Lcd_Cmd(0xC0);            //WERE WE NEED TO PRINT IN LCD
          Lcd_Write("HUMAN");       //PRINTING ON LCD
			
         
          Lcd_Cmd(0x8D);             //WERE WE NEED TO PRINT IN LCD
          lcd_print(c%10 + 48);      
          RA0 = 1;

          Lcd_Cmd(0x8C);             //WERE WE NEED TO PRINT IN LCD
          d = c/10;
          lcd_print(d%10 + 48);
          RA0 = d;
      
          Lcd_Cmd(0x8B);              //WERE WE NEED TO PRINT IN LCD
          f = d/10;
          lcd_print(f%10 + 48);	
          RA0 = f; 

          Lcd_Cmd(0x8E);              //WERE WE NEED TO PRINT IN LCD
          Lcd_Write("cm");            //PRINTING IN LCD
	   }  

    else
    {
	     {
		    RB3 = 0;               //LED OFF
		    Lcd_Cmd(0xC0);         //WERE WE NEED TO PRINT IN LCD
                    Lcd_Write("NO HUMAN"); //PRINTING IN LCD
		     
		     
		   }
	    
            Lcd_Cmd(0x01);          //WERE WE NEED TO PRINT IN LCD
            Lcd_Cmd(0x80);           //WERE WE NEED TO PRINT IN LCD
            Lcd_Write("Out of Range");//PRINTING IN LCD
      
    }
    __delay_ms(100);           
  }
}			