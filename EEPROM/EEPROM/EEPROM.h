/*
 * EEPROM.h
 *
 * Created: 10/17/2021 6:20:35 PM
 *  Author: lenovo
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_WRITE(unsigned short address,unsigned char data );// tkhzn el data ely b3tha fe el address ely enta b3tu ,short 3ashan ttkhzn fe 16 bit 
// data bttkhzn fe 8 bit
unsigned char EEPROM_READ(unsigned short address); 




#endif /* EEPROM_H_ */