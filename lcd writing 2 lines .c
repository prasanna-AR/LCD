/**********************************************/
/* Author : Prasanna */
/* Date   : 23-10-2022 */
/* Filename: LCD WRITING 2 LINES*/
/* Description : 2 LINES BLINK */
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
   TRISD=0;// 8 BIT TO COMMUNICATE LCD DB0-DB7
   TRISC0=0;//RS PIN
   TRISC1=0;//RW PIN
   TRISC2=0;//EN PIN
   
   PORTD=0x00;

 lcd_cmd (0X38);//init 5X8-FONT TYPE ,2-DISPLAY LINE, 8-BITE
 lcd_cmd (0X0E);//DISPLAY ON D-SET DISPLAY ,C-CURSOR,B-BLINK ON/OFF
 lcd_cmd (0x01);//CLEAR DISPLAY
 lcd_cmd (0x02);//RETURN TO HOME
 lcd_cmd (0x06);//ENTRY MODE SET-ID-INCREAMENT/DECREAMENT,SH-SHIFT OF ENTRI DISPLAY
 lcd_cmd (0x80);// SET DDRAM
 
 
 lcd_data ('T');
 lcd_data ('A');
 lcd_data ('L');  
 lcd_data ('K');  
 lcd_data ('');
 delay();  
 lcd_data ('I');  
 lcd_data ('S');  
 lcd_data ('');
 delay(); 
 lcd_data ('C');  
 lcd_data ('H');
 lcd_data ('E');  
 lcd_data ('A');  
 lcd_data ('P');
 lcd_data (''); 
 delay();  
 lcd_data (''); 
 delay(); 
 lcd_data ('');
 delay(); 


 lcd_cmd (0xC0);// SET DDRAM second line to blink
 
 
 lcd_data ('S');
 lcd_data ('H');
 lcd_data ('O');  
 lcd_data ('W');  
 lcd_data ('');
 delay();   
 lcd_data ('M');  
 lcd_data ('E');  
 lcd_data ('');
 delay(); 
 lcd_data ('T');  
 lcd_data ('H');
 lcd_data ('E');  
 lcd_data ('');
 delay();   
 lcd_data ('C');
 lcd_data ('O');  
 lcd_data ('D'); 
 lcd_data ('E');
 delay(); 
 
 
 
        
 while(1);
 
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
	 TMR1ON=1;
	 
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
	   