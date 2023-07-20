/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : ABDULLAH HEIKAL 
MICRO : STM32F401CCU6
DRIVER : GPIO_Driver
File : interface File
Version :1.0
Date :29/5/2023
********************************************************************************************************
********************************************************************************************************
 */
#ifndef MGPIO_INT_H
#define MGPIO_INT_H
/********************************************************** MODES macros  **************************************8****************************//******************/

#define GPIO_INPUT                   0
#define GPIO_OUTPUT                  1
#define GPIO_AlternateFunction       2
#define GPIO_AnalogMode              3
/********************************************************** PORT NUMBERS macros  **************************************8****************************//******************/

#define GPIO_PORTA  0
#define GPIO_PORTB  1
#define GPIO_PORTC  2
/********************************************************** PIN NUMBERS macros **************************************8****************************//******************/

#define GPIO_PIN0   0
#define GPIO_PIN1   1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15
// speed macros
 #define Low_Speed       0
 #define Medium_Speed    1
 #define High_Speed      2
 #define VeryHigh_Speed  3
// output mode macros
#define OPushPull   0
#define OOPenDrain  1
// I/O pull-up or pull-down macros
#define INPUT_Floating          0
#define INPUT_PULLUP            1
#define INPUT_PULLDOWN          2

// MODE TO Choose between reset and set
 #define Reset_BSRR    0
 #define SET_BSRR      1


void MGPIO_VidGPIOModeSelect(u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8GPIOMode);
void MGPIO_VidGPIOSetOutputPinMode (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8OutputMode , u8 Copy_u8Speed);
void MGPIO_VidSetInputPinMode (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8inputputMode);
void MGPIO_VidGetPinValue (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 *Copy_pu8PIN);
void MGPIO_vidSetPinValue (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8Data);
void MGPIO_vidSetPinValueBSRR (u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,u8 Copy_u8Data,u8 Copy_u8Mode);

typedef enum {
    AF0=0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15
}AlternateFunction;
void MGPIO_vSelectAlternateFunction(u8 Copy_u8GPIOPort,u8 Copy_u8GPIOPIN,AlternateFunction Copy_u8AlternateFunction);











#endif
