/*
 * MFMI_int.h
 *
 *  Created on: Jun 14, 2023
 *      Author: midoy
 */

#ifndef MFMI_INT_H_
#define MFMI_INT_H_


void FMI_voidsectorErease(u8 Copy_u8Sector);

void FMI_voidFlashWrite(u32 Copy_u32Adress,u16* Copy_pu16Data,u16 Copy_u16Lenght);

#endif /* MFMI_INT_H_ */
