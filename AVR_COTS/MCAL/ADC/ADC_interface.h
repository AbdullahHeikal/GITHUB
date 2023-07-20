/*
 * ADC_interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: abdullah heikal
 *      FILE : ADC_interface
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*****************************************************************************************************************
 * *************************************start APIS Prototypes **********************************************************/
#include "ADC_config.h"
#include "ADC_private.h"
void ADC_VoidInit(void);
u8 ADC_u8StartConversionSynchronous (u8 Copy_u8ADC_Channels);
u16 ADC_u16StartConversionSynchronous (u8 Copy_u8ADC_Channels);
u8 ADC_u8StartConversionAsynchronous(u8 Copy_u8ADC_Channels ,void (*voidnotification_function)(void));
u16 ADC_Mapping(u16 Range1_max,u16 Range1_min,u16 Range2_max,u16 Range2_min,u16 Range1_reading);


/*****************************************************************************************************************
 * *************************************End APIS Prototypes **********************************************************/

#endif /* ADC_INTERFACE_H_ */
