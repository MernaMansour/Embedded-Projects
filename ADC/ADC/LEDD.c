/*
 * LEDD.c
 *
 * Created: 10/5/2021 9:24:41 PM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "LEDD.h"
void led_init(char port, char pin)
{
	DIO_SET_PIN_DIR(port,pin,1);
}
void led_on(char port,char pin)
{
	DIO_WRITE_PIN(port,pin,1);
}
void led_off(char port,char pin)
{
	DIO_WRITE_PIN(port,pin,0);
}
void led_toggle(char port,char pin)
{
	DIO_TOGGLE_PIN(port,pin);
}
char led_read_status(char port,char pin)
{
	return DIO_READ_PIN(port,pin);
}