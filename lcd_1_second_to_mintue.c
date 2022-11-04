/****************/
/* Author : Prasanna */
/* Date   : 28-10-2022 */
/* Filename:LCD_1_SECOND_TO_MINTUE */
/* Description :SECOND_TO_MINTUE*/
/****************/
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

int main()
{  
   int i,j,k,l,m,n;
   TRISD=0;// 8 BIT TO COMMUNICATE LCD DB0-DB7
   TRISC0=0;//RS PIN
   TRISC1=0;//RW PIN
   TRISC2=0;//EN PIN
   
   PORTD=0x00;
           
    lcd_cmd (0X38);//init 5X8-FONT TYPE ,2-DISPLAY LINE, 8-BITE
    lcd_cmd (0X0F);//DISPLAY ON D-SET DISPLAY ,C-CURSOR,B-BLINK ON/OFF
    lcd_cmd (0x01);//CLEAR DISPLAY
    lcd_cmd (0x02);//RETURN TO HOME
    lcd_cmd (0x04);//ENTRY MODE SET-ID-INCREAMENT/DECREAMENT,SH-SHIFT OF ENTRI DISPLAY
    lcd_cmd (0x80);// SET DDRAM
    lcd_cmd (0x10);
    while(1) 
    {  
		for(i=0;i<3;i++)
		 for(j=0;j<10;j++)
		  for(k=0;k<6;k++)
		   for(l=0;l<10;l++)
		    for(m=0;m<6;m++)
		     for(n=0;n<10;n++)
		      
  		{
	  		lcd_cmd(0x8F);
	  		lcd_data('M');
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x8E);
	  		lcd_data('A');
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x8D);
	  		lcd_data(':');
	  		 __delay_ms(1);
	  		 
	 		 lcd_cmd(0x8C);
	  		lcd_data(n+0X30);
	  		 __delay_ms(1);
	  		 
	  		  lcd_cmd(0x8B);
	  		lcd_data(m+0X30);
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x8A);
	  		 lcd_data(':');
	  		 __delay_ms(1);
	  		 
	  		  lcd_cmd(0x89);
	  		lcd_data(l+0X30);
	  		 __delay_ms(1);
	  		 
	  		  lcd_cmd(0x88);
	  		lcd_data(k+0X30);
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x87);
	  		lcd_data(':');
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x86);
	  		lcd_data(j+0X30);
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x85);
	  		lcd_data(i+0X30);
	  		 __delay_ms(1);
	  		 
	  		 lcd_cmd(0x84);
	  		lcd_data(':');
	  		 __delay_ms(1);
	  		 
	  		 
	  	}
	  
	 } 
}  
  
              
   
   
   
   

	   

   
            