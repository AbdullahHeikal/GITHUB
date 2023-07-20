/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL
MICRO : STM32F401CCU6
DRIVER : MNVIC_Driver
File : Program File
Version :1.0
Date :30/5/2023
 ********************************************************************************************************
 ********************************************************************************************************
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MNVIC_cfg.h"
#include "MNVIC_int.h"
#include "MNVIC_prv.h"

u8 Global_u8GroupMode ;
void MNVIC_VoidInterrupt_set_enable (u8 Copy_u8InterruptId){
	u8 Register_Number = Copy_u8InterruptId/Register_Division ;
	u8 Bit_Number = Copy_u8InterruptId % Register_Division ;
	NVIC ->NVIC_ISER[Register_Number] |= (1<<Bit_Number);
}
void MNVIC_VoidInterrupt_Clear_enable (u8 Copy_u8InterruptId){
	u8 Register_Number = Copy_u8InterruptId/Register_Division ;
	u8 Bit_Number = Copy_u8InterruptId % Register_Division ;
	NVIC ->NVIC_ICER[Register_Number] |= (1<<Bit_Number);
}
void MNVIC_VoidInterrupt_Enable_Pending (u8 Copy_u8InterruptId){
	u8 Register_Number = Copy_u8InterruptId/Register_Division ;
	u8 Bit_Number = Copy_u8InterruptId % Register_Division ;
	NVIC ->NVIC_ISPR[Register_Number] |= (1<<Bit_Number);
}
void MNVIC_VoidInterrupt_Disable_Pending (u8 Copy_u8InterruptId){
	u8 Register_Number = Copy_u8InterruptId/Register_Division ;
	u8 Bit_Number = Copy_u8InterruptId % Register_Division ;
	NVIC ->NVIC_ICPR[Register_Number] |= (1<<Bit_Number);
}
void  MNVIC_VoidInterrupt_Active (u8 Copy_u8InterruptId,u8 *ReadData){
	u8 Register_Number = Copy_u8InterruptId/Register_Division ;
	u8 Bit_Number = Copy_u8InterruptId % Register_Division ;
	*ReadData &= ((NVIC->NVIC_IABR[Register_Number]>>Bit_Number)&1);
}
void MNVIC_SetGroupMode(GroupMode_t Copy_enGroupMode){
	Global_u8GroupMode = Copy_enGroupMode ;
	AIRCR = MNVIC_VECTKEY ;
	u32 RegisterValue=0;
	RegisterValue = MNVIC_VECTKEY | (Copy_enGroupMode << 8);
	AIRCR = RegisterValue ;
}

void MNVIC_SetInterrupt_Priority(u8 Copy_u8InterruptId,u8 Copy_u8GroupId,u8 Copy_u8SubGroup){
	switch (Global_u8GroupMode){
	case MNVIC_GROUP16_SUB0 : NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8GroupId <<4 ;break;
	case MNVIC_GROUP8_SUB2  : NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8GroupId <<5 ; NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8SubGroup <<4 ;   break;
	case MNVIC_GROUP4_SUB4  : NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8GroupId <<6 ; NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8SubGroup <<4 ;   break;
	case MNVIC_GROUP2_SUB8  : NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8GroupId <<7 ; NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8SubGroup <<4 ;   break;
	case MNVIC_GROUP0_SUB16 : NVIC->NVIC_IPR [Copy_u8InterruptId]= Copy_u8SubGroup <<4;      break;
	default :
		break;
	}
	// configure 4 bits depend on number of G and SG
}
