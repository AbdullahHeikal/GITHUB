/*
 * MFMI_prg.c
 *
 *  Created on: Jun 14, 2023
 *      Author: midoy
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MFMI_cfg.h"
#include "MFMI_prv.h"
#include "MFMI_int.h"


void FMI_voidsectorErease(u8 Copy_u8Sector){
	//1- pooling on busy flag
	while(GET_BIT(FMI->SR,16)==1);
	//2- Unlock Flash Register
	if(GET_BIT(FMI->CR,31)==1)
	{
		FMI->KEYR =FMI_KEY1;
		FMI->KEYR =FMI_KEY2;
	}
	//3- Select sector
	FMI->CR &=~(0b1111<<3);
	FMI->CR |=(Copy_u8Sector<<3);
	//4- Set sector erase
	FMI->CR |=(1<<1);
	//5-start operation
	FMI->CR |=(1<<16);
	//6-wait until finish
	while(GET_BIT(FMI->SR,16)==1);
	//7- clear the flag
	FMI->SR |=(1<<0);
	//8- deSelect sector erase
	FMI->CR &=~(1<<1);
}

void FMI_voidFlashWrite(u32 Copy_u32Adress,u16* Copy_pu16Data,u16 Copy_u16Lenght){
	//1- pooling on busy flag
	while(GET_BIT(FMI->SR,16)==1);
	//2- Unlock Flash Register
	if(GET_BIT(FMI->CR,31)==1)
	{
		FMI->KEYR =FMI_KEY1;
		FMI->KEYR =FMI_KEY2;
	}
	// 3- select element size
	FMI->CR &=~(0b11<<8);
	FMI->CR |=(1<<8);
	//4- activating programming mode
	FMI->CR |=(1<<0);
	//5- write data
	for (u16 counter=0;counter<Copy_u16Lenght;counter++){
		*((volatile u32*)Copy_u32Adress)=Copy_pu16Data[counter];
		Copy_u32Adress+=2;
	}
	//6 wait for busy flag
	while(GET_BIT(FMI->SR,16)==1);
	//7- clear the flag
	FMI->SR |=(1<<0);
	//8- deSelect sector erase
	FMI->CR &=~(1<<0);
}


