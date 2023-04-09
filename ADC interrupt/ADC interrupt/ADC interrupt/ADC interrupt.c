/*
 * ADC_interrupt.c
 *
 * Created: 11/27/2021 3:52:40 PM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "LEDD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "macro.h"
int main(void)
{ 
	ADC_init();
	sei();
	SET_BIT(ADCSRA,ADIE);
	led_init('D',0);
	led_init('D',1);
    while(1)
    {
       SET_BIT(ADCSRA,ADSC);
	   _delay_ms(0.5);// freq-1/125000=8*10^-6 >>> 8*10^-6*13=1.04*10^-4 ...> time for ADC to stop conversion--> so use delay 
	   PORTD=0x02;
	   _delay_ms(1000);// on led 1 off led2 
     }
}
ISR(ADC_vect)
{
	PORTD=0x01;
	_delay_ms(1000);//on led 2 off led 1
}