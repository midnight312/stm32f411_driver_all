#ifndef SPI_H
#define SPI_H
#include "main.h"

/*
 * @brief SPI GPIO configuration
 */
void spi_GPIO_config();

/*
 * @brief SPI configuration
 */
void spi_config();

/*
 * @brief SPI transmit
 */
_Bool spi_transmit(uint8_t *pData,uint8_t len, uint32_t timeout);

/*
 * @brief SPI receive
 */
_Bool spi_receive(uint8_t *pData,uint8_t len, uint32_t timeout);





#endif /* SPI_H*/
