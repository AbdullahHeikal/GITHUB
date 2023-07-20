#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "HSTP_int.h"
#include "MSYSTICK_int.h"


void HSTP_voidInit(void){
	MGPIO_SetMode(PORTA,PIN0,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);

	MGPIO_SetMode(PORTA,PIN1,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);

	MGPIO_SetMode(PORTA,PIN2,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);


}
void HSTP_voidShiftData(u16 Copy_u16Frame){
	for (s8 i=7;i>=0;i--){

		MGPIO_SetPinValue(PORTA,PIN0,!GET_BIT(Copy_u16Frame,i));

		MGPIO_SetPinValue(PORTA,PIN1,STD_HIGH);
		MSYSYTICK_voidDelayMs(1);
		MGPIO_SetPinValue(PORTA,PIN1,STD_LOW);
		MSYSYTICK_voidDelayMs(1);
	}


}

	void HSTP_voidSendData(void)
	{
		MGPIO_SetPinValue(PORTA,PIN2,STD_HIGH);
		MSYSYTICK_voidDelayMs(1);
		MGPIO_SetPinValue(PORTA,PIN2,STD_LOW);
		MSYSYTICK_voidDelayMs(1);

	}









