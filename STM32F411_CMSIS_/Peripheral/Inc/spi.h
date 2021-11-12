/*
 * spi.h
 *
 *  Created on: Aug 30, 2021
 *      Author: thanh
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "main.h"

/*
 * @brief SPI1 GPIO configuration --> LCD ILI9341
 * SPI1 PA6-MISO PA7-MOSI PA5-SCK PB6-CS PC7-DC
 * SPI2 PC2-DO PC3-DIN PB5-TS_CS PB10-SCK
 * PA9-RST
 */
void spi_SPI1_GPIO_config(void);

/*
 * @brief SPI prephiral configuration
 */
void spi_SPI1_config(void);

/*
 * @brief SPI transmit
 */
_Bool spi_SPI1_transmit(uint8_t *pData, uint8_t len, uint32_t timeOut);

/*
 * @brief SPI receive
 */
_Bool spi_SPI1_receive(uint8_t *pData, uint8_t len, uint32_t timeOut);

/*
 * @brief SPI DMA configuration
 */
void spi_SPI1_DMA_config(void);

/*
 * @brief UART1 DMA Transmit
 */
void spi_SPI1_DMA_transmit(uint8_t *data,uint8_t len);

#endif /* INC_SPI_H_ */
