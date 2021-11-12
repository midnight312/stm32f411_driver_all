/*
 * i2c.c
 *
 *  Created on: Jun 27, 2021
 *      Author: thanh
 */

#include "i2c.h"

/*
 * @brief I2C GPIO Configuration
 */
void i2c_GPIO_config(void)
{
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOB_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	gpioInitStruct.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &gpioInitStruct);
}

/*
 * @brief I2C configuration
 */
_Bool i2c_config(void)
{

}
