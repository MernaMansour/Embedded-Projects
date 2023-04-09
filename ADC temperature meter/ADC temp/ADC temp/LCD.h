/*
 * LCD.h
 *
 * Created: 10/24/2021 3:53:12 PM
 *  Author: lenovo
 */ 

#define FOUR_BIT_MODE
#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0c
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined FOUR_BIT_MODE
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined EIGHT_BIT_MODE
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
#define SET_ADDRESS_1 0x80
#define SET_ADDRESS_2 0xc0
#define PORT_NAME D
void LCD_INIT(void);
void enable();
void LCD_SEND_CHAR(char data);
void LCD_SEND_CMD(char cmd);
void LCD_CLEAR_SCREEN();
void LCD_MOVE_CURSOR(char row,char column);
void LCD_SEND_STRING(char*ptr);
#endif /* LCD_H_ */

