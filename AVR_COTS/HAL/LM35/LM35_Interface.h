#ifndef LM35_INTERFACE_H
#define LM32_INTERFACE_H
#include "LIB/STD_Types.h"
#include "LM35_Config.h"
#include "LM35_Private.h"

typedef struct LM
{
    u8 PORT_NUM;
    u8 PIN_NUM ; 
    /* data */
}LM35_T;


u8 LM_voidInit (const LM35_T * LM_35);

u8 Tempratuer_u8LMReading (const LM35_T * LM_35,void (*IndicationForCompleteConv)(void));











#endif