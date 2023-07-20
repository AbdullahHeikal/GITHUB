/*

 *  Created on: Mar 11, 2023
 *      Author: abdul
 */

#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

/*
 options of sense control 0
 1- falling egde
 2- rising edge
 3- low level
 4- on change */
#define INT0_SENS   FALLING_EDGE
#define INT1_SENS   FALLING_EDGE
#define INT2_SENS   FALLING_EDGE
/*STATES OF PIE
  1- ENABLE
  2- DISABLE
  */
#define INT0_INITIAL_STATE   enable
#define INT1_INITIAL_STATE   disable
#define INT2_INITIAL_STATE   disable
#endif /* INTERRUPT_CONFIG_H_ */
