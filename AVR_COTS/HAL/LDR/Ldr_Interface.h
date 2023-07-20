#ifndef  LDR_INTERFACE_H
#define LDR_INTERFACE_H
#include "LIB/STD_Types.h"
#include "Ldr_Config.h"
#include "Ldr_Private.h"
typedef struct LDR 
{
    u8 PORT_Number;
    u8 PIN_Number ; 

}LDR_T;

u8 LDR_voidInit(const LDR_T * LDR1);




















#endif