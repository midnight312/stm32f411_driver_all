/*
 * tim.h
 *
 *  Created on: Jun 21, 2021
 *      Author: thanh
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#include "main.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;

/*
 * @brief TIMER3 configuration
 */
_Bool tim_TIM3_config(uint32_t msPriod);

/*
 * @brief TIM4 output compare GPIO config
 */
void tim_TIM4_OC_GPIO_config(void);

/*
 * @brief TIM4 output compare config
 */
_Bool tim_TIM4_OC_config(uint32_t msPeriod);

/*
 * @brief PWMs GPIO pins
 */
void tim_TIM3_PWM_GPIO_config(void);

/*
 * @brief TIM PWM Prephiral configuration
 */
_Bool tim_TIM3_PWM_config(void);

/*
 * @brief TIM PWM LED duty 0-100
 */
void tim_PWM_setDutyCycle_CH1(uint8_t duty_0_100);
void tim_PWM_setDutyCycle_CH2(uint8_t duty_0_100);
void tim_PWM_setDutyCycle_CH3(uint8_t duty_0_100);

/*
 * @brief Application PWM LED RGB
 */
void tim_PWM_setRGB(uint8_t R, uint8_t G, uint8_t B);

/*
 * @brief TIM5 ENCOUDER GPIO configuration
 */
void tim_TIM5_ENCODER_GPIO_config(void);

/*
 * @brief TIM5 ENCLUDER configuration
 */
_Bool tim_TIM5_ENCODER_config(void);

#endif /* INC_TIM_H_ */
