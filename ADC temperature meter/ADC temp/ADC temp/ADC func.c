/*
 * ADC_func.c
 *
 * Created: 11/27/2021 2:44:15 PM
 *  Author: lenovo
 */ 
#include <avr/io.h>
#include "macro.h"

void ADC_init(void)
{
	SET_BIT(ADMUX,REFS0); //reference voltage ---AVCC=5v
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);//enable adc
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);// division factor 64 --> frequency 125KHZ
	
}
unsigned short ADC_read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)==0);
	//while(IS_BIT_CLR(ADCSRA,ADIF));// if bit ADIF=0 ---> condition is true ...> return 1 till it becomes 1 it exist from loop
	SET_BIT(ADCSRA,ADIF);//clear bit
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val; 
}