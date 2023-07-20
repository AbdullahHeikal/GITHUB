#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_int.h"
#include "STK_cfg.h"
#include "STK_prv.h"

void(*callbacksys)(void)=NULL_PTR;
void MSTK_voidInit(void)
{
	CLR_BIT(MSTK_REG->CTRL,CLKSOURCE);
}

void MSTK_voidIntState(void)
{
	SET_BIT(MSTK_REG->CTRL,TICKINT);
}

void MSTK_voidStart(u32 Copy_u8PreloadValue)
{
	/* Load reload value */
	MSTK_REG->LOAD = Copy_u8PreloadValue;

	/* Clear Val register */
	MSTK_REG->VAL = 0;

	/* Enable Systick */
	SET_BIT(MSTK_REG->CTRL,STK_ENABLE);
}

u8 MSTK_u8ReadFlag(void)
{
	return (GET_BIT(MSTK_REG->CTRL,COUNTFLAG));
}

void MSTK_voidDelayUsec(u32 Copy_u8DelayUsec)
{
	CLR_BIT(MSTK_REG->CTRL,TICKINT);
	MSTK_voidStart(Copy_u8DelayUsec*2);
	while(MSTK_u8ReadFlag() == 0);

}

void MSTK_voidDelayMsec(u32 Copy_u8DelayMsec)
{
	CLR_BIT(MSTK_REG->CTRL,TICKINT);
	MSTK_voidStart(Copy_u8DelayMsec*2000);
	while(MSTK_u8ReadFlag() == 0);
}

u32  MSTK_u32GetElapsedTime(void)
{
	return ((MSTK_REG->LOAD)-(MSTK_REG->VAL)) ;
}

u32  MSTK_u32GetRemainingTime(void)
{
	return MSTK_REG->VAL ;
}


void CALLBACKSYS(void(*callback)(void)){
	callbacksys = callback ;
}


void Systick_IRQHandler(void){
	callbacksys();

}
