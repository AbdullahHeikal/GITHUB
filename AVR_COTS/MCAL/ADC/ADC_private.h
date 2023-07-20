/*
 * ADC_private.h
 *
 *  Created on: Apr 7, 2023
 *   *      Author: abdullah heikal
 *           File :ADC_PRIVATE
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/****************************************************************************************************************
 * *******************************   Start defines of  ADC register       *****************************************/
/*
 * 1 - ADMUX ->Address 0X27
 * 2-  ACSRA ->Address 0X26
 * 3-  ADCH  ->Address 0x25
 * 4-  ADCL  ->Address 0x24
 * 5-  SFIOR ->Address 0x50
 *  */

#define ADMUX_register    *((volatile u8 *) 0x27)
#define ADCSRA_register   *((volatile u8 *) 0x26)
#define ADCH_register     *((volatile u8 *) 0x25)
#define ADCL_register     *((volatile u8 *) 0x24)
#define SFIOR_register    *((volatile u8 *) 0x50)
#define ADC_TwoRegisters  *((volatile u16*) 0x24)


/****************************************************************************************************************
 * *******************************   End defines of  ADC register       *****************************************/



/****************************************************************************************************************
 * *******************************   Start define registers pins        *****************************************/
// ***********************************  ADMUX register *****************************************************
#define ADMUX_MUX0  0
#define ADMUX_MUX1  1
#define ADMUX_MUX2  2
#define ADMUX_MUX3  3
#define ADMUX_MUX4  4
#define ADMUX_ADLAR 5
#define ADMUX_REFS0 6
#define ADMUX_REFS1 7

//***********************************  ADCSRA register *****************************************************
#define ADCSRA_ADPS0  0
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS2  2
#define ADCSRA_ADIE   3
#define ADCSRA_ADIF   4
#define ADCSRA_ADATE  5
#define ADCSRA_ADSC   6
#define ADCSRA_ADEN   7

//***********************************  SFIOR register *****************************************************
#define SFIOR_ADTS0  5
#define SFIOR_ADTS1  6
#define SFIOR_ADTS2  7



#define ADMUX_Reset  0xE0
#define PreScaler_Reset 0x07


#endif /* ADC_PRIVATE_H_ */
