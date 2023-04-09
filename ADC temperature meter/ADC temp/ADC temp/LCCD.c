/*
 * LCCD.c
 *
 * Created: 10/24/2021 3:52:59 PM
 *  Author: lenovo
 */ 
#include "LCD.h"

#define F_CPU 8000000UL
#include <util/delay.h>
void LCD_INIT(void)
{
	#if defined EIGHT_BIT_MODE
	DIO_SET_PIN_DIR('D',0,1);
	DIO_SET_PIN_DIR('D',1,1);
	DIO_SET_PIN_DIR('D',2,1);
	DIO_SET_PIN_DIR('D',3,1);
	DIO_SET_PIN_DIR('D',4,1);
	DIO_SET_PIN_DIR('D',5,1);
	DIO_SET_PIN_DIR('D',6,1);
	DIO_SET_PIN_DIR('D',7,1);
	DIO_SET_PIN_DIR('B',EN,1);
	DIO_SET_PIN_DIR('B',RW,1);
	DIO_SET_PIN_DIR('B',RS,1);
	DIO_WRITE_PIN('B',RW,0);
	LCD_SEND_CMD(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_SEND_CMD(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_SEND_CMD(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_SEND_CMD(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#elif defined FOUR_BIT_MODE
	DIO_SET_PIN_DIR('D',4,1);
	DIO_SET_PIN_DIR('D',5,1);
	DIO_SET_PIN_DIR('D',6,1);
	DIO_SET_PIN_DIR('D',7,1);
	DIO_SET_PIN_DIR('B',EN,1);
	DIO_SET_PIN_DIR('B',RW,1);
	DIO_SET_PIN_DIR('B',RS,1);
	DIO_WRITE_PIN('B',RW,0);
	LCD_SEND_CMD(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_SEND_CMD(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_SEND_CMD(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_SEND_CMD(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_SEND_CMD(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}
void enable()
{
	DIO_WRITE_PIN('B',EN,1);
	_delay_ms(2);
	DIO_WRITE_PIN('B',EN,0);
	_delay_ms(2);
	
}
void LCD_SEND_CHAR(char data)
{
	#if defined EIGHT_BIT_MODE
	DIO_WRITE_PORT('D',data);
	DIO_WRITE_PIN('B',RS,1);
	enable();
	#elif defined FOUR_BIT_MODE
	DIO_WRITE_HIGH_NIBBLE('D',data>>4);
	DIO_WRITE_PIN('B',RS,1);
	enable();
	DIO_WRITE_HIGH_NIBBLE('D',data);
	enable();
	#endif
	_delay_ms(1);
}
void LCD_SEND_CMD(char cmd)
{
	#if defined EIGHT_BIT_MODE
	DIO_WRITE_PORT('D',cmd);
	DIO_WRITE_PIN('B',RS,0);
	enable();
	#elif defined FOUR_BIT_MODE
	
	DIO_WRITE_HIGH_NIBBLE('D',cmd>>4);
	DIO_WRITE_PIN('B',RS,0);
	enable();
	DIO_WRITE_HIGH_NIBBLE('D',cmd);
	DIO_WRITE_PIN('B',RS,0);
	enable();
	#endif
	_delay_ms(1);
	
	
}
void LCD_CLEAR_SCREEN()
{
	LCD_SEND_CMD(CLR_SCREEN);
}
void LCD_MOVE_CURSOR(char row,char column)
{
	char data;
	if(row>2||row<0||column>16||column<0)
	{
		data=SET_ADDRESS_1;
	}
	else if (row==1)
	{
		data= SET_ADDRESS_1+column-1;
	}
	else if(row==2)
	{
		data=SET_ADDRESS_2+column-1;
	}
	LCD_SEND_CMD(data);
	_delay_ms(1);
}
void LCD_SEND_STRING(char*ptr)
{
	while(*ptr!='\0')
	{
		LCD_SEND_CHAR(*ptr);
		ptr++;
	}
}