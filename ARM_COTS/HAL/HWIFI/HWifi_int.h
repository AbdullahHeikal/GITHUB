/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : WIFI_Driver
File : interface File
Version :1.0
Date :13/6/2023
********************************************************************************************************
********************************************************************************************************
 */

#ifndef HWIFI_INT_H
#define HWIFI_INT_H


void HWIFI_vINT(void);

void HWIFI_vSendCommand(u8 Copy_u8Command);


u8 HWIFI_u8CheckResponce(void);


#define   HWIFI_PORT   GPIO_PORTA
#define   HWIFI_TX     GPIO_PIN10
#define   HWIFI_RX     GPIO_PIN9













#endif