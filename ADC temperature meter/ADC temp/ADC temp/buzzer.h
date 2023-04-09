/*
 * IncFile1.h
 *
 * Created: 10/6/2021 12:07:56 AM
 *  Author: lenovo
 */ 


#ifndef buzzer_H_
#define buzzer_H_


void buzzer_init(char port, char pin);
void buzzer_on(char port,char pin);
void buzzer_off(char port,char pin);

void buzzer_toggle(char port,char pin);
char buzzer_read_status(char port,char pin);


#endif /* INCFILE1_H_ */