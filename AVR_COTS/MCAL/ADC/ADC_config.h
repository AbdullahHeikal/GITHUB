/*
 * ADC_config.h
 *
 *  Created on: Apr 7, 2023
 *     Author: abdullah heikal
 *      FILE : ADC_config
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*************************************** conversion mode ******************************************************** */
#define SingleConversion 1
#define AutoTrigger      2
#define ConversionMode   SingleConversion
/*****************************************************************************************************************/


/*************************************** channels Type ******************************************************** */
#define SingleEnded 1
#define Diffrential   2
/*****************************************************************************************************************/

/*************************************** ADC 8 channels ******************************************************** */
#define ADC_Channel0   0X00
#define ADC_Channel1   0X01
#define ADC_Channel2   0X02
#define ADC_Channel3   0X03
#define ADC_Channel4   0X04
#define ADC_Channel5   0X05
#define ADC_Channel6   0X06
#define ADC_Channel7   0X07
#define ConstVolt      0X1E
#define GND            0X1F

/*****************************************************************************************************************/

/*********************** Configuration of pre build single ended & diffrential *************************************
 * **************************************************************************************************************/
#define Channels_type SingleEnded
#define PositiveGain1_channel ADC_Channel0
#define NegativeGain1_channel ADC_Channel0
#define PositiveGain10_channel ADC_Channel0
#define NegativeGain10_channel ADC_Channel0
#define PositiveGain200_channel ADC_Channel0
#define NegativeGain200_channel ADC_Channel0
/**************************************voltage refrence selection************************************************************/
#define AREF_RefrenceVoltage 1
#define AVCC_RefrenceVoltage 2
#define InternalVoltage  3
#define ReferenceVolt    AVCC_RefrenceVoltage

/*****************************************************************************************************************/

/***************************************pre scaler select**************************************************************************/
#define PreScaler2     0x01
#define PreScaler4     0x02
#define PreScaler8     0x03
#define PreScaler16    0x04
#define PreScaler32    0x05
#define PreScaler64    0x06
#define PreScaler128   0x07
#define Prescaler      PreScaler8
/*****************************************************************************************************************/

/************************************Auto Trigger Source*****************************************************************************/
#define FreeRunningMode            1
#define AnalogComparator           2
#define EXTIR0                     3
#define TimerCounter0_CompareMatch 4
#define TimerCounter0_OverFlow     5
#define TimerCounter_CompareMatchB 6
#define TimerCounter1_OverFlow     7
#define TimerCounter0_ICU          8
#define AutoTriggerSource    FreeRunningMode
/*****************************************************************************************************************/

#define TimeOut 2000


#endif /* ADC_CONFIG_H_ */
