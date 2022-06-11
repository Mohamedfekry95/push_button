#ifndef PB_H
#define PB_H

typedef enum
{
    pb_inc;
    pb_dec;
    pb_set;
    unused;
}tpb_type;


typedef enum
{
    pb_prepressed;
    pb_pressed;
    pb_prereleased;
    pb_released;
} tpb_state;

void PushButton_init(tpb_type pb , tpb_state inital_state);

void PB_Update(void);

tpb_state PB_GetState(tpb_type pb);


#endif  /* PB_H */