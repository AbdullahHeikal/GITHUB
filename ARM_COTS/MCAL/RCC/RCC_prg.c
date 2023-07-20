/*
 * RCC_prg.c
 *
 *  Created on: Jun 3, 2023
 *      Author: abdul
 */


/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL
MICRO : STM32F401CCU6
DRIVER : RCC
File : Program File
Version :1.0
Date :28/5/2023
 ********************************************************************************************************
 ********************************************************************************************************
 */
#include "STD_Types.h"
#include "RCC_cfg.h"
#include "RCC_int.h"
#include "RCC_prv.h"



void MRCC_u8Init (void){
#if (SYS_CLK == RCC_HSE)    // check on Sys clock config == High speed external clock
#if (SYS_OSC==OSC_CRISTAL)  // check on type of external clock  == crystal
	RCC->CR &= ~(1<<CR_HSEBYP);  // reset bypass pin to ensure that 2 pins working
#elif (SYS_OSC==OSC_RC)// check on type of external clock  == RC
	RCC->CR |= (1<<CR_HSEBYP); // bypass the power pin of CLK
#endif
	RCC->CR |= 1<<CR_HSE_EN; // enable external
	while (!GET_BIT(RCC->CR,CR_HSE_EN+1));
	RCC->CFGR |=1; // system clOCk is HSE


#elif (SYS_CLK==RCC_HSI)
	RCC->CR |= 1<<CR_HSI_EN;
	while (!((RCC->CR>>(CR_HSI_EN+1))&1));
	RCC->CFGR &= (CFGR_SW0Mask);
	RCC->CFGR = CFGR_SW0;
#endif

}

void MRCC_VIDEnablePeripheral (u8 Copy_u8BUS , u8 Copy_u8peripheral)
{
	switch (Copy_u8BUS){
	case RCC_AHB1 :
		RCC->AHB1ENR |= 1<<Copy_u8peripheral ;
		break;
	case RCC_AHB2 :
		RCC->AHB2ENR |= 1<<Copy_u8peripheral ;
		break;
	case RCC_APB1 :
		RCC->APB1ENR |= 1<<Copy_u8peripheral ;
		break;
	case RCC_APB2 :
		RCC->APB2ENR |= 1<<Copy_u8peripheral ;
		break;
	default:
		break;
	}



}
void MRCC_VIDDisablePeripheral (u8 Copy_u8BUS , u8 Copy_u8peripheral){
	switch (Copy_u8BUS){
	case RCC_AHB1 :
		RCC->AHB1RSTR &= ~ (1<<Copy_u8peripheral) ;
		break;
	case RCC_AHB2 :
		RCC->AHB2RSTR &= ~ (1<<Copy_u8peripheral) ;
		break;
	case RCC_APB1 :
		RCC->APB1RSTR &= ~ (1<<Copy_u8peripheral)  ;
		break;
	case RCC_APB2 :
		RCC->APB2RSTR &= ~ (1<<Copy_u8peripheral)  ;
		break;
	default:
		break;
	}

}


void MRCC_VBusSpeed(Bus_Prescaler Prescaler){
	switch (Prescaler) {
	case AHBBus_NoDivision :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBBus_NoDivision <<4);
		break;
	case AHBus_Divison2 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison2 <<4);
		break;
	case AHBus_Divison4 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison4 <<4);
		break;
	case AHBus_Divison8 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison8 <<4);
		break;
	case AHBus_Divison16 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison16 <<4);
		break;
	case AHBus_Divison64 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison64 <<4);
		break;
	case AHBus_Divison128 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison128 <<4);
		break;
	case AHBus_Divison256 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison256 <<4);
		break;
	case AHBus_Divison512 :
		RCC->CFGR &= ~(	AHBus_Masking <<4);
		RCC->CFGR |=  (AHBus_Divison512 <<4);
		break;
	case APBus1_Divison2 :
		RCC->CFGR &= ~(	APBus_MaSking <<10);
		RCC->CFGR |=  (APBus1_Divison2 <<10);
		break;
	case APBus1_Divison4 :
		RCC->CFGR &= ~(	APBus_MaSking <<10);
		RCC->CFGR |=  (APBus1_Divison2 <<10);
		break;
	case APBus1_Divison8 :
		RCC->CFGR &= ~(	APBus_MaSking <<10);
		RCC->CFGR |=  (APBus1_Divison2 <<10);
		break;
	case APBus1_Divison16 :
		RCC->CFGR &= ~(	APBus_MaSking << 10);
		RCC->CFGR |=  (APBus1_Divison16 <<10);
		break;

	default :
		break;
	}
}




