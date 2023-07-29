#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "UART2_int.h"
#include "MFMI_int.h"
#include "HexParser_int.h"
u8 Record_Recieved [60];
u8 Global_RX_Counter = 0 ;
void callbackfunction(void) ;

void (*APP)(void) = (void (*)(void))0x08004004;





/* call back function*/







void main(void)
{
	MRCC_init();   // INIT RCC
	MRCC_Enable_peripheral(RCC_AHBLP,AHBLP1_FMI);  // Enable FMI
	MRCC_Enable_peripheral(RCC_AHB1,AHB1_GPIOA);  // Enable GPIO
	MRCC_Enable_peripheral(RCC_APB2,APB2_USART1); // ENABLE UART
	MGPIO_SetMode(PORTA,PIN9,ALT_FUNC);  // SET UART PINS
	MGPIO_SetMode(PORTA,PIN10,ALT_FUNC);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN9,7);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN10,7);
	UART_voidInit();
	UART_voidEnable();
	u8 Local_u8UARTStatus = 0;
	MGPIO_SetMode(PORTA,PIN1,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW);
	u8 Timeout =1 ;
	u8 data = 0;
while(1)
{

	u8 counter = 0;
	data = UART_u8RecieveData();
	if(data == '*')
	{
		Record_Recieved[counter] = data;
	}

	counter++;


				if(data =='*')
				{
					UART_voidSendData('K');  // indication for ending the Record


					HexParser_vParseData(Record_Recieved);  // start to convert data received


					counter = 0;

				}

				if (data =='$')
				{
					//MGPIO_SetPinValue(PORTA,PIN1,STD_HIGH);
					callbackfunction(); // call Application

				}








}

}




void callbackfunction(void)
{
#define SCB_VTOR (*((volatile u32*)0xE00ED00+0x08))
	SCB_VTOR = 0x8004000 ;    // Shift APP vector table
	APP();/*Call App After end of operation*/
}
