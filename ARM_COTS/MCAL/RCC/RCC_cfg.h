/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : RCC
File : Config File
Version :1.0
Date :28/5/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef RCC_CFG_H
#define RCC_CFG_H
/* 
OPTIONS OF SYSCLK 
1- RCC_HSI  
2- RCC_HSE 
 */
#define SYS_CLK RCC_HSI

 
#define SYS_CLKSWITCH   SW_HSI
#define SYS_OSC  NOT_BAYPASSED
#define PLL_USBOTGDIVISIONFACTOR  PLL_USB_5

/* AHB bus choices
 AHBBus_NoDivision
 AHBBus_Divison2
 AHBBus_Divison4
 AHBBus_Divison8
 AHBBus_Divison16
 AHBBus_Divison64
 AHBBus_Divison128
 AHBBus_Divison256
 AHBBus_Divison512
 */


#define AHBBUS_CLK_PreScaler  AHBBus_Divison2


/*
# APBBus_NoDivision
# APBus_Divison2
# APBBus_Divison4
# APBBus_Divison8
# APBBus_Divison16

 */


#define APBBUS_CLK_PreScaler  APBus_Divison2





#endif //RCC_CONFIG_H
