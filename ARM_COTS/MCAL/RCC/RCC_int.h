/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : RCC
File : interface File
Version :1.0
Date :28/5/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef RCC_INT_H
#define RCC_INT_H

/* OPTIONS FOR BUS NAMES */
typedef enum {
	AHBBus_NoDivision =  0,
	AHBus_Divison2    =  8,
	AHBus_Divison4    =  9,
	AHBus_Divison8    =  10,
	AHBus_Divison16   =  11,
	AHBus_Divison64   =  12,
	AHBus_Divison128  =  13,
	AHBus_Divison256   =  14,
	AHBus_Divison512  = 15,
	AHBus_Masking     =15,
	APBus_MaSking     = 7,
	APBus_NoDivision  = 0,
	APBus1_Divison2    = 4,
	APBus1_Divison4    = 5,
	APBus1_Divison8    = 6,
	APBus1_Divison16   = 7,
}Bus_Prescaler;

#define Bus_PRE AHBus_Divison2


void MRCC_u8Init (void);
void MRCC_VIDEnablePeripheral (u8 Copy_u8BUS , u8 Copy_u8peripheral);
void MRCC_VIDDisablePeripheral(u8 Copy_u8BUS , u8 Copy_u8peripheral);


/*
	AHBBus_NoDivision
	AHBus_Divison2
	AHBus_Divison4
	AHBus_Divison8
	AHBus_Divison16
	AHBus_Divison64
	AHBus_Divison128
	AHBus_Divison256
	AHBus_Divison512
	AHBus_Masking
	APBus_MaSking
	APBus_NoDivision
	APBus1_Divison2
	APBus1_Divison4
	APBus1_Divison8
	APBus1_Divison16
	APBus2_Divison2
	APBus2_Divison4
	APBus2_Divison8
	APBus2_Divison16
 */

void MRCC_VBusSpeed(Bus_Prescaler Prescaler);






/*
define peripherals bits
*/
//AHB1 Register
#define AHB1_GPIOA   0
#define AHB1_GPIOB   1
#define AHB1_GPIOC   2
#define AHB1_GPIOD   3
#define AHB1_GPIOE   4
#define AHB1_GPIOH   7
#define AHB1_CRC     12
#define AHB1_DMA1    21
#define AHB1_DMA2    22

//AHB2 Register
#define AHB2_OTGFS   7

//APB1 Register
#define APB1_TIM2     0
#define APB1_TIM3     1
#define APB1_TIM4     2
#define APB1_TIM5     3
#define APB1_WWDG     11
#define APB1_SPI2     14
#define APB1_SPI3     15
#define APB1_USART2   17
#define APB1_I2C1     21
#define APB1_I2C2     22
#define APB1_I2C3     23
#define OAPB1_PWR      28

//APB2 Register 
#define AHB2_TIM1     0
#define AHB2_USART1   4
#define AHB2_USART6   5
#define AHB2_ADC1     8
#define AHB2_SDIO     11
#define AHB2_SPI1     12
#define AHB2_SPI4     13
#define AHB2_SYSCFG   14
#define AHB2_TIM9     16
#define AHB2_TIM10    17
#define AHB2_TIM11    18




#define  RCC_AHB1   0
#define  RCC_AHB2   1
#define  RCC_APB1   2
#define  RCC_APB2   3





#endif //RCC_INT_H
