/*
 * spi.h
 *
 *  Created on: Jun 26, 2021
 *      Author: thanh
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "main.h"

extern SPI_HandleTypeDef spi1Handle;

/*
 * @brief SPI1 GPIO configuration
 */
void spi_GPIO_config(void);

/*
 * @brief SPI1 configuration
 */
_Bool spi_config(void);

/*
 * @brief SPI1 CS1-RFID
 */
void spi_CS1_enable(void);
void spi_CS1_disable(void);

#endif /* INC_SPI_H_ */
