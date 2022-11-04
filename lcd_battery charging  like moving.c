/**********************************************/
/* Author : Prasanna */
/* Date   : 04-11-2022 */
/* Filename: lcd moving like battery charge*/
/* Description :lcd move*/
/**********************************************/
#include<htc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define RS RC0
#define RW RC1
#define EN RC2

void delay();
   
   void lcd_cmd (unsigned char cmd);
   void lcd_data (unsigned char data);
   
   int main()
   
  {
	  int i,j;
	 
	  unsigned char obj0[8]={0x04,0x1F,0x11,0x11,0x11,0x11,0x1F,0x1F};
	  unsigned char obj1[8]={0x04,0x1F,0x11,0x11,0x11,0x1F,0x1F,0x1F};
	  unsigned char obj2[8]={0x04,0x1F,0x11,0x11,0x1F,0x1F,0x1F,0x1F};
	  unsigned char obj3[8]={0x04,0x1F,0x11,0x1F,0x1F,0x1F,0x1F,0x1F};
	  unsigned char obj4[8]={0x04,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
	  unsigned char obj5[8]={0x04,0x0C,0x14,0x04,0x04,0x04,0x1F,0x00};
	  unsigned char obj6[8]={0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x0E};
	  unsigned char obj7[8]={0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x0E};
	  unsigned char obj8[8]={0x00,0x01,0x0A,0x04,0x08,0x12,0x00,0x00};
	 
   TRISD=0;// 8 BIT TO COMMUNICATE LCD DB0-DB7
   TRISC0=0;//RS PIN
   TRISC1=0;//RW PIN
   TRISC2=0;//EN PIN
   TRISB1=1;//INPUT/OUTPUT
   RB1=1;
   
   PORTD=0x00;
           
    lcd_cmd (0X38);//init 5X8-FONT TYPE ,2-DISPLAY LINE, 8-BITE
    lcd_cmd (0X0F);//DISPLAY ON D-SET DISPLAY ,C-CURSOR,B-BLINK ON/OFF
    lcd_cmd (0x0C);
    lcd_cmd (0x01);//CLEAR DISPLAY
    lcd_cmd (0x02);//RETURN TO HOME
    lcd_cmd (0x06);//ENTRY MODE SET-ID-INCREAMENT/DECREAMENT,SH-SHIFT OF ENTRI DISPLAY
    
    lcd_cmd (0x40);//CGRAM ADDRESS
    __delay_ms(500);
    
    for(i=0; i<8; i++)
    lcd_data(obj0[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj1[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj2[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj3[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj4[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj5[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj6[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj7[i]);
    
    for(i=0; i<8; i++)
    lcd_data(obj8[i]);
      
    
    
    __delay_ms(500);
    //lcd_cmd(0X80);
    
  while(1)
	  {
	  	if(RB1 ==0)
		  	{   
			  	lcd_cmd (0x01);//CLEAR DISPLAY
			  	lcd_cmd(0xC0);//WERE WE NEED TO BLINK 
			  	__delay_ms(100);
			  	lcd_data(0);//WHICH OBJ WANT TO BLINK
			  	__delay_ms(100);
			  	
			  	lcd_cmd(0xC0);
			  	__delay_ms(100);
			  	lcd_data(1);
			  	__delay_ms(100);
			  	
			  	lcd_cmd(0xC0);
			  	__delay_ms(100);
			  	lcd_data(2);
			  	__delay_ms(100);
			  	
			    lcd_cmd(0xC0);
			  	__delay_ms(100);
			  	lcd_data(3);
			  	__delay_ms(100);
			  	
			  	lcd_cmd(0xC0);
			  	__delay_ms(100);
			  	lcd_data(4);
			  	__delay_ms(100);
			  
			  	lcd_cmd(0xC1);
			  	__delay_ms(100);
			  	lcd_data(5);
			  	__delay_ms(100);
			  	
			  	
			  	lcd_cmd(0xC2);
			  	__delay_ms(100);
			  	lcd_data(6);
			  	__delay_ms(100);
			  	
			    lcd_cmd(0xC3);
			  	__delay_ms(100);
			  	lcd_data(7);
			  	__delay_ms(100);
			  	
			  	  lcd_cmd(0xC4);
			  	__delay_ms(100);
			  	lcd_data(8);
			  	__delay_ms(100);
			  	
			  		
			   
			  	
			  	
			  	
			  	
			}    
   } 
   } 
    

void delay()
{
	 TMR1CS=0;
	 T1CKPS0=1;
	 T1CKPS1=1;
	 TMR1H=0x0B;
	 TMR1L=0xDC;
	 TMR1ON=1;
	 while(TMR1IF==0);
	 TMR1IF=0;
	 TMR1ON=0;
}


void lcd_cmd(unsigned char cmd)

{ 
	RS =0;
	RW =0;
	EN =1;
	PORTD =cmd;
	__delay_ms(100);
	EN =0;
	
}
void lcd_data (unsigned char data)

{
	RS =1;
	RW =0;
	EN =1;
	PORTD =data;
	__delay_ms(100);
	EN =0;
}	