/********************************************************/
/* Author 		: Prasanna */
/* Date   		: 16-11-2022 */
/* Filename		: PIR_SENSOR*/
/* Description  : PIR_SENSOR_HC_SR501 */
/*********************************************************/
#include <htc.h>
#include <stdio.h>
# define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define PIR RC3//FOR SENSOR OUTPUT

void main()

{
	TRISC3 = 1;// FOR SENSOR OUTPUT
	TRISC6 = 0;// FOR LIGHT
	while(1)
	
	{
		if(RC3 == 1)//OUTPUT IS ON 
		
		{ 
			RC6 = 1;//LED BLINK
			
			
	     }
	     else//OUTPUT IS OFF
	    
	     
	     {
		     RC6 = 0;//LED NOT BLINK 
		     
		     
		   }

	}	               
		   

}		   	