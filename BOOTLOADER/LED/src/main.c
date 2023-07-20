#include "STD_Types.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"



void main(void)
{
	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,AHB1_GPIOA);  // Enable GPIO
	MGPIO_SetMode(PORTA,PIN0,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW);


	while (1)
	{
		MGPIO_SetPinValue(PORTA,PIN0,STD_HIGH);
	}
}


