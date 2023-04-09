/*
 * LCD.c
 *
 * Created: 10/24/2021 3:34:02 PM
 *  Author: lenovo
 */ 


#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	LCD_INIT();
	LCD_SEND_STRING("ahmed");
	LCD_SEND_CMD(0x07);
	_delay_ms(1000);
	LCD_SEND_CHAR('a');
	LCD_SEND_CMD(0x07);
	_delay_ms(1000);
	LCD_SEND_CHAR('b');
	LCD_SEND_CMD(0x07);
	_delay_ms(1000);
	LCD_SEND_CHAR('c');
	LCD_SEND_CMD(0x07);
	_delay_ms(1000);
	
}