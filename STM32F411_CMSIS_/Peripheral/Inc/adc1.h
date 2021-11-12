/*
 * adc1.h
 *
 *  Created on: Aug 19, 2021
 *      Author: thanh
 */

#ifndef INC_ADC1_H_
#define INC_ADC1_H_

#include "main.h"

//ADC channel singnal sellect
typedef enum ADC_singleSelect_TAG
{
	ADC_singleSelect_Potentimeter = 1,
	ADC_singleSelect_x,
	ADC_singleSelect_y
}ADC_singleSelect_e;

/*
 * @breif ADC GPIO Pin: PA1-POT PA2-X PA3-Y
 */
void adc_GPIO_config(void);

/*
 * @brief ADC single Channel config
 */
void adc_singleConfig(ADC_singleSelect_e channel);

/*
 * @brief ADC Start-SWSTART
 */
void adc_start();

/*
 * @brief ADC Stop
 */
void adc_stop();

/*
 * @brief ADC Poll for end conversion
 */
_Bool adc_pollForEndConversion(uint32_t msTimeOut);

/*
 * @breif ADC read value
 */
uint16_t adc_readValue(void);

/*
 * @breif ADC enable/disabel Interrupt
 */
void adc_enableEOC_IT();

void adc_disableEOC_IT();

/*
 * @breif ADC Multil-Channel Configuration
 */
void adc_multiChanel_config(void);

/*
 * @breif ADC Multil-Channel DMA Configuration
 */
void adc_multichanel_DMA_config(uint16_t *adcBuffer);

/*
 * @brief ADC Analog Watdog configuration
 * @prama lowThreshod/highThreshold 0-4095
 */
void adc_AWD_config(uint8_t channel, uint16_t lowThreshold, uint16_t highThreshold);

/*
 * @brief ADC1 Temperation
 */
uint16_t adc_Temperature(void);

#endif /* INC_ADC1_H_ */
