/*
 * ADC_interface.h
 *
 *  Created on: may 15, 2023
 *      Author: abdullah heikal
 *      FILE : LED_INTERFACE
 */

#ifndef  LED_INTERFACE_H
#define LED_INTERFACE_H

#include "LIB/STD_Types.h"
#include "Led_Private.h"
#include "Led_Config.h" 
#define LED_OFF 0 
#define LED_ON 1 

typedef struct LED
{
    u8 PORT_Number ; 
    u8 PIN_Number ; 
    u8 LED_Status ;
}LED_T;

void LED_voidInit (const LED_T * LED);
void LED_voidTurnOn (const LED_T * LED);
void LED_voidTurnOff (const LED_T * LED);
void LED_voidTurnToggle (const LED_T * LED);

















#endif