/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : GPIO_Driver
File : Private File
Version :1.0
Date :29/5/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef MGPIO_PRV_H
#define MGPIO_PRV_H
#define GPIOA_BASE_ADDRESS    0x40020000
#define GPIOB_BASE_ADDRESS    0x40020400
#define GPIOC_BASE_ADDRESS    0x40020800
typedef struct
{
	u32 GPIO_Moder ;
	u32 GPIO_OTYPER ;
	u32 GPIO_OSPEEDR ;
	u32 GPIO_PUPDR ;
	u32 GPIO_IDR ;
	u32 GPIO_ODR ;
	u32 GPIO_BSRR ;
	u32 GPIO_LCKR ;
	u32 GPIO_AFRL ;
	u32 GPIO_AFRH ;
}MGPIO_t;

#define GPIOA   ((volatile MGPIO_t *)GPIOA_BASE_ADDRESS)
#define GPIOB   ((volatile MGPIO_t *)GPIOB_BASE_ADDRESS)
#define GPIOC   ((volatile MGPIO_t *)GPIOC_BASE_ADDRESS)
#define GPIO_PIN_Mask     3
#define GPIO_OUTPUT_MASK  1
#define GPIO_SPEED_Mask    3
#define GPIO_INPUT_Mask    3

#endif
