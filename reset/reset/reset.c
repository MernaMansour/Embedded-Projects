/*
 * reset.c
 *
 * Created: 11/12/2021 8:54:54 PM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include "LEDD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{ 
	led_init('A',0);
	led_init('A',1);
	led_init('A',2);
	led_on('A',0);
	_delay_ms(500);
	led_off('A',0);
	led_on('A',1);
	_delay_ms(500);
	led_off('A',1);
	led_on('A',2);
	_delay_ms(500);
	led_off('A',2);
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}