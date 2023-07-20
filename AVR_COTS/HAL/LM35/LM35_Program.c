#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"
#include "LM35_Interface.h"
#include "DIO_interface.h"
#include "ADC/ADC_interface.h"
extern Copy_AsynchReading ; // extern the varaible where ADC Asynch reading is stored  
/* LM35 SENSOR 
we only need to init it then we take in this function the port and pin */
u8 LM_voidInit (const LM35_T * LM_35){
    u8 Local_ErrorState = OK;
    if (LM_35->PORT_NUM <4 && LM_35->PIN_NUM <=7){   // CHECK IF PORT OR PIN ARE EXCEED THE LIMIT 
        DIO_voidSetPinDirection(LM_35->PORT_NUM,LM_35->PIN_NUM,INPUT);
    }
    else{
        u8 Local_ErrorState = NOK;
    }
     return Local_ErrorState;
}
// Using ADC Module in MCAL layer to convert from ANLAOG TO DIGIAL TO KNOW TEMP 
u8 Tempratuer_u8LMReading (const LM35_T * LM_35,void (*IndicationForCompleteConv)(void)){
    u16 Reading ; 
    ADC_VoidInit();
    ADC_u8StartConversionAsynchronous(LM_35->PIN_NUM, (*IndicationForCompleteConv));
    Reading =((u16)(((u32)Copy_AsynchReading*5000UL)/256UL));
    return Reading ; 

}