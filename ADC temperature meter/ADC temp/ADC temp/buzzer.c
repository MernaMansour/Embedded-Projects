/*
 * buzzer.c
 *
 * Created: 10/6/2021 12:07:40 AM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "buzzer.h"
void buzzer_init(char port, char pin)
{
	DIO_SET_PIN_DIR(port,pin,1);
}
void buzzer_on(char port,char pin)
{
	DIO_WRITE_PIN(port,pin,1);
}
void buzzer_off(char port,char pin)
{
	DIO_WRITE_PIN(port,pin,0);
}
void buzzer_toggle(char port,char pin)
{
	DIO_TOGGLE_PIN(port,pin);
}
char buzzer_read_status(char port,char pin)
{
	return DIO_READ_PIN(port,pin);
}