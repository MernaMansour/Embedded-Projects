/*
 * ADC.c
 *
 * Created: 11/27/2021 2:42:51 PM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include "LEDD.h"
#include "ADC.h"
int main(void)
{ 
	ADC_init();
	char i;
	for(i=0;i<=7;i++)
	{led_init('D',i);}
    while(1)
    {
       PORTD=ADC_read();
    }
}