/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : GPIO_Driver
File : Program File
Version :1.0
Date :29/5/2023
 ********************************************************************************************************
 ********************************************************************************************************
 */
#include "STD_Types.h"
#include "MGPIO_INT.h"
#include "MGPIO_CFG.h"
#include "MGPIO_PRV.h"

void MGPIO_VidGPIOModeSelect(u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8GPIOMode){
	switch (Copy_u8GPIOPort){

	case GPIO_PORTA:
		GPIOA->GPIO_Moder  &=  ~(GPIO_PIN_Mask<<Copy_u8GPIOPIN *2);
		GPIOA->GPIO_Moder |=  ( Copy_u8GPIOMode << Copy_u8GPIOPIN *2 );
		break ;
	case GPIO_PORTB:
		GPIOB->GPIO_Moder  &=  ~(GPIO_PIN_Mask<<Copy_u8GPIOPIN *2);
		GPIOB->GPIO_Moder |=  ( Copy_u8GPIOMode << Copy_u8GPIOPIN *2 );

		break ;
	case GPIO_PORTC:
		GPIOC->GPIO_Moder  &=  ~(GPIO_PIN_Mask<<Copy_u8GPIOPIN *2);
		GPIOC->GPIO_Moder |=  ( Copy_u8GPIOMode << Copy_u8GPIOPIN *2 );

		break ;
	default :
		/*DO nothing*/
		break ;
	}
}

void MGPIO_VidGPIOSetOutputPinMode (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8OutputMode , u8 Copy_u8Speed)
{

	switch (Copy_u8GPIOPort){
	case GPIO_PORTA:
		GPIOA->GPIO_OTYPER  &= ~ (GPIO_OUTPUT_MASK << Copy_u8GPIOPIN);
		GPIOA->GPIO_OTYPER  |=  ( Copy_u8OutputMode << Copy_u8GPIOPIN);
		GPIOA->GPIO_OSPEEDR &= ~ (GPIO_SPEED_Mask << Copy_u8GPIOPIN);
		GPIOA->GPIO_OSPEEDR |=  ( Copy_u8Speed << Copy_u8GPIOPIN*2 );
		break ;
	case GPIO_PORTB:
		GPIOB->GPIO_OTYPER   &=  ~(GPIO_OUTPUT_MASK << Copy_u8GPIOPIN);
		GPIOB->GPIO_OTYPER   |=  ( Copy_u8OutputMode << Copy_u8GPIOPIN );
		GPIOB->GPIO_OSPEEDR  &= ~(GPIO_SPEED_Mask << Copy_u8GPIOPIN);
		GPIOB->GPIO_OSPEEDR  |=   ( Copy_u8Speed << Copy_u8GPIOPIN*2 );
		break ;
	case GPIO_PORTC:
		GPIOC->GPIO_OTYPER  &=  ~(GPIO_OUTPUT_MASK << Copy_u8GPIOPIN);
		GPIOC->GPIO_OTYPER |=    (Copy_u8OutputMode << Copy_u8GPIOPIN );
		GPIOC->GPIO_OSPEEDR &= ~ (GPIO_SPEED_Mask << Copy_u8GPIOPIN);
		GPIOC->GPIO_OSPEEDR |=   (Copy_u8Speed << Copy_u8GPIOPIN*2 );
		break ;
	default :
		/*DO nothing*/
		break ;
	}
}
void MGPIO_VidSetINputPinMode (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8inputputMode)
{
	switch (Copy_u8GPIOPort){

	case GPIO_PORTA:
		GPIOA->GPIO_PUPDR &=  ~( GPIO_INPUT_Mask << Copy_u8GPIOPIN *2 );
		GPIOA->GPIO_PUPDR |=  ( Copy_u8inputputMode << Copy_u8GPIOPIN *2 );
		break ;
	case GPIO_PORTB:
		GPIOB->GPIO_PUPDR &=  ~( GPIO_INPUT_Mask     << Copy_u8GPIOPIN *2 );
		GPIOB->GPIO_PUPDR |=   ( Copy_u8inputputMode << Copy_u8GPIOPIN *2 );
		break ;
	case GPIO_PORTC:
		GPIOC->GPIO_PUPDR &=  ~( GPIO_INPUT_Mask << Copy_u8GPIOPIN *2 );
		GPIOC->GPIO_PUPDR |=  ( Copy_u8inputputMode << Copy_u8GPIOPIN *2 );
		break ;
	default :
		/*DO nothing*/
		break ;
	}
}

void MGPIO_VidGetPinValue (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 *Copy_pu8PIN)
{
	switch (Copy_u8GPIOPort){
	case GPIO_PORTA:
		*Copy_pu8PIN  =  (GPIOA->GPIO_IDR >> Copy_u8GPIOPIN)&1 ;
		break ;
	case GPIO_PORTB:
		*Copy_pu8PIN  =  (GPIOB->GPIO_IDR >> Copy_u8GPIOPIN)&1 ;
		break ;
	case GPIO_PORTC:
		*Copy_pu8PIN  =  (GPIOC->GPIO_IDR >> Copy_u8GPIOPIN)&1 ;
		break ;
	default : /*DO nothing*/
		break ;
	}

}
void MGPIO_vidSetPinValue (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8Data)
{
	switch (Copy_u8GPIOPort){
	case GPIO_PORTA:
		if(Copy_u8Data==1){
			GPIOA->GPIO_ODR  |=  (Copy_u8Data<<Copy_u8GPIOPIN);
			break ;
		}
		else
		{
			GPIOA->GPIO_ODR  &=  ~(1<<Copy_u8GPIOPIN);
			break;
		}

	case GPIO_PORTB:
		if(Copy_u8Data==1){
			GPIOB->GPIO_ODR  |=  (Copy_u8Data<<Copy_u8GPIOPIN);
			break ;
		}
		else
		{
			GPIOB->GPIO_ODR  &=  ~(1<<Copy_u8GPIOPIN);
			break;
		}
	case GPIO_PORTC:
		if(Copy_u8Data==1){
			GPIOC->GPIO_ODR  |=  (Copy_u8Data<<Copy_u8GPIOPIN);
			break ;
		}
		else
		{
			GPIOC->GPIO_ODR  &=  ~(1<<Copy_u8GPIOPIN);
			break;
		}
	default : /*DO nothing*/
		break ;
	}




}


void MGPIO_vidSetPinValueBSRR (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8Data,u8 Copy_u8Mode){
	switch (Copy_u8GPIOPort){
	case GPIO_PORTA:
		switch (Copy_u8Mode){
		case Reset_BSRR :
			GPIOA->GPIO_BSRR  |=  (Copy_u8Data<<(Copy_u8GPIOPIN+16));
			break;
		case SET_BSRR:
			GPIOA->GPIO_BSRR  |=  (Copy_u8Data<<Copy_u8GPIOPIN);
			break;
		default : break ;
		}
		break ;
		case GPIO_PORTB:
			switch (Copy_u8Mode){
			case Reset_BSRR :
				GPIOB->GPIO_BSRR  |= (Copy_u8Data << (Copy_u8GPIOPIN+16));
				break;
			case SET_BSRR:
				GPIOB->GPIO_BSRR  |=  (Copy_u8Data << Copy_u8GPIOPIN);
				break;
			default : break ;
			}
			break ;
			case GPIO_PORTC:
				switch (Copy_u8Mode){
				case Reset_BSRR :
					GPIOC->GPIO_BSRR  |=  (Copy_u8Data << (Copy_u8GPIOPIN+16));
					break;
				case SET_BSRR:
					GPIOC->GPIO_BSRR  |=  (Copy_u8Data<<Copy_u8GPIOPIN);
					break;
				default : break ;
				}
				break ;
				default : /*DO nothing*/
					break ;
	}


}


void MGPIO_vSelectAlternateFunction(u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,AlternateFunction Copy_u8AlternateFunction)
{
	switch (Copy_u8GPIOPort)
	{
	case GPIO_PORTA:
	if(Copy_u8GPIOPIN>=0 && Copy_u8GPIOPIN <8)
	{
		GPIOA->GPIO_AFRL |= (Copy_u8AlternateFunction<<Copy_u8GPIOPIN*4);
	
	}
	else if (Copy_u8GPIOPIN>=8 && Copy_u8GPIOPIN <16) 
	{
		GPIOA->GPIO_AFRH |= (Copy_u8AlternateFunction<<(Copy_u8GPIOPIN-8)*4);
	}
	break ; 
	case GPIO_PORTB:
		if(Copy_u8GPIOPIN>=0 && Copy_u8GPIOPIN <8)
	{
		GPIOB->GPIO_AFRL |= (Copy_u8AlternateFunction<<Copy_u8GPIOPIN*4);
	
	}
	else if (Copy_u8GPIOPIN>=8 && Copy_u8GPIOPIN <16) 
	{
		GPIOB->GPIO_AFRH |= (Copy_u8AlternateFunction<<(Copy_u8GPIOPIN-8)*4);
	}
	break;
	case GPIO_PORTC:
	if(Copy_u8GPIOPIN>=0 && Copy_u8GPIOPIN <8)
	{
		GPIOC->GPIO_AFRL |= (Copy_u8AlternateFunction<<Copy_u8GPIOPIN*4);
	
	}
	else if (Copy_u8GPIOPIN>=8 && Copy_u8GPIOPIN <16) 
	{
		GPIOC->GPIO_AFRH |= (Copy_u8AlternateFunction<<(Copy_u8GPIOPIN-8)*4);
	}
	default:
		break;
}