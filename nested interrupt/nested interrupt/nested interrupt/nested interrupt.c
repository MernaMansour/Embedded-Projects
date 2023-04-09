/*
 * nested_interrupt.c
 *
 * Created: 11/12/2021 10:31:24 PM
 *  Author: lenovo
 */ 

#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "LEDD.h"
#include "macro.h"
#include "button.h"

int main(void)
{ 
	led_init('A',0);
	led_init('A',1);
	led_init('A',2);
	sei();
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT2);
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUSR,ISC2);
	
    while(1)
    {
       led_off('A',0);
	   led_off('A',1);
	   led_off('A',2);
    }
}
ISR(INT0_vect)
{
	led_on('A',0);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	led_on('A',1);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	led_on('A',2);
	_delay_ms(1000);
}