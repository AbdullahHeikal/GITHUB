/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR  : ABDULLAH HEIKAL
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : NVIC_Driver
File    : Private File
Version :1.0
Date    :30/5/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef MNVIC_PRV_H
#define MNVIC_PRV_H

typedef struct {
	u32 NVIC_ISER [8]  ;
	u32 Reserved1 [24] ;
    u32 NVIC_ICER [8]  ;
    u32 Reserved2 [24] ;
    u32 NVIC_ISPR [8]  ;
    u32 Reserved3 [24] ;
    u32 NVIC_ICPR [8]  ;
    u32 Reserved4 [24] ;
    u32 NVIC_IABR [8]  ;
    u32 Reserved5 [56] ;
    u8  NVIC_IPR  [240];
    u32 reserved6 [580];
    u32 STIR ;

}MNVIC_t;

#define MNVIC_BASE_ADDRESS  (0XE000E100)

#define NVIC  ((volatile MNVIC_t* )MNVIC_BASE_ADDRESS)

#define AIRCR    (*(volatile u32*) 0xE000ED0C)

#define MNVIC_VECTKEY 0X05FA0000

#define Register_Division 32




#endif //MNVIC_PRV_H
