/*
 * button2.c
 *
 * Created: 10/6/2021 12:56:19 AM
 *  Author: lenovo
 */ 
void button_init(char port,char pin)
{
	DIO_SET_PIN_DIR(port,pin,0);
}
char button_read(char port, char pin)
{
	return DIO_READ_PIN(port,pin);
}