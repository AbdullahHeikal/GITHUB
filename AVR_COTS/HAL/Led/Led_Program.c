#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"
#include "Led_Interface.h"
#include "DIO_interface.h"
/* *****************************************************************************************************
F_D: function return void and takes a pointer to a struct of type LED_T that have all details needed for  a led 
F_W: this function is tended to init the led 
 *****************************************************************************************************
 */
void LED_voidInit (const LED_T * LED){
    // LED INIT IT TAKES THE PORT AND PIN TO MAKE IT OUTPUT 
    DIO_voidSetPinDirection(LED->PORT_Number,LED->PIN_Number,OUTPUT);
}
/****************************************************************************************************** 
F_D: function return void and takes a pointer to a struct of type LED_T that have all details needed for  a led 
F_W: this function is tended to turn on  the led 
 *****************************************************************************************************
 */
void LED_voidTurnOn (const LED_T * LED){
// WILL PUT THE VALUE OF LED_ON TO THE PIN 
DIO_voidSetPinValue(LED->PORT_Number,LED->PIN_Number,LED_ON);
}
/* *****************************************************************************************************
F_D: function return void and takes a pointer to a struct of type LED_T that have all details needed for  a led 
F_W: this function is tended to turn off the led 
 *****************************************************************************************************
 */
void LED_voidTurnOff (const LED_T * LED){
// WILL PUT THE VALUE OF LED_OFF TO THE PIN 
DIO_voidSetPinValue(LED->PORT_Number,LED->PIN_Number,LED_OFF);
}

/* *****************************************************************************************************
F_D: function return void and takes a pointer to a struct of type LED_T that have all details needed for  a led 
F_W: this function is tended to toggle the led 
 *****************************************************************************************************
 */
void LED_voidTurnToggle (const LED_T * LED){
// WILL TOGGLE THE VALUE OF PIN 
if (LED->LED_Status == LED_ON){
    DIO_voidSetPinValue(LED->PORT_Number,LED->PIN_Number,LED_OFF);
}
else{
DIO_voidSetPinValue(LED->PORT_Number,LED->PIN_Number,LED_ON);
}


}

