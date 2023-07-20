/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR  : ABDULLAH HEIKAL
MICRO   : STM32F401CCU6
Layer   : MCAL
DRIVER  : NVIC_Driver
File    : interface File
Version :1.0
Date    :30/5/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef MNVIC_INT_H
#define MNVIC_INT_H

typedef enum {
	MNVIC_GROUP16_SUB0 = 3 ,
	MNVIC_GROUP8_SUB2 ,
	MNVIC_GROUP4_SUB4 ,
	MNVIC_GROUP2_SUB8 ,
	MNVIC_GROUP0_SUB16
} GroupMode_t;




void MNVIC_VoidInterrupt_set_enable (u8 Copy_u8InterruptId);
void MNVIC_VoidInterrupt_Clear_enable (u8 Copy_u8InterruptId);
void MNVIC_VoidInterrupt_Enable_Pending (u8 Copy_u8InterruptId);
void MNVIC_VoidInterrupt_Disable_Pending (u8 Copy_u8InterruptId);
void  MNVIC_VoidInterrupt_Active (u8 Copy_u8InterruptId,u8 *ReadData);
void MNVIC_SetInterrupt_Priority(u8 Copy_u8InterruptId,u8 Copy_u8GroupId,u8 Copy_u8SubGroup);
void MNVIC_SetGroupMode(GroupMode_t  Copy_enGroupMode);

// GROUP MODES


















#endif
