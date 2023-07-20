/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : UART_Driver
File : PRV File
Version :1.0
Date :7/6/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef SPI_PRV_H
#define SPI_PRV_H


#define SPI1_BASEAddress   0x40013000
typedef struct 
{
    u32 SPI_CR1;
    u32 SPI_CR2;
    u32 SPI_SR ; 
    u32 SPI_DR ; 
    u32 SPI_CRCPR;
    u32 SPI_RXCRCR;
    u32 SPI_TXCRCR;
    /* data */
}SPI_t;





#define   SPI1   ((volatile SPI_t* )SPI1_BASEAddress);









#endif