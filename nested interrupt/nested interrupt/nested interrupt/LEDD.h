/*
 * IncFile1.h
 *
 * Created: 10/5/2021 9:25:57 PM
 *  Author: lenovo
 */ 


#ifndef LEDD_H_
#define LEDD_H_
void led_init(char port, char pin);
void led_on(char port,char pin);
void led_off(char port,char pin);

void led_toggle(char port,char pin);
char led_read_status(char port,char pin);





#endif /* INCFILE1_H_ */