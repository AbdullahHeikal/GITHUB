/*
 * Timer_Private.h
 *
 *  Created on: Apr 15, 2023
 *      Author: abdul
 */
/*
 * ************************************************************************************************************************************
 * ************************************************************************************************************************************
 * AUTHOR     : Abdullah mohamed heikal
 * file       : Timer_Private
 * driver     : timer driver
 * date of v1 : 16/4/2023
 * edit v1.1 : 29/4/2023
 *  * ************************************************************************************************************************************
 *  * ************************************************************************************************************************************
 *  * *********************************************************************************************************************************
 * */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
/***********************************************         Registers       ********************************************************
 * *  * ************************************************************************************************************************************
 *  *  * ************************************************************************************************************************************
 */
// *********************************   TCCR0 Register   *******************************************************

#define TCCR0_Register     *((volatile u8 *) 0x53)
#define FOC0_TCCR0     7
#define WGM00_TCCR0    6
#define COM01_TCCR0    5
#define COM00_TCCR0    4
#define WGM01_TCCR0    3
#define CS02_TCCR0     2
#define CS01_TCCR0     1
#define CS00_TCCR0     0
//*************************************************************************************************************
#define OCR0_Register      *((volatile u8 *) 0x5C)  // STORE VALUE OF COMPARE MATCH
#define TCNT0_Register     *((volatile u8 *) 0x52)  // STORE COUNTER VALUE

// *********************************   TIMSK Register   *******************************************************

#define TIMSK_Register     *((volatile u8 *) 0x59)
#define  OCIE2_TIMSK   7
#define  TOIE2_TIMSK   6
#define  TICIE1_TIMSK  5
#define  OCIE1A_TIMSK  4
#define  OCIE1B_TIMSK  3
#define  TIOE1_TIMSK   2
#define  OCIE0_TIMSK   1
#define  TOIE0_TIMSK   0
//*************************************************************************************************************

// *********************************   TIFR Register   *******************************************************

#define TIFR_Register      *((volatile u8 *) 0x58)
#define TOV0_TIFR    0
#define OCF0_TIFR    1
#define TOV1_TIFR    2
#define OCF1B_TIFR   3
#define OCF1A_TIFR   4
#define ICF1_TIFR    5
#define TOV2_TIFR    6
#define OCF2_TIFR    7

//*************************************************************************************************************



#define TCCR2_Register     *((volatile u8 *) 0x45)
#define FOC2_TCCR2     7
#define WGM20_TCCR2    6
#define COM21_TCCR2    5
#define COM20_TCCR2    4
#define WGM21_TCCR2    3
#define CS22_TCCR2     2
#define CS21_TCCR2     1
#define CS20_TCCR2     0


#define TCNT2_Register     *((volatile u8 *) 0x44)
#define OCR2_Register      *((volatile u8 *) 0x43)

/* *  * ************************************************************************************************************************************
 *  *  * ************************************************************************************************************************************
 * */
/************************************ timer 1 registers ***************************/
#define TCCR1A_Register *((volatile u8 *)0x4f) /* Timer control High byte */
#define WGM01_TCCR1A  0 
#define WGM11_TCCR1A  1
#define COM1A1_TCCR1A 7
#define COM1A0_TCCR1A 6
#define COM1B1_TCCR1A 5
#define COM1B0_TCCR1A 4
#define TCCR1B_Register *((volatile u8 * )0x4E) /* Timer control Low byte */
#define WGM12_TCCR1B   3 
#define WGM13_TCCR1B   4
#define TCCR1B_IEC1 6
#define TCNT1H_Register *((volatile u8 *)0x4d) /* Timer counter A high byte */
#define TCNT1L_Register *((volatile u8 *)0x4c) /*  Timer counter A Low byte */
#define TCNT1_REGISTER  *((volatile u8 *)0x4c)
#define OCR1AH_Register *((volatile u8 *)0x4B) /* output compare A high byte */
#define OCR1AL_Register *((volatile u8 *)0x4A) /* output compare A high byte */
#define OCR1BH_Register *((volatile u8 *)0x49) /* output compare b high byte */
#define OCR1BL_Register *((volatile u8 *)0x48) /* output compare b high byte */
#define ICR1L_Register  *((volatile u8 *)0x46) /* Input capture unit Low */
#define ICR1H_Register *((volatile u8 *)0x47)  /* Input capture unit High  */
#define ICR_Register   *((volatile u16 *)0x46) /* Input capture unit access all register 16 bit */


// modes of timer
#define Normal_Mode         1
#define PWM_PhaseCorrect    2
#define CompareMatch        3
#define FastPwm             4



// timer clock 
#define NoClock                 1
#define CPUClock               2
#define Pre_8_Scaler            3
#define Pre_64_Scaler           4
#define Pre_256_Scaler          5
#define Pre_1024_Scaler         6
#define ExternalClock_falling  7
#define ExternalClock_rising   8


// PIN OC modes 
#define Disconnected      0
#define Toggle            1
#define Clear             2
#define Set               3
#define Toggle            1
#define NonInvertedMode  4
#define InvertedMode     5
#define RISING_EGDE   1 
#define FALLING_EDGE 2 
#define ClearUp_SetDown  6
#define SetUp_ClearDown  7

// timer 1 14 mode 
#define OC1A    1
#define OC1B    2
#define Both    3
#define OC1A_masking 0b00111111
#define OC1B_masking 0b11001111
#define BOTH_Masking 0b00001111
#endif /* TIMER_PRIVATE_H_ */
