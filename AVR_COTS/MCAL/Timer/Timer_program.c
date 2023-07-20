/*
 * ************************************************************************************************************************************
 * ************************************************************************************************************************************
 * AUTHOR     : Abdullah mohamed heikal
 * file       : Timer_Program
 * driver     : timer driver
 * date of v1 : 16/4/2023
 *  * ************************************************************************************************************************************
 *  * ************************************************************************************************************************************
 *  * *********************************************************************************************************************************
 * */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"
#include "Timer_interface.h"
static void(*Global_CTCTimer0Pointer)(void)=NULL;
static void(*Global_TOVTimer0Pointer)(void)=NULL;
static void(*Global_CTCTimer1Pointer)(void)=NULL;
static void(*Global_TOVTimer1Pointer)(void)=NULL;
static void(*Global_CTCTimer2Pointer)(void)=NULL;
static void(*Global_TOVTimer2Pointer)(void)=NULL;
static void(*Global_ICUPointer)(void)=NULL ;

void Timer0_VidInit(){
#if (Timer0_Mode == Normal_Mode)
	{
		CLR_BIT(TCCR0_Register,WGM00_TCCR0);
		CLR_BIT(TCCR0_Register,WGM01_TCCR0);
		SET_BIT(TIMSK_Register,TOIE0_TIMSK);
	}

#elif  (Timer0_Mode == PWM_PhaseCorrect)
	{
		CLR_BIT(TCCR0_Register,WGM01_TCCR0);
		SET_BIT (TCCR0_Register,WGM00_TCCR0);



#if (OC0State_PhaseCorrect==OC0_Disconnected)
		{
			CLR_BIT(TCCR0_Register,COM00_TCCR0);
			CLR_BIT(TCCR0_Register,COM01_TCCR0);
		}
#elif(OC0State_PhaseCorrect==OC0_ClearUp_SetDown)
		{
			SET_BIT(TCCR0_Register,COM01_TCCR0);
			CLR_BIT(TCCR0_Register,COM00_TCCR0);
		}
#elif(OC0State_PhaseCorrect==OC0_SetUp_ClearDown)
		{
			SET_BIT(TCCR0_Register,COM00,TCCR0);
			SET_BIT(TCCR0_Register,COM01_TCCR0);
		}
#else
		{
#error "Invalid OC0 Mode"
		}

#endif
		SET_BIT(TIMSK_Register,TOIE0_TIMSK);
		SET_BIT(TIMSK_Register,OCIE0_TIMSK);
	}
#elif (Timer0_Mode == FastPwm)
	{
		SET_BIT(TCCR0_Register,WGM01_TCCR0);
		CLR_BIT(TCCR0_Register,WGM00_TCCR0);
#if (OC0State_FastPWM==OC0_Disconnected)
		{
			CLR_BIT(TCCR0_Register,COM00_TCCR0);
			CLR_BIT(TCCR0_Register,COM01_TCCR0);
		}
#elif(OC0State_FastPWM==OC0_NonInvertedMode)
		{
			SET_BIT(TCCR0_Register,COM01_TCCR0);
			CLR_BIT(TCCR0_Register,COM00_TCCR0);
		}
#else(OC0State_FastPWM==OC0_InvertedMode)
		{
			SET_BIT(TCCR0_Register,COM00,TCCR0);
			SET_BIT(TCCR0_Register,COM01_TCCR0);
		}
#endif
		SET(TIMSK_Register,TOIE0_TIMSK);
		SET(TIMSK_Register,OCIE0_TIMSK);
	}

#elif (Timer0_Mode==CompareMatch)
	{
		SET_BIT(TCCR0_Register,WGM01_TCCR0);
		CLR_BIT (TCCR0_Register,WGM00_TCCR0);
#if (OC0State_NonPWM==OC0_Disconnected)
		{
			CLR_BIT(TCCR0_Register,COM00_TCCR0);
			CLR_BIT(TCCR0_Register,COM01_TCCR0);
		}
#elif(OC0State_NonPWM==OC0_Toggle)
		{
			SET_BIT(TCCR0_Register,COM00_TCCR0);
			CLR_BIT(TCCR0_Register,COM01_TCCR0);
		}
#elif (OC0State_NonPWM==OC0_Clear)
		{
			SET_BIT(TCCR0_Register,COM01_TCCR0);
			CLR_BIT(TCCR0_Register,COM00_TCCR0);
		}
#elif(OC0State_NonPWM==OC0_Set)
		{
			SET_BIT(TCCR0_Register,COM00,TCCR0);
			SET_BIT(TCCR0_Register,COM01_TCCR0);
		}
#else
		{
#error "Invalid OC0 Mode"
		}

#endif
	}
	SET_BIT(TIMSK_Register,OCIE0_TIMSK);
#else
#error "Invalid Timer Mode"
#endif


}
#if(PreScalerSelecttimer0 == NoClock)
	{
		CLR_BIT(TCCR0_Register,CS00_TCCR0);
		CLR_BIT(TCCR0_Register,CS01_TCCR0);
		CLR_BIT(TCCR0_Register,CS02_TCCR0);
	}
#elif(PreScalerSelecttimer0==CPUClock)
	{
		SET_BIT(TCCR0_Register,CS00_TCCR0);
		CLR_BIT(TCCR0_Register,CS01_TCCR0);
		CLR_BIT(TCCR0_Register,CS02_TCCR0);

	}
#elif(PreScalerSelecttimer0==Pre_8_Scaler)
	{
		CLR_BIT(TCCR0_Register,CS00_TCCR0);
		SET_BIT(TCCR0_Register,CS01_TCCR0);
		CLR_BIT(TCCR0_Register,CS02_TCCR0);
	}
#elif (PreScalerSelecttimer0==Pre_64_Scaler)
	{
		SET_BIT(TCCR0_Register,CS00_TCCR0);
		SET_BIT(TCCR0_Register,CS01_TCCR0);
		CLR_BIT(TCCR0_Register,CS02_TCCR0);
	}
#elif(PreScalerSelecttimer0==Pre_256_Scaler)
	{
		CLR_BIT(TCCR0_Register,CS00_TCCR0);
		CLR_BIT(TCCR0_Register,CS01_TCCR0);
		SET_BIT(TCCR0_Register,CS02_TCCR0);
	}
#elif(PreScalerSelecttimer0==Pre_1024_Scaler)
	{
		SET_BIT(TCCR0_Register,CS00_TCCR0);
		CLR_BIT(TCCR0_Register,CS01_TCCR0);
		SET_BIT(TCCR0_Register,CS02_TCCR0);
	}
#elif(PreScalerSelecttimer0==ExternalClock_falling)
	{
		CLR_BIT(TCCR0_Register,CS00_TCCR0);
		SET_BIT(TCCR0_Register,CS01_TCCR0);
		SET_BIT(TCCR0_Register,CS02_TCCR0);
	}
#elif(PreScalerSelecttimer0==ExternalClock_rising)
	{
		SET_BIT(TCCR0_Register,CS00_TCCR0);
		SET_BIT(TCCR0_Register,CS01_TCCR0);
		SET_BIT(TCCR0_Register,CS02_TCCR0);
	}
#else
#error " Invalid prescaler select "
#endif


void Timer0_VidSetPreLoadValue(u8 Copy_u8PreLoadValue){
	TCNT0_Register = Copy_u8PreLoadValue;
}
void Timer0_VidCompareMatchvalue(u8 Copy_u8CompareValue){
	OCR0_Register=Copy_u8CompareValue;

}
void Timer_vidCTC_0CallBack(void(*Timer0_CTC_callback)(void)){
	Global_CTCTimer0Pointer=Timer0_CTC_callback;
}
void Timer_vidTOV_0CallBack(void(*Timer0_TOV_callback)(void)){
	Global_TOVTimer0Pointer=Timer0_TOV_callback;
}
void __vector_10 (void) __attribute__((signal));
void __vector_10(void){
	Global_CTCTimer0Pointer();

}
// ovf  timer 1
void __vector_11 (void) __attribute__((signal));
void __vector_11(void){
	Global_TOVTimer0Pointer();

}



void Timer2_VidInit(void){
#if (Timer2_Mode == Normal_Mode)
	{
		CLR_BIT(TCCR2_Register,WGM20_TCCR2);
		CLR_BIT(TCCR2_Register,WGM21_TCCR2);
		SET_BIT(TIMSK_Register,TOIE2_TIMSK);
	}

#elif  (Timer2_Mode == PWM_PhaseCorrect)
	{
		CLR_BIT(TCCR2_Register,WGM21_TCCR2);
		SET_BIT (TCCR2_Register,WGM20_TCCR2);



#if (OC2State_PhaseCorrect==OC2_Disconnected)
		{
			CLR_BIT(TCCR2_Register,COM20_TCCR2);
			CLR_BIT(TCCR2_Register,COM21_TCCR2);
		}
#elif(OC2State_PhaseCorrect==OC2_ClearUp_SetDown)
		{
			SET_BIT(TCCR2_Register,COM21_TCCR2);
			CLR_BIT(TCCR2_Register,COM20_TCCR2);
		}
#elif(OC2State_PhaseCorrect==OC2_SetUp_ClearDown)
		{
			SET_BIT(TCCR2_Register,COM20,TCCR2);
			SET_BIT(TCCR2_Register,COM21_TCCR2);
		}
#else
		{
#error "Invalid OC2 Mode"
		}

#endif
		SET_BIT(TIMSK_Register,TOIE2_TIMSK);
		SET_BIT(TIMSK_Register,OCIE2_TIMSK);
	}
#elif (Timer2_Mode == FastPwm)
	{
		SET_BIT(TCCR2_Register,WGM21_TCCR2);
		CLR_BIT(TCCR2_Register,WGM20_TCCR2);
#if (OC2State_FastPWM==OC2_Disconnected)
		{
			CLR_BIT(TCCR2_Register,COM20_TCCR2);
			CLR_BIT(TCCR2_Register,COM21_TCCR2);
		}
#elif(OC2State_FastPWM==OC2_NonInvertedMode)
		{
			SET_BIT(TCCR2_Register,COM21_TCCR2);
			CLR_BIT(TCCR2_Register,COM20_TCCR2);
		}
#else(OC2State_FastPWM==OC2_InvertedMode)
		{
			SET_BIT(TCCR2_Register,COM20,TCCR2);
			SET_BIT(TCCR2_Register,COM21_TCCR2);
		}
#endif
		SET(TIMSK_Register,TOIE2_TIMSK);
		SET(TIMSK_Register,OCIE2_TIMSK);
	}

#elif (Timer2_Mode==CompareMatch)
	{
		SET_BIT(TCCR2_Register,WGM21_TCCR2);
		SET_BIT (TCCR2_Register,WGM20_TCCR2);
#if (OC2State_NonPWM==OC2_Disconnected)
		{
			CLR_BIT(TCCR2_Register,COM20_TCCR2);
			CLR_BIT(TCCR2_Register,COM21_TCCR2);
		}
#elif(OC2State_NonPWM==OC2_Toggle)
		{
			SET_BIT(TCCR2_Register,COM20_TCCR2);
			CLR_BIT(TCCR2_Register,COM21_TCCR2);
		}
#elif (OC2State_NonPWM==OC2_Clear)
		{
			SET_BIT(TCCR2_Register,COM21_TCCR2);
			CLR_BIT(TCCR2_Register,COM20_TCCR2);
		}
#elif(OC2State_NonPWM==OC2_Set)
		{
			SET_BIT(TCCR2_Register,COM20,TCCR2);
			SET_BIT(TCCR2_Register,COM21_TCCR2);
		}
#else
		{
#error "Invalid OC2 Mode"
		}

#endif
	}
	SET_BIT(TIMSK_Register,OCIE2_TIMSK);
#else
#error "Invalid Timer Mode"
#endif


	// Prescaler select


#if(PreScalerSelect == NoClock)
	{
		CLR_BIT(TCCR2_Register,CS20_TCCR2);
		CLR_BIT(TCCR2_Register,CS21_TCCR2);
		CLR_BIT(TCCR2_Register,CS22_TCCR2);
	}
#elif(PreScalerSelect==CPUClock)
	{
		SET_BIT(TCCR2_Register,CS20_TCCR2);
		CLR_BIT(TCCR2_Register,CS21_TCCR2);
		CLR_BIT(TCCR2_Register,CS22_TCCR2);

	}
#elif(PreScalerSelect==Pre_8_Scaler)
	{
		CLR_BIT(TCCR2_Register,CS20_TCCR2);
		SET_BIT(TCCR2_Register,CS21_TCCR2);
		CLR_BIT(TCCR2_Register,CS22_TCCR2);
	}
#elif (PreScalerSelect==Pre_64_Scaler)
	{
		SET_BIT(TCCR2_Register,CS20_TCCR2);
		SET_BIT(TCCR2_Register,CS21_TCCR2);
		CLR_BIT(TCCR2_Register,CS22_TCCR2);
	}
#elif(PreScalerSelect==Pre_256_Scaler)
	{
		CLR_BIT(TCCR2_Register,CS20_TCCR2);
		CLR_BIT(TCCR2_Register,CS21_TCCR2);
		SET_BIT(TCCR2_Register,CS22_TCCR2);
	}
#elif(PreScalerSelect==Pre_1024_Scaler)
	{
		SET_BIT(TCCR2_Register,CS20_TCCR2);
		CLR_BIT(TCCR2_Register,CS21_TCCR2);
		SET_BIT(TCCR2_Register,CS22_TCCR2);
	}
#elif(PreScalerSelect==ExternalClock_falling)
	{
		CLR_BIT(TCCR2_Register,CS20_TCCR2);
		SET_BIT(TCCR2_Register,CS21_TCCR2);
		SET_BIT(TCCR2_Register,CS22_TCCR2);
	}
#elif(PreScalerSelect==ExternalClock_rising)
	{
		SET_BIT(TCCR2_Register,CS20_TCCR2);
		SET_BIT(TCCR2_Register,CS21_TCCR2);
		SET_BIT(TCCR2_Register,CS22_TCCR2);
	}
#else
#error " Invalid prescaler select "
#endif


}
void Timer2_VidNormalMode(u8 Copy_u8PreLoadValue){
	TCNT2_Register = Copy_u8PreLoadValue;

}
void Timer2_VidCompareMatchMode(u8 Copy_u8CompareValue){
	OCR2_Register=Copy_u8CompareValue;
}
void Timer_vidCTC_2CallBack(void(*Timer0_CTC2_callback)(void)){
	Global_CTCTimer2Pointer=Timer0_CTC2_callback;
}
void Timer_vidTOV_2CallBack(void(*Timer0_TOV2_callback)(void)){
	Global_TOVTimer2Pointer=Timer0_TOV2_callback;
}



//compare match  ISR -- TIMER1
void __vector_4 (void) __attribute__((signal));
void __vector_4(void){
	Global_CTCTimer2Pointer();

}
// ovf  timer 1
void __vector_5 (void) __attribute__((signal));
void __vector_5(void){
	Global_TOVTimer2Pointer();

}


//******************************** delay function for timer zero  ********************************************* ..
void Timer0_Delay(u32 time,u8 unit){
	if (unit == 'm')
	{
		u32 Local_u32Counter=0;
		//SET TIMER MODE COMPAREMATCH
		SET_BIT(TCCR0_Register,WGM01_TCCR0);
		CLR_BIT (TCCR0_Register,WGM00_TCCR0);
		//SET PRE SCALER TO EQUAL 1MS WILL BE 64
		SET_BIT(TCCR2_Register,CS20_TCCR2);
		SET_BIT(TCCR2_Register,CS21_TCCR2);
		CLR_BIT(TCCR2_Register,CS22_TCCR2);
		OCR0_Register=125;

		while(Local_u32Counter!=time){
			Local_u32Counter++;
		}
	}
	else if (unit == 'u')
	{
		u32 Local_u32Counter=0;
		//SET TIMER MODE COMPAREMATCH
		SET_BIT(TCCR0_Register,WGM01_TCCR0);
		CLR_BIT (TCCR0_Register,WGM00_TCCR0);
		//SET PRE SCALER TO EQUAL 1MS WILL BE CPU
		CLR_BIT(TCCR2_Register,CS20_TCCR2);
		SET_BIT(TCCR2_Register,CS21_TCCR2);
		CLR_BIT(TCCR2_Register,CS22_TCCR2);
		OCR0_Register=255;
		while(Local_u32Counter!=time){
			Local_u32Counter++;
		}


	}
}
/* ********************************************************************************************** */
void Timer1_VidInit(void){
	// MODE OF TIMER 1 -- MODE 14 
CLR_BIT (TCCR1A_Register,WGM01_TCCR1A);
SET_BIT (TCCR1A_Register,WGM11_TCCR1A);
SET_BIT (TCCR1B_Register,WGM12_TCCR1B);
SET_BIT (TCCR1B_Register,WGM13_TCCR1B);


// OC1A.B PIN MODE -- NON INVERTED 
 CLR_BIT (TCCR1A_Register,COM1A1_TCCR1A);
 SET_BIT (TCCR1A_Register,COM1A0_TCCR1A); 
}
void Timer1_VidNormalMode(u8 preLoadValue){
TCNT1_REGISTER = preLoadValue ; 
}
void Timer1_VidCompareMatchMode(u8 Copy_u8CompareValue){
  ICR_Register = Copy_u8CompareValue;
}



void Timer_vidCTC_1CallBack(void(*Timer1_CTC_callback)(void)){
	Global_CTCTimer1Pointer = Timer1_CTC_callback ;

}
void Timer_vidTOV_1CallBack(void(*Timer1_TOV_callback)(void)){
Global_TOVTimer1Pointer = Timer1_TOV_callback;
}






/* **************************************** ICU Functions ********************************** */
void ICU_voidInit(void){
// set initially to be rising edge 
 SET_BIT(TCCR1B_Register,TCCR1B_IEC1);

// ENABLE INTERRUPT  
SET_BIT (TIMSK_Register,TICIE1_TIMSK);

}
u8 ICU_SetCallBack(void(*ICU_Interrupt)(void)){
	u8 Local_u8ErrorState = OK;
	if (ICU_Interrupt != NULL){
		Global_ICUPointer = ICU_Interrupt;
		return Local_u8ErrorState; 
	}
	else {
		Local_u8ErrorState=NOK; 
		return Local_u8ErrorState;
	}

}
u8 ICU_voidChangeTrigger(u8 Copu_u8Tiggersource){
	u8 Local_u8ErrorState = OK;
	switch (Copu_u8Tiggersource){
		case FALLING_EDGE :
		CLR_BIT (TCCR1B_Register,TCCR1B_IEC1);
		break;
		case RISING_EGDE :
		SET_BIT (TCCR1B_Register,TCCR1B_IEC1);
		break;
		default :
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}

u16 ICU_u16ReadInputCapture(void){
	return ICR_Register;

}
void ICU_InterruptDisabl(void){
CLR_BIT(TIMSK_Register,TICIE1_TIMSK);
}


void __vector_6 (void) __attribute__((signal));
void __vector_6(void){
	if (Global_ICUPointer != NULL){
		Global_ICUPointer();
	}
	else {
		// don't do anything 
	}


}
/* ******************************************************************************************* */