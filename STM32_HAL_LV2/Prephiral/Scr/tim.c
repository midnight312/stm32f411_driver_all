/*
 * tim.c
 *
 *  Created on: Jun 21, 2021
 *      Author: thanh
 */

#include "tim.h"

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;
/*
 * @brief TIMER3 configuration
 */
_Bool tim_TIM3_config(uint32_t msPriod)
{
	__HAL_RCC_TIM3_CLK_ENABLE();
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = (msPriod*10 - 1);
	htim3.Init.Period = 9600 - 1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	if(HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		return false;
	}
	//Clock source configuration
	TIM_ClockConfigTypeDef clockSrcConfig = {0};
	clockSrcConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if(HAL_TIM_ConfigClockSource(&htim3, &clockSrcConfig) != HAL_OK)
	{
		return false;
	}
	//Master output trigger
	TIM_MasterConfigTypeDef masterClockConfig = {0};
	masterClockConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	masterClockConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if(HAL_TIMEx_MasterConfigSynchronization(&htim3, &masterClockConfig) != HAL_OK)
	{
		return false;
	}

	HAL_NVIC_SetPriority(TIM3_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
	return true;
}
/*
 * @brief TIM4 output compare GPIO config
 */
void tim_TIM4_OC_GPIO_config(void)
{
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOD_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	gpioInitStruct.Alternate = GPIO_AF2_TIM4;
	HAL_GPIO_Init(GPIOD, &gpioInitStruct);
}

/*
 * @brief TIM4 output compare config
 */
_Bool tim_TIM4_OC_config(uint32_t msPeriod)
{
	__HAL_RCC_TIM4_CLK_ENABLE();
	htim4.Instance = TIM4;
	htim4.Init.Prescaler = (msPeriod*10 - 1);
	htim4.Init.Period = 9600 - 1;
	htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	if(HAL_TIM_Base_Init(&htim4) != HAL_OK)
	{
		return false;
	}
	if(HAL_TIM_OC_Init(&htim4) != HAL_OK)
	{
		return false;
	}
	TIM_OC_InitTypeDef ocConfig = {0};
	ocConfig.OCMode = TIM_OCMODE_TOGGLE;
	ocConfig.Pulse = 2000- 1;
	ocConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	ocConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	ocConfig.OCFastMode = TIM_OCFAST_DISABLE;
	ocConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	ocConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if(HAL_TIM_OC_ConfigChannel(&htim4, &ocConfig, TIM_CHANNEL_1) != HAL_OK)
	{
		return false;
	}
	ocConfig.Pulse = 5000 - 1;
	if(HAL_TIM_OC_ConfigChannel(&htim4, &ocConfig, TIM_CHANNEL_2) != HAL_OK)
	{
		return false;
	}
	ocConfig.Pulse = 5000 - 1;
	return true;
}

void tim_TIM3_PWM_GPIO_config(void)
{
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOC_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	gpioInitStruct.Alternate = GPIO_AF2_TIM3;
	HAL_GPIO_Init(GPIOC, &gpioInitStruct);
}

/*
 * @brief TIM PWM Prephiral configuration
 */
_Bool tim_TIM3_PWM_config(void)
{
	__HAL_RCC_TIM3_CLK_ENABLE();
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 100 - 1;
	htim3.Init.Period = 96 - 1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP ;
	if(HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		return false;
	}
	//Clock source configuration
	TIM_ClockConfigTypeDef clockSrcConfig = {0};
	clockSrcConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if(HAL_TIM_ConfigClockSource(&htim3, &clockSrcConfig) != HAL_OK)
	{
		return false;
	}
	//PWM
	HAL_TIM_PWM_Init(&htim3);
	TIM_OC_InitTypeDef ocConfig = {0};
	//CH1
	ocConfig.OCMode = TIM_OCMODE_PWM1;
	ocConfig.Pulse = 0;
	ocConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	ocConfig.OCFastMode = TIM_OCFAST_DISABLE;
	if(HAL_TIM_PWM_ConfigChannel(&htim3, &ocConfig, TIM_CHANNEL_1) != HAL_OK)
	{
		return false;
	}
	//CH2
	ocConfig.OCMode = TIM_OCMODE_PWM1;
	ocConfig.Pulse = 0;
	ocConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	ocConfig.OCFastMode = TIM_OCFAST_DISABLE;
	if(HAL_TIM_PWM_ConfigChannel(&htim3, &ocConfig, TIM_CHANNEL_2) != HAL_OK)
	{
		return false;
	}
	//CH3
	ocConfig.OCMode = TIM_OCMODE_PWM1;
	ocConfig.Pulse = 0;
	ocConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	ocConfig.OCFastMode = TIM_OCFAST_DISABLE;
	if(HAL_TIM_PWM_ConfigChannel(&htim3, &ocConfig, TIM_CHANNEL_3) != HAL_OK)
	{
		return false;
	}
	return true;
}

/*
 * @brief TIM PWM LED duty 0-100
 */
void tim_PWM_setDutyCycle_CH1(uint8_t duty_0_100)
{
	if(duty_0_100 > 100) duty_0_100 = 100;
	uint16_t ccValue = (uint16_t)(__HAL_TIM_GET_AUTORELOAD(&htim3)*(duty_0_100/100.0f));
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,ccValue);
}
void tim_PWM_setDutyCycle_CH2(uint8_t duty_0_100)
{
	if(duty_0_100 > 100) duty_0_100 = 100;
	uint16_t ccValue = (uint16_t)(__HAL_TIM_GET_AUTORELOAD(&htim3)*(duty_0_100/100.0f));
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,ccValue);
}
void tim_PWM_setDutyCycle_CH3(uint8_t duty_0_100)
{
	if(duty_0_100 > 100) duty_0_100 = 100;
	uint16_t ccValue = (uint16_t)(__HAL_TIM_GET_AUTORELOAD(&htim3)*(duty_0_100/100.0f));
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,ccValue);
}

/*
 * @brief Application PWM LED RGB
 */
void tim_PWM_setRGB(uint8_t R, uint8_t G, uint8_t B)
{
	tim_PWM_setDutyCycle_CH1(100*(R/255.0f));
	tim_PWM_setDutyCycle_CH2(100*(G/255.0f));
	tim_PWM_setDutyCycle_CH3(100*(B/255.0f));
}

/*
 * @brief TIM5 ENCOUDER GPIO configuration
 */
void tim_TIM5_ENCODER_GPIO_config(void)
{
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	gpioInitStruct.Alternate = GPIO_AF2_TIM5;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);
}

/*
 * @brief TIM5 ENCLUDER configuration
 */
_Bool tim_TIM5_ENCODER_config(void)
{
	__HAL_RCC_TIM5_CLK_ENABLE();
	htim5.Instance = TIM3;
	htim5.Init.Prescaler = 65536 - 1;
	htim5.Init.Period = 0;
	htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim5.Init.CounterMode = TIM_COUNTERMODE_UP ;
	if(HAL_TIM_Base_Init(&htim5) != HAL_OK)
	{
		return false;
	}
	//Clock source configuration
	TIM_ClockConfigTypeDef clockSrcConfig = {0};
	clockSrcConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if(HAL_TIM_ConfigClockSource(&htim5, &clockSrcConfig) != HAL_OK)
	{
		return false;
	}
	//ENCOUDER
	TIM_Encoder_InitTypeDef encouderConfig = {0};
	encouderConfig.EncoderMode = TIM_ENCODERMODE_TI1;
	encouderConfig.IC1Polarity = TIM_ENCODERINPUTPOLARITY_RISING;
	encouderConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	encouderConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	encouderConfig.IC1Filter = 4;
	encouderConfig.IC2Polarity = TIM_ENCODERINPUTPOLARITY_RISING;
	encouderConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	encouderConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	encouderConfig.IC2Filter = 4;
	if(HAL_TIM_Encoder_Init(&htim5, &encouderConfig) != HAL_OK)
	{
		return false;
	}
	return true;
}
