/*
 * EEPROM1.c
 *
 * Created: 10/17/2021 7:09:35 PM
 *  Author: lenovo
 */ 
#include "EEPROM.h"
int main (void)
{
	EEPROM_WRITE(0x0063,0x52);
	while(1)
	{
		
	}
}