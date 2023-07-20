#ifndef PIR_INTERFACE_H
#define PIR_INTERFACE_H
#include "LIB/STD_Types.h"
#include "PIR_Config.h"
#include "PIR_Private.h"


// data of a pir sensor 
typedef struct PIR
{
    u8 PORT_NUM;
    u8 PIN_NUM;
    /* data */
}PIR_T;

/* we need in PIR only the port and pin to intialize it 
the output of PIR is  digital  */
u8 PIR_u8Init (PIR_T * PIR_SENSOR);

u8 PIR_u8Reading(PIR_T * PIR_SENSOR);








#endif