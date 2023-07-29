#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MSYSTICK_prv.h"
#include "MSYSTICK_cfg.h"
#include "MSYSTICK_int.h"

void (*global_voidPointer)(void)=NULL_PTR;

void MSYSYTICK_voidInit(void)
{
#if (SYSTICK_Source==AHB)
	SYSTICK->CTRL |=1<<ClockSource;

#elif (SYSTICK_Source==AHB_DIVIDEBY8)

	SYSTICK->CTRL &=~(1<<ClockSource);

#endif
}

void MSYSYTICK_voidStart(u32 Copy_u32Loadvalue)
{
	SYSTICK->LOAD = Copy_u32Loadvalue;
	SYSTICK->VAL =0;
	SYSTICK->CTRL |=1;
}

u8   MSYSYTICK_voidReadFlag(void)
{
	return GET_BIT(SYSTICK->CTRL,CountFlag);
}

void MSYSYTICK_voidCtrlIntState(SYSTICKState Copy_State )
{
	switch (Copy_State){
	case SYSTICKEnable:
		SYSTICK->CTRL |=1<<TickInt;
		break;
	case SYSTICKDisable:
		SYSTICK->CTRL &=~(1<<TickInt);
		break;
	default:  break;
	}
}

u32  MSTK_u32GetElapsedTime(void)
{
	return (((SYSTICK->LOAD)-(SYSTICK->VAL))/2) ;
}

u32  MSTK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL ;
}

void MSYSYTICK_voidDelayMs(u32 Copy_u32Delayvalue){
	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSYTICK_voidStart(Copy_u32Delayvalue*2);
	while(MSYSYTICK_voidReadFlag()==0);

}

void MSYSYTICK_voidDelayms(u32 Copy_u32Delayvalue){

	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSYTICK_voidStart(Copy_u32Delayvalue*2000);
	while(MSYSYTICK_voidReadFlag()==0);
}

void MSYSTICK_voidSetCallBack(void(*ptr)(void))
{
	global_voidPointer=ptr;

}


void Systick_IRQHandler(void)
{
	if (global_voidPointer!=NULL_PTR){
	global_voidPointer();
	}
}

