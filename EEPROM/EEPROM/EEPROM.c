/*
 * EEPROM.c
 *
 * Created: 10/17/2021 6:20:05 PM
 *  Author: lenovo
 */ 
#include <avr/io.h>
#include "macro.h"
void EEPROM_WRITE(unsigned short address,unsigned char data )
{
	EEARL=(char)address; 1010110101
	EEARH=(char)(address>>8);//el castig mmkn ashelo
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}
unsigned char EEPROM_READ(unsigned short address)
{
	EEARL= (char)address;
	EEARH=(char)(address>>8);
	SET_BIT(EECR,EERE);
	return EEDR;
}