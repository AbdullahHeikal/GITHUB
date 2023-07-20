/*
 * 
 *
 *  Created on: Mar 11, 2023
 *      Author: abdul
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_
#define MCUCR *((volatile u8*)(0x55))
#define GIFR *((volatile u8*)(0x5A))
#define  GICR *((volatile u8*)(0x5B))
#define MCUCSR *((volatile u8*)(0x54))

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define INTF1 7
#define INTF0 6
#define INTF2 5

#define INT1 7
#define INT0 6
#define INT2 5

#define ISC2 6

 #define enable  1
 #define disable 2
 #define FALLING_EDGE  1
#define RISING_EDGE   2
#define LOW_LEVEL     3
#define ON_CHANGE     4
#endif /* INTERRUPT_PRIVATE_H_ */
