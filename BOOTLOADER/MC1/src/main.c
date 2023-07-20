#include "STD_Types.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "UART2_int.h"
#include "MEXTI_int.h"
#include "MNVIC_int.h"
#include "MSYSTICK_int.h"
#include "RecordsArray.h"
u8 Local_u8Uartstatus = 0;
u16 String_Counter ;
u16 Local_RecordCounter=0  ;
u8 i;

void main(void)
{
	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,AHB1_GPIOA);  // Enable GPIO
	MRCC_Enable_peripheral(RCC_APB2,APB2_SYSCFG); //enable syscfg
	MRCC_Enable_peripheral(RCC_APB2,APB2_USART1);// ENABLE UART
	MGPIO_SetMode(PORTA,PIN0,INPUT);
	MGPIO_SetInputPin(PORTA,PIN0,INPUT_PullUP);
	MGPIO_SetMode(PORTA,PIN9,ALT_FUNC);  // SET UART PINS
	MGPIO_SetMode(PORTA,PIN10,ALT_FUNC);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN9,7);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN10,7);
	MGPIO_SetMode(PORTA,PIN1,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW);
	UART_voidInit();
	UART_voidEnable();
	u8 flag2 = 0;
	u8 TimeOut=1 ;

	for(String_Counter=0;String_Counter<108;String_Counter++)
		{
				for (Local_RecordCounter=0 ; arr[String_Counter][Local_RecordCounter] != '\0';Local_RecordCounter++)
				{
					if(arr[String_Counter][8] == '5')
					{
						flag2 = 1;
						UART_voidSendData('$');

					}
					else
					{
						MGPIO_SetPinValue(PORTA,PIN1,STD_HIGH);
						UART_voidSendData(arr[String_Counter][Local_RecordCounter]);
					}

				}

				while(Local_u8Uartstatus != 'K')
				{
					Local_u8Uartstatus=UART_u8RecieveData();
				}

				if(flag2 == 1)
				{
					break;
				}
		}


	while (1)
	{


	}
}

