#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "MUSART_cfg.h"
#include "MUSART_prv.h"
#include "MUSART_int.h"

static void (*global_ptr)(void)=NULL_PTR;

void MUSART_voidInit(void)
{
	//baud rate 16MHZ HSI
	USART->BRR =(104<<4)|(3);
	//over sample by 16
	USART->CR1.OVER8 =0;
	//word length 8
	USART->CR1.M =0;
	//parity disable
	USART->CR1.PCE =0;
	//one stop bits
	USART->CR2 &=~(1<<12);
	USART->CR2 &=~(1<<13);
	//enable transmit & receive
	USART->CR1.TE =1;
	USART->CR1.RE =1;
	//receive interrupt enable
	USART->CR1.RXNEIE=1;


}
void MUSART_Transmitt(u8 Copy_u8Data)
{

	USART->DR =Copy_u8Data;
	while(GET_BIT(USART->SR,6)==0);
}
u8 MUSART_Recive(void)
{
	if(GET_BIT(USART->SR,5)==1){
		return (u8)USART->DR;
		}
		else{
return 0;
		}
}
void MUSART_voidEnable(void)
{
	USART->CR1.UE=1;
}
void MUSART_voidDisable(void)
{
	USART->CR1.UE=0;
}
void MUSART_voidCallBack(void(*ptr)(void))
{
	if(ptr !=NULL_PTR)
	{
		global_ptr=ptr;
	}
	else
	{
		//do nothing
	}
}

void USART1_IRQHandler(void){
	if(global_ptr !=NULL_PTR)
	{
		global_ptr();
	}
	else
	{
		//do nothing
	}
}





void MUSART_voidTransmit(u8 * arr){
	u8 i = 0 ;
		while(arr[i] != '\0')
		{
			USART->DR = arr[i];
			while ((GET_BIT(USART->SR , 6)) == 0);
			i++;
		}
}
u8   MUSART_u8ReceiveWIFI(void){
	u16 timeout = 0 ;
		u8 Local_ReceivedData=0;
		while(GET_BIT(USART->SR,5)==0)
		{
			timeout++;
			if(timeout==10000)
			{
				Local_ReceivedData=255;
				break;
			}
		}
		if(Local_ReceivedData==0)
		{
			Local_ReceivedData= USART->DR;
		}
		return(Local_ReceivedData);
}


u8 MUSART_ReciveString(u8 * Receiving_Location)
{
	u8 status;

	if ((GET_BIT(USART->SR,5)==1))
	{
		status=1;
		*Receiving_Location = USART->DR;

	}
	else
	{

		status = 0;
	}
	return status ;

}
















