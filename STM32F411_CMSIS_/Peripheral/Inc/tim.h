/*
 * tim.h
 *
 *  Created on: Aug 21, 2021
 *      Author: thanh
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#include "main.h"

/*
 * @brief TIM2 TRGG ADC configuration
 */
void tim_TIM2_config(void);

/*
 * @brief TIM3 delay configuration
 */
void tim_TIM3_delayConfig();

/*
 * @brief TIM3 milisecon delay
 */
void tim_TIM3_msDelay(uint32_t msDelay);

/*
 * @brief TIM2 periodic interrupt
 */
void tim_TIM3_periodicInterrupt(uint32_t msDelay);

/*
 * @brief configuration TIM5CH2 -->PA2
 */
void tim_TIM5_CH2N_GPIO_config();

/*
 * @brief TIM5 Output Compare OC configuaration
 */
void tim_TIM5_OC_config(uint32_t msPeriod);

/*
 * @brief TIM5 PWM GPIO configuration CH3 PA3
 */
void tim_TIM5_PWM_GPIO_config(void);

/*
 * @brief TIM5 PWM configuratin configuration
 */
void tim_TIM5_PWM_config();

/*
 * @brief RGB TIM5
 */
void tim_TIM5_RGB(uint8_t R, uint8_t G, uint8_t B);

#endif /* INC_TIM_H_ */
