#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "STK_int.h"
#include "HLEDMATRIX_int.h"


void HLEDMATRIX_VoidInit(void){
	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN0,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN1,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN2,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN3,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN4,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN5,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN6,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTA,GPIO_PIN7,OPushPull,Medium_Speed);



	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN0,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN1,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN2,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN6,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN6,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN7,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN7,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN8,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN7,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN9,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN8,OPushPull,Medium_Speed);

	MGPIO_VidGPIOModeSelect(GPIO_PORTB,GPIO_PIN10,GPIO_OUTPUT);
	MGPIO_VidGPIOSetOutputPinMode(GPIO_PORTB,GPIO_PIN10,OPushPull,Medium_Speed);


}
void HLEDMATRIX_VoidDisableColumns(void){
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN0,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN1,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN2,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN3,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN4,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN5,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN6,Low);
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN7,Low);
}

void HLEDMATRIX_VoidSetRowValue(u8 Copy_u8RowValue){
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN0,!GET_BIT(Copy_u8RowValue,0));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN1,!GET_BIT(Copy_u8RowValue,1));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN2,!GET_BIT(Copy_u8RowValue,2));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN6,!GET_BIT(Copy_u8RowValue,3));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN7,!GET_BIT(Copy_u8RowValue,4));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN8,!GET_BIT(Copy_u8RowValue,5));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN9,!GET_BIT(Copy_u8RowValue,6));
	MGPIO_vidSetPinValue(GPIO_PORTB,GPIO_PIN10,!GET_BIT(Copy_u8RowValue,7));
}

void HLEDMATRIX_VoidDisplay(u8 *Copy_u8arr)
{
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN0,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[0]);
	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN1,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[1]);

	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN2,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[2]);

	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN3,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[3]);

	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN4,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[4]);

	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN5,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[5]);

	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN6,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[6]);

	MSTK_voidDelayMsec(5);

	HLEDMATRIX_VoidDisableColumns();
	MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN7,High);
	HLEDMATRIX_VoidSetRowValue(Copy_u8arr[7]);

	MSTK_voidDelayMsec(5);
}
