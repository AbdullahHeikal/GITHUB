/*
 * ADC_program.c
 *
 *  Created on: Apr 7, 2023
 *      Author: abdullah heikal
 *      File : ADC_program
 */
/****************************************************************************************************************
 * *******************************    Includes       *****************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
/*****************************************************************************************************************/
// notification function pointer to send it to ISR --call back concept--
void (*Notification_CallBack)(void)=NULL;
//Global variable to store reading of asynch conversion
u16 Copy_AsynchReading=0;
void ADC_VoidInit(void){
/**********************************Choose Refrence Voltage First*************************************************/

#if (ReferenceVolt==AREF_RefrenceVoltage)
	{
		CLR_BIT(ADMUX_register,ADMUX_REFS0);
		CLR_BIT(ADMUX_register,ADMUX_REFS1);
	}
#elif(ReferenceVolt==AVCC_RefrenceVoltage)
	{
		SET_BIT(ADMUX_register,ADMUX_REFS0);
		CLR_BIT(ADMUX_register,ADMUX_REFS1);
	}
#elif(ReferenceVolt==InternalVoltage)
	{
		CLR_BIT(ADMUX_register,ADMUX_REFS0);
		SET_BIT(ADMUX_register,ADMUX_REFS1);
	}
#endif


/******************************************************************************************************************/
/*************************** pre scaler Bit Masking ********************************************************************/
#if (Prescaler==PreScaler2)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler2;

	}
#elif(Prescaler==PreScaler4)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler4;
	}
#elif(Prescaler==PreScaler8)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler8;
	}
#elif(Prescaler==PreScaler16)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler16;
	}
#elif(Prescaler==PreScaler32)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler32;
	}
#elif(Prescaler==PreScaler64)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler64;
	}
#elif(Prescaler==PreScaler128)
	{
		ADCSRA_register =ADCSRA_register & PreScaler_Reset;
		ADCSRA_register=ADCSRA_register|PreScaler128;
	}
#endif


/****************************************************Enable ADC************************************************************************/
SET_BIT(ADCSRA_register,ADCSRA_ADEN);
/******************************************************************************************************************/
/******************************************************************************************************************/
}

u8 ADC_u8StartConversionSynchronous (u8 Copy_u8ADC_Channels){
	// define counter to use it in timeout mechanism
	u16 Local_u8Counter = 0 ;
	u8 Local_ErrorState = OK;
	/*channel selection using Bit Masking Method
	 * by ensure that mux bits is zero first
	 * then ORing with channel */
	ADMUX_register =ADMUX_register & ADMUX_Reset;
	ADMUX_register=ADMUX_register|Copy_u8ADC_Channels;
	// set left adjust to read the Most 8 bits
	SET_BIT(ADMUX_register,ADMUX_ADLAR);
	// Start conversion
	SET_BIT(ADCSRA_register,ADCSRA_ADSC);

	// polling until the adc finish the conversion or reach time out
	while ((GET_BIT(ADCSRA_register,ADCSRA_ADIF))!=1 || (Local_u8Counter<=TimeOut))
	{
		Local_u8Counter ++ ;
	}
	// check if conversion happen or the processor has an error
	if (GET_BIT(ADCSRA_register,ADCSRA_ADIF)==1)
	{
		//return data from ADC register
		return ADCH_register;
	}
	else
	{
		Local_ErrorState =NOK;
		return Local_ErrorState;
	}
	SET_BIT(ADCSRA_register,ADCSRA_ADIF);

}


u16 ADC_u16StartConversionSynchronous (u8 Copy_u8ADC_Channels){
	// define counter to use it in timeout mechanism
	u16 Local_u8Counter = 0 ;
	u8 Local_ErrorState = OK;
	ADMUX_register =ADMUX_register & ADMUX_Reset;
	ADMUX_register=ADMUX_register|Copy_u8ADC_Channels;
	// Start conversion
	SET_BIT(ADCSRA_register,ADCSRA_ADSC);
	// polling until the adc finish the conversion or reach time out
	while ((GET_BIT(ADCSRA_register,ADCSRA_ADIF))!=1 || (Local_u8Counter==TimeOut))
	{
		Local_u8Counter ++ ;
	}
	// check if conversion happen or the processor has an error
	if (GET_BIT(ADCSRA_register,ADCSRA_ADIF)==1)
	{
		return ADC_TwoRegisters;
	}
	else
	{
		Local_ErrorState =NOK;
		return Local_ErrorState;
	}
}
u8 ADC_u8StartConversionAsynchronous(u8 Copy_u8ADC_Channels ,void (*notification_function)(void)){
u8 Local_ErrorState = OK ;
	ADMUX_register = ADMUX_register & ADMUX_Reset;
	ADMUX_register = ADMUX_register|Copy_u8ADC_Channels;
	SET_BIT(ADCSRA_register,ADCSRA_ADIE);
	if(Notification_CallBack==NULL)
	{
		return Local_ErrorState=NOK;

	}
	else
	{
		Notification_CallBack = notification_function;
		return Local_ErrorState;

	}
	SET_BIT(ADCSRA_register,ADCSRA_ADSC);

}

u16 ADC_Mapping(u16 Range1_max,u16 Range1_min,u16 Range2_max,u16 Range2_min,u16 Range1_reading)
{
	return (Range1_min+(Range1_reading-Range1_min)*((Range2_max-Range2_min)/(Range1_max-Range1_min)));

}

/****************************************************************************************************************
 * *******************************   end of  APIS       *****************************************/

/**************************************** ISR ****************************************************/
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void){
	Notification_CallBack();
	Copy_AsynchReading = ADC_TwoRegisters;
}
