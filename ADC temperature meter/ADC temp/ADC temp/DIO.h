/*
 * IncFile1.h
 *
 * Created: 10/3/2021 2:58:05 PM
 *  Author: lenovo
 */ 



#ifndef DIO_H_
#define DIO_H_

void DIO_SET_PIN_DIR(char port, char pin, char dir);
void DIO_WRITE_PIN(char port,char pin, char val);
void DIO_TOGGLE_PIN(char port,char pin);
char DIO_READ_PIN(char port,char pin);
void DIO_SET_PORT_DIR(char pin,char dir);
void DIO_WRITE_PORT(char port, char val);
char DIO_READ_PORT(char port);
void TOGGLE_PORT(char port);
void DIO_ENABLE_PULLUP(char port,char pin, char enable);
void DIO_WRITE_LOW_NIBBLE(char port, char value);
void DIO_WRITE_HIGH_NIBBLE(char port, char value);




#endif /* INCFILE1_H_ */