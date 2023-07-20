/*********************************************************************************************************
 *********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : RCC
File : Private File
Version :1.0
Date :28/5/2023
 ********************************************************************************************************
 ********************************************************************************************************
 */
#ifndef RCC_PRV_H
#define RCC_PRV_H
// Base Address for RCC memory section 
#define MRCC_BASE_ADDRESS    (0X40023800)

typedef struct  
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved0;
	u32 reserved1;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved_14 ;
	u32 reserved_15 ;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved3;
	u32 reserved4;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 reserved5;
	u32 reserved6;
	u32 AHB1LPEN;
	u32 AHB2LPEN;
	u32 reserved7;
	u32 reserved8;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 reserved9;
	u32 reserved10;
	u32 BDCR;
	u32 CSR;
	u32 reserved11;
	u32 reserved12;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 reserved13;
	u32 DCKCFGR;

}RCC_t;

#define RCC_HSI  0 // High speed Internal clock
#define RCC_HSE  1 // high speed external clock
#define RCC_PLL  2   // Phase Locked Loop clock
#define RCC  ((volatile RCC_t*)MRCC_BASE_ADDRESS)  // pointer to struct from type RCC

#define CR_HSE_EN  16  // Control register external enable 
#define CR_HSI_EN  0  // control register internal enable 
#define CFGR_SW0 0
#define CFGR_SW0Mask   0xfffffffc //
#define CFGR_SW1   1 
#define SW_HSE 0
#define SW_HSI 1
#define CR_HSEBYP 18  // Bypass pin in control register 

/* 2 options of external clock
Crystall or ceramic -- we need 2 pins one for i/p power and one for clk then we choose to not bypass
if we using  RC we only need one pin then we choose to bypass */
#define OSC_CRISTAL 0
#define OSC_RC     1 
// Busses 





// Main PLL Division Factor For USB_OTG 
#define PLL_USB_0    0
#define PLL_USB_1    1
#define PLL_USB_2    2
#define PLL_USB_3    3
#define PLL_USB_4    4
#define PLL_USB_5    5
#define PLL_USB_6    6
#define PLL_USB_7    7
#define PLL_USB_8    8
#define PLL_USB_9    9
#define PLL_USB_10   10
#define PLL_USB_11   11
#define PLL_USB_12   12
#define PLL_USB_13   13
#define PLL_USB_14   14
#define PLL_USB_15   15


/*
 *
#define AHBBus_Masking      15
#define AHBBus_NoDivision   0
#define AHBBus_Divison2     8
#define AHBBus_Divison4     9
#define AHBBus_Divison8     10
#define AHBBus_Divison16    11
#define AHBBus_Divison64    12
#define AHBBus_Divison128   13
#define AHBBus_Divison256   14
#define AHBBus_Divison512   15

#define APBBus_MaSking      7
#define APBBus_NoDivision  0
#define APBus_Divison2    4
#define APBBus_Divison4   5
#define APBBus_Divison8   6
#define APBBus_Divison16  7*/




#endif //RCC_PRV_H
