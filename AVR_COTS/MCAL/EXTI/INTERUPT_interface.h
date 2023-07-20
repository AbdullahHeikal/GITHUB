/*
 * INTERUPT_interface.h
 *
 *  Created on: Mar 11, 2023
 *      Author: abdul
 */

#ifndef INTERUPT_INTERFACE_H_
#define INTERUPT_INTERFACE_H_


void EXTI_INT0INIT(void);
void EXTI_INT1INIT(void);
void EXTI_INT2INIT(void);
/*function sets snse control by post build configuration
 * input :u8_sense_copy ,, arguments : 1- low level
 *                                     2- on change
 *                                     3- falling
 *                                     4- rising
 * output : error state  */
u8 EXTI_u8setsensecontrolINT0(u8 u8_sense_copy);
u8 EXTI_u8setsensecontrolINT1(u8 u8_sense_copy);
u8 EXTI_u8setsensecontrolINT2(u8 u8_sense_copy);
void EXTI_u8ISRINT0Address(void(*israddress)(void));
void EXTI_u8INT1ISRAddress(void(*israddress)(void));
void EXTI_u8INT2ISRAddress(void(*israddress)(void));



#endif /* INTERUPT_INTERFACE_H_ */
