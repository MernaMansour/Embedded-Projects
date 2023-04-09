/*
 * DIO.c
 *
 * Created: 10/3/2021 2:57:34 PM
 *  Author: lenovo
 */ 


#include <avr/io.h>
#include "macro.h"


void DIO_SET_PIN_DIR(char port, char pin, char dir)
{
	switch(port)
	{
		case'A':
		case'a':
		if(dir==1)
		{
			SET_BIT(DDRA,pin);

        }
		else
		{
			CLR_BIT(DDRA,pin);
		}
		break;
		case'B':
		case'b':
		if(dir==1)
		{
			SET_BIT(DDRB,pin);

		}
		else
		{
			CLR_BIT(DDRB,pin);
		}
		break;	
		case'C':
		case'c':
		if(dir==1)
		{
			SET_BIT(DDRC,pin);

		}
		else
		{
			CLR_BIT(DDRC,pin);
		}
		break;
		case'D':
		case'd':
		if(dir==1)
		{
			SET_BIT(DDRD,pin);

		}
		else
		{
			CLR_BIT(DDRD,pin);
		}
		break;
	}
}
void DIO_WRITE_PIN(char port,char pin, char val)
{
	switch(port)
	{
		case'A':
		case'a':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;	
			case'B':
			case'b':
			if(val==1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;	
			case'C':
			case'c':
			if(val==1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;	
				case'D':
				case'd':
				if(val==1)
				{
					SET_BIT(PORTD,pin);
				}
				else
				{
					CLR_BIT(PORTD,pin);
				}
				break;
	}
}					
void DIO_TOGGLE_PIN(char port,char pin)
{
	switch(port)
	{
		case'A':
		case'a':
		TOG_BIT(PORTA,pin);
		break;
		case'B':
		case'b':
		TOG_BIT(PORTB,pin);
		break;
		case'C':
		case'c':
		TOG_BIT(PORTC,pin);
		break;
		case'D':
		case'd':
		TOG_BIT(PORTD,pin);
		break;
	}
}
char DIO_READ_PIN(char port,char pin)
{
	unsigned char value;
	switch(port)
	{
	case'A':
	case'a':
	value=READ_BIT(PINA,pin);
	break;
	case'B':
	case'b':
	value=READ_BIT(PINB,pin);
	break;
	case'C':
	case'c':
	value=READ_BIT(PINC,pin);
	break;
	case'D':
	case'd':
	value=READ_BIT(PIND,pin);
	break;
	}	
	return value;
}	
void DIO_SET_PORT_DIR(char port,char dir)
{
	switch(port)
	{
	case'A':
	case'a':
	DDRA=dir;
	break;
	case'B':
	case'b':
	DDRB=dir;
	break;
	case'C':
	case'c':
	DDRC=dir;
	break;
	case'D':
	case'd':
	DDRD=dir;
	break;
	}	
}
void DIO_WRITE_PORT(char port, char val)
{
	switch(port)
	{
		case'A':
		case'a':
		PORTA=val;
		break;
		case'B':
		case'b':
		PORTB=val;
		break;
		case'C':
		case'c':
		PORTC=val;
		break;
		case'D':
		case'd':
		PORTD=val;
		break;
	}
}
char DIO_READ_PORT(char port)
{
	unsigned char value;
	switch(port)
	{
		case'A':
		case'a':
		value=PINA;
		break;
		case'B':
		case'b':
		value=PINB;
		break;
		case'C':
		case'c':
		value=PINC;
		break;
		case'D':
		case'd':
		value=PIND;
		break;
	}
	return value;
}
void TOGGLE_PORT(char port)
{
	switch(port)
	{
		case'A':
		case'a':
		PORTA =~PORTA;
		break;
		case'B':
		case'b':
		PORTB =~PORTB;
		break;
		case'C':
		case'c':
		PORTC =~PORTC;
		break;
		case'D':
		case'd':
		PORTD =~PORTD;
		break;
	}		
}
void DIO_ENABLE_PULLUP(char port,char pin, char enable)
{
	switch(port)
	{
		case'A':
		case'a':
		if(enable==1)
		SET_BIT(PORTA,pin);
		else
		CLR_BIT(PORTA,pin);
		break;
		case'B':
		case'b':
		if(enable==1)
		SET_BIT(PORTB,pin);
		else
		CLR_BIT(PORTB,pin);
		break;
		case'C':
		case'c':
		if(enable==1)
		SET_BIT(PORTC,pin);
		else
		CLR_BIT(PORTC,pin);
		break;
		case'D':
		case'd':
		if(enable==1)
		SET_BIT(PORTD,pin);
		else
		CLR_BIT(PORTD,pin);
		break;
	}
}	
	void DIO_WRITE_LOW_NIBBLE(char port, char value)
	{
		value &=0x0f;
		 switch(port)
		 {
			 case'A':
			 case'a':
			 PORTA &=0xf0;
			 PORTA|=value;
			 break;
			 case'B':
			  case'b':
			  PORTB &=0xf0;
			  PORTB|=value;
			  break;
			  case'C':
			  case'c':
			  PORTC &=0xf0;
			  PORTC|=value;
			  break;
			   case'D':
			   case'd':
			   PORTD &=0xf0;
			   PORTD|=value;
			   break;
		/* DIO_WRITE_PIN(port,0,DIO_READ_PIN(value,0));
	  DIO_WRITE_PIN(port,1,DIO_READ_PIN(value,1));
	   DIO_WRITE_PIN(port,2,DIO_READ_PIN(value,2));
	    DIO_WRITE_PIN(port,3,DIO_READ_PIN(value,3));*/
			 
		 }
	}
	void DIO_WRITE_HIGH_NIBBLE(char port, char value)
	{
		value<<=4;
		switch(port)
		{
			case'A':
			case'a':
			PORTA &=0x0f;
			PORTA|=value;
			break;
			case'B':
			case'b':
			PORTB &=0x0f;
			PORTB|=value;
			break;
			case'C':
			case'c':
			PORTC &=0x0f;
			PORTC|=value;
			break;
			case'D':
			case'd':
			PORTD &=0x0f;
			PORTD|=value;
			break;
			/* DIO_WRITE_PIN(port,4,DIO_READ_PIN(value,4));
	  DIO_WRITE_PIN(port,5,DIO_READ_PIN(value,5));
	   DIO_WRITE_PIN(port,6,DIO_READ_PIN(value,6));
	    DIO_WRITE_PIN(port,7,DIO_READ_PIN(value,7));*/
	}
	}
		
