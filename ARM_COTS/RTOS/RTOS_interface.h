/**********************************************************************/ 
/* AUTHOR      : Ahmed Assaf                                          */
/* DATE        : 7 Sep 2022                                           */
/* Description : Interface file for OS module                         */
/* Version     : V01                                                  */
/**********************************************************************/
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_voidStartOS(void);
u8 RTOS_u8CreateTask (  void(*Copy_Handler)(void) , u8 Copy_u8Periodicity, u8 Copy_u8Priority , u8 Copy_FirstD  );


#endif
