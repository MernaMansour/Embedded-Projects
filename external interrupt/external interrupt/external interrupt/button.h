/*
 * button.h
 *
 * Created: 10/6/2021 12:56:37 AM
 *  Author: lenovo
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO.h"
#include "LEDD.h"
void button_init(char port,char pin);
char button_read(char port, char pin);



#endif /* BUTTON_H_ */