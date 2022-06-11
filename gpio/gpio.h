#ifndef GPIO_H
#define GPIO_H

typedef enum
{
    GPIO_OUT = 1,
    GPIO_IN = 0
}tDirection;

typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D
}tPort;

void IO_SetDir(tPort port , unsigned char pin , tDirection dir);

void IO_SetVal(tPort port , unsigned char pin , unsigned char val);

unsigned char IO_ReadVal(tPort port , unsigned char pin);

#endif /* GPIO_H */