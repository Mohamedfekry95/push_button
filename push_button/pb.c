#include "pb.h"
#include "push_button/gpio/gpio.h"

#define NO_OF_BUTTONS 4
#define NO_OF_SAMPLES 2

#define pressed 0
#define released 1


typedef struct
{
    unsigned char samples[NO_OF_SAMPLES];
    tpb_state pb_state;
}tpb_info;


static tpb_info pb_info[NO_OF_BUTTONS];

void PushButton_init(tpb_type pb , tpb_state inital_state)
{
    /* define pin as output */
    switch(pb)
    {
        case pb_inc:
        IO_SetDir(PORT_A , pb_inc , GPIO_IN);
        case pb_dec:
        IO_SetDir(PORT_A , pb_dec , GPIO_IN);
        case pb_set:
        IO_SetDir(PORT_A , pb_set , GPIO_IN);
        case unused:
        IO_SetDir(PORT_A , unused , GPIO_IN);
    }

    /* initialize buton with inital state */
    pb_info[pb].pb_state = inital_state;

    /* initialize button with inital sample */
    switch(inital_state)
    {
        case pb_pressed:
        case pb_prepressed:
        pb_info[pb].samples[0] = pressed;
        pb_info[pb].samples[1] = pressed;
        break;
        case pb_released:
        case pb_prereleased:
        pb_info[pb].samples[0] = released;
        pb_info[pb].samples[1] = released;
        break;
    }
}

void PB_Update(void)
{
    tpb_type current_button;
    for(current_button = pb_inc ; current_button < unused ; current_button++)
    {
        /* update samples */
        pb_info[current_button].samples[0] = pb_info[current_button].samples[1];
        switch(current_button)
        {
            case pb_inc :
            pb_info[current_button].samples[1] = IO_ReadVal(PORT_A , pb_inc);
            break;
            case pb_dec :
            pb_info[current_button].samples[1] = IO_ReadVal(PORT_A , pb_dec;
            break;
            case pb_set :
            pb_info[current_button].samples[1] = IO_ReadVal(PORT_A , pb_set);
            break;
            case unused : 
            pb_info[current_button].samples[1] = IO_ReadVal(PORT_A , unused);
            break;
        }      
        /*  update state */ 
        switch(pb_info[current_button].state)
        {
            case pb_released :
            if((pb_info[current_button].samples[0] == pressed) && (pb_info[current_button].samples[1] == pressed))
                pb_info[current_button].state == pb_prepressed;
            break;
            case pb__prepressed :
            if(pb_info[current_button].samples[0] == pressed)
                pb_info[current_button].state == pb_pressed;
            break;
            case pb_pressed : 
            if((pb_info[current_button].samples[0] == released) && (pb_info[current_button].samples[1] == released))
                pb_info[current_button].state == pb_prereleased;
            break;
            case pb_prereleased :
            if(pb_info[current_button].samples[0] == released)
                pb_info[current_button].state == pb_released;
            break;
        }
    }
}

tpb_state PB_GetState(tpb_type pb)
{
    tpb_state ret;
    ret = pb_info[pb].state;
    return ret; 
}