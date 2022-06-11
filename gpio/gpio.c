
#include <avr/io.h>

#include "gpio.h"

void IO_SetDir(tPort port , unsigned char pin , tDirection dir)
{
    switch(port)
    {
        case PORT_A:
        if(dir == GPIO_OUT)
            DDRA |= (1<<pin);
        else 
            DDRA &= ~(1<<pin); 
        break;
        case PORT_B:
        if(dir == GPIO_OUT)
            DDRB |= (1<<pin);
        else 
            DDRB &= ~(1<<pin); 
        break;
        case PORT_C:
         if(dir == GPIO_OUT)
            DDRC |= (1<<pin);
        else 
            DDRC &= ~(1<<pin); 
        break;
        case PORT_D:
         if(dir == GPIO_OUT)
            DDRD |= (1<<pin);
        else 
            DDRD &= ~(1<<pin); 
        break;
    }
}

void IO_SetVal(tPort port , unsigned char pin , unsigned char val)
{
    switch(port)
    {
        case PORT_A:
        if(val == 1)
            PORTA |= (1<<pin);
        else 
            PORTA &= ~(1<<pin); 
        break;
        case PORT_B:
         if(val == 1)
            PORTB |= (1<<pin);
        else 
            PORTB &= ~(1<<pin); 
        break;
        case PORT_C:
         if(val == 1)
            PORTC |= (1<<pin);
        else 
            PORTC &= ~(1<<pin); 
        break;
        case PORT_D:
         if(val == 1)
            PORTD |= (1<<pin);
        else 
            PORTD &= ~(1<<pin); 
        break;
    }
}
unsigned char IO_ReadVal(tPort port , unsigned char pin)
{
    unsigned char res;
    switch(port)
    {
        case PORT_A:
        res = PINA & (1<<pin);
        break;
        case PORT_B:
        res = PINB & (1<<pin);
        break;
        case PORT_C:
        res = PINC & (1<<pin);
        break;
        case PORT_D:
        res = PIND & (1<<pin);
        break;
    }
}