#ifndef _ADC1_H
#define _ADC1_H

#include "main.h"

//ADC single chanel sellect
typedef enum ADC_SingleSellect_Tag
{
	ADC_SingleSellect_Device1 = 0,
	ADC_SingleSellect_Device2,
	ADC_SingleSellect_Device3

}ADC_SingleSellect_e;

/**
 * @brief ADC gpio PIN : PA0, PA1, PA2
 */
void adc_GPIO_config(void);

/**
 * @brief ADC single Chanel configuartion
 */
void adc_singleConfig(ADC_SingleSellect_e channel);

/**
 * @brief ADC start SWSTART
 */
void adc_start(void);

/**
 * @brief ADC stop
 */
void adc_stop(void);

/**
 * @brief ADC Poll end of conversion
 */
_Bool adc_pollEndOffConversion(uint32_t timeout);

/**
 * @brief read ADC
 */
uint16_t adc_readValue(void);

/**
 * @brief enable/disable Interrupt ADC
 */
void adc_Enable_Interrupt(void);
void adc_Disable_Interrupt(void);




#endif /* _ADC1_H */
