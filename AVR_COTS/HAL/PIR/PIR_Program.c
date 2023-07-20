#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"
#include "PIR_Interface.h"
#include "DIO/DIO_interface.h"



/*****************************************************************************************************
function discribtion : PIR Initialization 
   function job      : to set pin which connected to PIR to be input 
   ***************************************************************************************************/
u8 PIR_u8Init (PIR_T * PIR_SENSOR){
    u8 LocalErrorState = OK;
    if (PIR_SENSOR->PORT_NUM <4 &&  PIR_SENSOR->PIN_NUM <=7 ){
        DIO_voidSetPinDirection(PIR_SENSOR->PORT_NUM,PIR_SENSOR->PIN_NUM,INPUT);
    }
    else {
        LocalErrorState = NOK;
    }
return LocalErrorState;

}
/******************************************************************************************************
   function discribtion : PIR Initialization 
   function job         : get output of PIR sensor  
   *****************************************************************************************************
   */ 

u8 PIR_u8Reading(PIR_T * PIR_SENSOR){
    return DIO_u8GetPinValue(PIR_SENSOR->PORT_NUM,PIR_SENSOR->PIN_NUM);
}
