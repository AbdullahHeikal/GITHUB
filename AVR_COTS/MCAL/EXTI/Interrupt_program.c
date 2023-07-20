/*
 * Interrupt_program.c
 *
 *  Created on: Mar 11, 2023
 *      Author: abdul
 */

#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"
#include "INTERUPT_interface.h"
#include "interrupt_config.h"
#include "interrupt_private.h"


void(*EXINT0_ADDRESS)(void)=NULL;
void(*EXINT1_ADDRESS)(void)=NULL;
void(*EXINT2_ADDRESS)(void)=NULL;
void EXTI_INT0INIT(void){
	// Check sense control
#if INT0_SENS == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENS == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENS == FALLING_EDGE
	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
#elif INT0_SENS == RISING_EDGE
	SET_BIT(MCUCR,,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "wrong INT0_SENS configuration options"
#endif
#if INT0_INITIAL_STATE == enable
	SET_BIT(GICR,INT0);
#elif INT0_INITIAL_STATE == disable
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Invalid choice"
#endif

}
void EXTI_INT1INIT(void){
	// Check sense control
#if INT1_SENS == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENS == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENS == FALLING_EDGE
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);
#elif INT1_SENS == RISING_EDGE
	SET_BIT(MCUCR,,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "wrong INT1_SENS configuration options"
#endif
#if INT1_INITIAL_STATE == enable
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == disable
	CLR_BIT(GICR,INT1);
#else
#error "Invalid choice"
#endif

}
void EXTI_INT2INIT(void){
	// Check sense control
	//INT2 is an edge interrupt
#if INT0_SENS == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
#elif INT0_SENS == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#endif
#if INT2_INITIAL_STATE == enable
	SET_BIT(GICR,GICR_INT0);
#elif INT2_INITIAL_STATE == disable
	CLR_BIT(GICR,INT0);
#else
#error "Invalid choice"
#endif

}
// INT 0 POST BUILD CONFIG
u8 EXTI_u8setsensecontrolINT0(u8 u8_sense_copy){
	u8 Local_error= OK;
	switch (u8_sense_copy){
	case FALLING_EDGE:
		SET_BIT(MCUCR,ISC01);
		CLR_BIT(MCUCR,ISC00);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
	case LOW_LEVEL:
		CLR_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		break;
	default:Local_error =NOK;
	}
	return Local_error;
}
// SET CALLBACK FUNCTION
void EXTI_u8ISRINT0Address(void(*israddress)(void)){
		EXINT0_ADDRESS=israddress;
}

void __vector_1 (void)  __attribute__ ((signal,used, externally_visible));
void __vector_1(void){
		EXINT0_ADDRESS();


}
u8 EXTI_u8setsensecontrolINT1(u8 u8_sense_copy){
	u8 Local_u8errorstatus = OK ;
	switch (u8_sense_copy){
	case LOW_LEVEL:
		CLR_BIT(MCUCR,ISC11);
		CLR_BIT(MCUCR,ISC10);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,ISC10);
		CLR_BIT(MCUCR,ISC11);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR,ISC11);
		CLR_BIT(MCUCR,ISC10);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
	default :
		Local_u8errorstatus=NOK;
	}
	return Local_u8errorstatus;
}
void EXTI_u8INT1ISRAddress(void(*israddress)(void)){
		EXINT1_ADDRESS=israddress;


}
void __vector_2 (void) __attribute__ ((signal));
void __vector_2 (void){
		EXINT1_ADDRESS();

}

u8 EXTI_u8setsensecontrolINT2(u8 u8_sense_copy){
	u8 Local_Error = OK;
	switch(u8_sense_copy){
	case FALLING_EDGE:
		CLR_BIT(MCUCSR,ISC2);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCSR,ISC2);
		break;
	default :
		Local_Error =NOK;

	}
	return Local_Error;
}
void EXTI_u8INT2ISRAddress(void(*israddress)(void)){
		EXINT2_ADDRESS=israddress;

}
void __vector_3 (void) __attribute__ ((signal));
void __vector_3 (void){
		EXINT2_ADDRESS();
}
