/****************/
/* Author : Prasanna */
/* Date   : 05-11-2022 */
/* Filename:LCD_keypad*/
/* Description :keypad*/
/****************/
#include<htc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);


#define RS RB1//register selected signal
#define RW RB2//read/write selected signal
#define EN RB3//enable signal

#define row_1 RD0//input pin
#define row_2 RD1//input pin
#define row_3 RD2//input pin
#define row_4 RD3//input pin

#define col_1 RD4//output pin
#define col_2 RD5//output pin
#define col_3 RD6//output pin
#define col_4 RD7//output pin


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
	PORTC =cmd;
	__delay_ms(100);
	EN =0;
	
}
void lcd_data (unsigned char data)

{
	RS =1;
	RW =0;
	EN =1;
	PORTC =data;
	__delay_ms(100);
	EN =0;
}	

int main()
{  
	

   
   TRISC=0;// 8 BIT TO COMMUNICATE LCD BB0-BB7
   TRISB1=0;//RS PIN
   TRISB2=0;//RW PIN
   TRISB3=0;//EN PIN
   TRISD=0xF0;//KEYPAD 
   
   PORTC=0x00;
           
    lcd_cmd (0X38);//init 5X8-FONT TYPE ,2-DISPLAY LINE, 8-BITE
    lcd_cmd (0X0D);//DISPLAY ON D-SET DISPLAY ,C-CURSOR,B-BLINK ON/OFF
    lcd_cmd (0x01);//CLEAR DISPLAY
    lcd_cmd (0x02);//RETURN TO HOME
    lcd_cmd (0x04);//ENTRY MODE SET-ID-INCREAMENT/DECREAMENT,SH-SHIFT OF ENTRI DISPLAY
    lcd_cmd (0x40);// SET CGRAM
    
    lcd_data('0');
    lcd_data('1');
    lcd_data('2');
    lcd_data('3');
    lcd_data('4');
    lcd_data('5');
    lcd_data('6');
    lcd_data('7');
    lcd_data('8');
    lcd_data('9');
    lcd_data('A');
    lcd_data('B');
    lcd_data('C');
    lcd_data('D');
    lcd_data('E');
    lcd_data('F');
    
    
   
    
    while(1)
    
    
   
    
    
    {
		
		row_1 =1;//which row we need 
		row_2 =0;
		row_3 =0;
		row_4 =0;
		
		if (PORTD == 0x11)//which button we need to push
		
		{
			lcd_cmd(0x01);//clear display
			lcd_cmd(0x80);//in lcd were we need to blink
			lcd_cmd(col_1 == 1);which collam we need 
			lcd_data('0');in lcd what we need to print
			__delay_ms(100);
		
		
		}
		
		if (PORTD == 0x21)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x81);
			lcd_cmd(col_1 == 1);
			lcd_data('1');
			__delay_ms(100);	
		}
		if (PORTD == 0x41)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x82);
			lcd_cmd(col_1 == 1);
			lcd_data('2');	
			__delay_ms(100);	
		}
		if (PORTD == 0x81)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x83);
			lcd_cmd(col_1 == 1);
			lcd_data('3');
			__delay_ms(100);
		}
	
	    row_1 =0;
		row_2 =1;
		row_3 =0;
		row_4 =0;
		
		if (PORTD==0x12)
		
		{
			lcd_cmd(0x01);
			lcd_cmd(0x84);
			lcd_cmd(col_2 == 1);
			lcd_data('4');
			__delay_ms(100);
			
		
		}
		
		if (PORTD==0x22)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x85);
			lcd_cmd(col_2 == 1);
			lcd_data('5');
			__delay_ms(100);
			
		}
		if (PORTD==0x42)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x86);
			lcd_cmd(col_2 == 1);
			lcd_data('6');
			__delay_ms(100);
			
		}
		if (PORTD==0x82)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x87);
			lcd_cmd(col_2 == 1);
			lcd_data('7');
			__delay_ms(100);
		
		}
		
		row_3 =1;
		row_2 =0;
		row_1 =0;
		row_4 =0;
		
		if (PORTD == 0x14)
		  
		{
			lcd_cmd(0x01);
			lcd_cmd(0x88);
			lcd_cmd(col_3 == 1);
			lcd_data('8');
			__delay_ms(100);
		}
		
		if (PORTD == 0x24)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x89);
			lcd_cmd(col_3 == 1);
			lcd_data('9');
			__delay_ms(100);
		
			
		}
		if (PORTD == 0x44)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x8A);
			lcd_cmd(col_3 == 1);
			lcd_data('A');	
			__delay_ms(100);	
			
		}
		if (PORTD == 0x84)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x8B);
			lcd_cmd(col_3 == 1);
			lcd_data('B');
			__delay_ms(100);
		
		}	
		row_4 =1;
		row_2 =0;
		row_1 =0;
		row_3 =0;
		
		if (PORTD == 0x18)
	
		{
			lcd_cmd(0x01);
			lcd_cmd(0x8C);
			lcd_cmd(col_4 == 1);
			lcd_data('C');
			__delay_ms(100);
		
		}
		
		if (PORTD == 0x28)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x8D);
			lcd_cmd(col_4 == 1);
			lcd_data('D');
			__delay_ms(100);
		
			
		}
		if (PORTD == 0x48)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x8E);
			lcd_cmd(col_4 == 1);
			lcd_data('E');
			__delay_ms(100);
		
			
		}
		if (PORTD == 0x88)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x8F);
			lcd_cmd(col_4 == 1);
			lcd_data('F');
			__delay_ms(100);
		}	
				
		
	}
	
}				