#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"
#include "Ldr_Interface.h"
#include "DIO/DIO_interface.h"


u8 LDR_voidInit (const LDR_T * LDR1 ){
    u8 Local_ERRORSTATE = OK; 
    if(LDR1->PORT_Number <4 && LDR1->PIN_Number <= 7){

DIO_voidSetPinDirection(LDR1->PORT_Number,LDR1->PIN_Number,INPUT);
    }
    else 
    Local_ERRORSTATE =NOK;

return Local_ERRORSTATE ;
}