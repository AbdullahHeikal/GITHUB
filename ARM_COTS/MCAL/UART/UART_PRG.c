/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : UART_Driver
File : PROGRAM File
Version :1.0
Date :7/6/2023
********************************************************************************************************
********************************************************************************************************
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "UART_INT.h"
#include "UART_CFG.h"
#include "UART_PRV.h"


/*************************************** USART_vInit  *************************************************/
/* 
to set all UART  General options nedded 
 */

/* 
 OVER_8SAMPLING   1 
OVER_16SAMPLING   0 
*/
void USART_vInit(void)
{
    UART->USART_BRR &= ~(BaudRateMask);  // reset baudrate value 
    UART->USART_BRR |= (Brr_Mantissa<<4)|(Brr_Fraction);   // set baud rate 
    UART->USART_CR1 &= ~((~OVER_16SAMPLING)<<15);  //choose oversampling by 16 
    UART->USART_CR1 &= ~(1<<12);   // 8bit word lenght 




}
/*********************************************************************************************************/
/*********************************************************************************************************/

/*************************************** USART_vTransmitRecieve  *************************************************/
/* 
to set all UART options for full dublex 
 */

u8 USART_vTransmitRecieve(u8 Copy_u8Data)
{
    UART->USART_CR1 |= (1<<3);  // transmit enable
    UART->USART_CR1 |= (1<<2);  // receive enable 
    while ( ((UART->USART_SR >>7)&1)!=1);
    UART->USART_DR =Copy_u8Data ; 
    while(((UART->USART_SR >>7)&1)!=1)
    return (UART->USART_DR);

}
/*********************************************************************************************************/
/*********************************************************************************************************/
/*************************************** USART_vTransmit  *************************************************/
/* 
to set all UART options for Half dublex  transmit
 */
void USART_vTransmit (u8 Copy_u8Data)
{

}
/*********************************************************************************************************/
/*********************************************************************************************************/
/*************************************** USART_u8Recieve  *************************************************/
/* 
to set all UART options for Half dublex  receive
 */
u8 USART_u8Recieve (void)
{

}
/*********************************************************************************************************/
/*********************************************************************************************************/

/*************************************** USART_ENABLE  *************************************************/

void USART_ENABLE (void)
{
UART->USART_CR1 |= (Enable<<13);
}

/*********************************************************************************************************/
/*********************************************************************************************************/


/*************************************** USART_Disable  *************************************************/

void USART_Disable (void)
{

UART->USART_CR1 &= ~((~Enable)<<13);

}
/*********************************************************************************************************/
/*********************************************************************************************************/


