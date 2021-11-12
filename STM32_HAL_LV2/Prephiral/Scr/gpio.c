/*
 * gpio.c
 *
 *  Created on: Jun 21, 2021
 *      Author: thanh
 */
#include "gpio.h"


/*
 * @brief GPIO configuration
 */
void gpio_LED_config(void)
{
	//LED GREEEN - PD12
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOD_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_12;
	gpioInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOD, &gpioInitStruct);
}

/*
 * @brief LEDs write/toggle
 */
void gpio_LED_write(_Bool state)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, state);
}
void gpio_LED_toggle(void)
{
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
}

/*
 * @brief button configuration
 */
void gpio_PB_config(void)
{
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_0;
	gpioInitStruct.Mode = GPIO_MODE_INPUT;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);
}

_Bool gpio_PB_read(void)
{
	return (_Bool)HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}
