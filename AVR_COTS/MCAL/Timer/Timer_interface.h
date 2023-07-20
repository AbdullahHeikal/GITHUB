/*
 * ************************************************************************************************************************************
 * ************************************************************************************************************************************
 * AUTHOR     : Abdullah mohamed heikal
 * file       : Timer_interface
 * driver     : timer driver
 * date of v1 : 16/4/2023
 *  * ************************************************************************************************************************************
 *  * ************************************************************************************************************************************
 *  * *********************************************************************************************************************************
 * */


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/* *  * ************************************************************************************************************************************
 *  *  * *****************************************      APIS PROTOTYPES     ******************************************************************
 * */
#include "LIB/STD_Types.h"
#include "Timer_Private.h"
#include "Timer_Config.h"


void Timer2_VidInit(void);
void Timer2_VidNormalMode(u8 Copy_u8PreLoadValue);
void Timer2_VidCompareMatchMode(u8 Copy_u8CompareValue);
void Timer_vidCTC_2CallBack(void(*Timer0_CTC2_callback)(void));
void Timer_vidTOV_2CallBack(void(*Timer0_TOV2_callback)(void));





/*********************************** Timer 0 APIS ************************************************************/
void Timer0_VidSetPreLoadValue(u8 PreLoadValue);

void Timer0_VidCompareMatchvalue(u8 Copy_u8CompareValue);
void Timer_vidCTCCallBack(void(*Timer0_CTC_callback)(void));
void Timer_vidTOVCallBack(void(*Timer0_TOV_callback)(void));
void Timer0_VidInit(void);

/**********************************************************************************************************/
// delay functions
void Timer0_Delay(u32 time,u8 unit);
/**************************** time one 16 bit functions *************************************/
void Timer1_VidInit(void);
void Timer1_VidNormalMode(u8 preLoadValue);
void Timer1_VidCompareMatchMode(u8 Copy_u8CompareValue);
void Timer_vidCTC_1CallBack(void(*Timer1_CTC_callback)(void));
void Timer_vidTOV_1CallBack(void(*Timer1_TOV_callback)(void));


/* ***************************************************************************************** */
/* *************************************** ICU APIS ****************************************  */
void ICU_voidInit(void);
u8 ICU_SetCallBack(void(*ICU_Interrupt)(void));
u8 ICU_voidChangeTrigger(u8 Copu_u8Tiggersource);
u16 ICU_u16ReadInputCapture(void);
void ICU_InterruptDisabl(void);



#endif /* TIMER_INTERFACE_H_ */
