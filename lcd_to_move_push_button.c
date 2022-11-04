/**********************************************/
/* Author : Prasanna */
/* Date   : 03-11-2022 */
/* Filename: LCD_MOVE_PUSH_BUTTON */
/* Description : MOVE_LCD */
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
	  int i;
	  unsigned char obj0[8]={0x06,0x09,0x0B,0x04,0x16,0x1C,0x04,0x04};
	  
	  
   TRISD=0;// 8 BIT TO COMMUNICATE LCD DB0-DB7
   TRISC0=0;//RS PIN
   TRISC1=0;//RW PIN
   TRISC2=0;//EN PIN
   TRISB1=1;
   RB1=1;
   
   PORTD=0x00;
           
    lcd_cmd (0X38);//init 5X8-FONT TYPE ,2-DISPLAY LINE, 8-BITE
    lcd_cmd (0X0F);//DISPLAY ON D-SET DISPLAY ,C-CURSOR,B-BLINK ON/OFF
    lcd_cmd (0x0C);
    lcd_cmd (0x01);//CLEAR DISPLAY
    lcd_cmd (0x02);//RETURN TO HOME
    lcd_cmd (0x06);//ENTRY MODE SET-ID-INCREAMENT/DECREAMENT,SH-SHIFT OF ENTRI DISPLAY
    
    lcd_cmd (0x40);
    __delay_ms(500);
    
    for(i=0; i<8; i++)
    lcd_data(obj0[i]);
    
    __delay_ms(500);
    lcd_cmd(0X80);
    
  while(1)
	  {
	  	if(RB1 ==0)
		  	{   
			  	lcd_cmd (0x01);//CLEAR DISPLAY
			  	lcd_cmd(0xC0);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x81);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xC2);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x83);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xC4);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x85);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xC6);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x87);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xC8);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x89);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xCA);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x8B);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xCC);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x8D);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0xCE);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			  	
			  	lcd_cmd (0x01);
			  	lcd_cmd(0x8F);
			  	__delay_ms(100);
			  	lcd_data(0);
			  	__delay_ms(100);
			}    
   } 
   } 
    /*for(i=0;i<2;i++)
    {
	    lcd_data(i);
	    __delay_ms(100);
	}
	
	if(RB1 ==0)
	{
		lcd_cmd(0x40);
		__delay_ms(100);
		lcd_data(0);
		__delay_ms(100);
		
	}*/	
	 
	


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