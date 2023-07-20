#include "STD_Types.h"
#include "BIT_MATH.h"
#include "RCC_int.h"
#include "STK_int.h"
#include "MGPIO_INT.h"
#include "R2R_int.h"

void R2R_Init (void)
{
	MRCC_u8Init();
	MRCC_VIDEnablePeripheral(RCC_AHB1,AHB1_GPIOA);


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


}

void R2R_SendData(const u8 * arr,u32 ArrayIndex)
{
	u32 Local_u8Counter =0 ;
	for (Local_u8Counter=0;Local_u8Counter<ArrayIndex;Local_u8Counter++)
	{


		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN0,GET_BIT(arr[Local_u8Counter],0));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN1,GET_BIT(arr[Local_u8Counter],1));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN2,GET_BIT(arr[Local_u8Counter],2));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN3,GET_BIT(arr[Local_u8Counter],3));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN4,GET_BIT(arr[Local_u8Counter],4));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN5,GET_BIT(arr[Local_u8Counter],5));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN6,GET_BIT(arr[Local_u8Counter],6));
		MGPIO_vidSetPinValue(GPIO_PORTA,GPIO_PIN7,GET_BIT(arr[Local_u8Counter],7));
		MSTK_voidDelayUsec(125);


	}


}


