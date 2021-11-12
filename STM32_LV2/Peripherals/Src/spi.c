/*
 * spi.c
 *
 *  Created on: Jun 26, 2021
 *      Author: thanh
 */

#include "spi.h"

SPI_HandleTypeDef spi1Handle;

/*
 * @brief SPI1 GPIO configuration
 */
void spi_GPIO_config(void)
{
	//PA4-NSS PA5-SCK PA6-MISO PA7-MOSI
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpioInitStruct.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Pull = GPIO_NOPULL;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	gpioInitStruct.Alternate = GPIO_AF5_SPI1;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);
}

/*
 * @brief SPI1 configuration
 */
_Bool spi_config(void)
{
	__HAL_RCC_SPI1_CLK_ENABLE();
	spi1Handle.Instance = SPI1;
	spi1Handle.Init.Mode = SPI_MODE_MASTER;
	spi1Handle.Init.Direction = SPI_DIRECTION_2LINES;
	spi1Handle.Init.DataSize = SPI_DATASIZE_8BIT;
	spi1Handle.Init.CLKPolarity = SPI_POLARITY_LOW;
	spi1Handle.Init.CLKPhase = SPI_PHASE_1EDGE;
	spi1Handle.Init.NSS = SPI_NSS_SOFT;
	spi1Handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
	spi1Handle.Init.FirstBit = SPI_FIRSTBIT_MSB;
	spi1Handle.Init.TIMode = SPI_TIMODE_DISABLE;
	spi1Handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	if(HAL_SPI_Init(&spi1Handle) != HAL_OK)
	{
		return false;
	}

	return true;
}

/*
 * @brief SPI1 CS1-RFID
 */
void spi_CS1_enable(void)
{
	//HAL_SPI
}


void spi_CS1_disable(void);
