/*
 * MFMI_prv.h
 *
 *  Created on: Jun 14, 2023
 *      Author: midoy
 */

#ifndef MFMI_PRV_H_
#define MFMI_PRV_H_

#define MFMI_BASE_ADRESS (0x40023C00)

typedef struct{
u32 ACR;
u32 KEYR;
u32 OPTKEYR;
u32 SR;
u32 CR;
u32 OPTCR;
}MFMI_t;



#define FMI   ((volatile MFMI_t*)MFMI_BASE_ADRESS)

#define FMI_KEY1  0x45670123
#define FMI_KEY2  0xCDEF89AB

#endif /* MFMI_PRV_H_ */
