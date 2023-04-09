/*
 * ADC_temp.c
 *
 * Created: 11/27/2021 5:12:27 PM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include "buzzer.h"

char read_val;
unsigned short temp;

int main(void)
{
	LCD_INIT();
	ADC_init();
	LCD_SEND_STRING("temp=");
	buzzer_init('A',5);
    while(1)
    {
        temp=(ADC_read()*0.25);
		if(temp<10)
		{
			LCD_MOVE_CURSOR(1,6);
			LCD_SEND_CHAR(0x30);// ascii code of zero
			LCD_SEND_CHAR(temp+48);
			LCD_SEND_CHAR(0xDF);
			LCD_SEND_CHAR('c'); 
		}	
		else if (temp<100)
		{
			LCD_MOVE_CURSOR(1,6);
			LCD_SEND_CHAR((temp/10)+48);
			LCD_SEND_CHAR((temp%10)+48);
			LCD_SEND_CHAR(0xDF);
			LCD_SEND_CHAR('c');
		}	
		else
		{
		}	
		if(temp>70)
		{ 
			buzzer_on('A',5);
		}									
    }
}