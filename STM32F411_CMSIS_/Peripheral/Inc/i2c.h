/*
 * i2c.h
 *
 *  Created on: Sep 8, 2021
 *      Author: thanh
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"

/*
 * @brief SPI GPIO configiguration
 */
void i2c_I2C1_GPIO_config(void);

/*
 * @brief I2C configuration
 */
_Bool i2c_I2C1_config(void);

/*
 * @brief I2C check address
 */
_Bool i2c_I2C1_isSlaveAddressExist(uint8_t addr, uint32_t timeOut);

/*
 * @brief I2C transmit (master)
 */
_Bool i2c_I2C1_masterTransmit(uint8_t addr,uint8_t *data, uint8_t len, uint32_t timeOut);

/*
 * @brief I2C receive (master)
 */
_Bool i2c_I2C1_receiveTransmit(uint8_t addr,uint8_t *data, uint8_t len, uint32_t timeOut);

#endif /* INC_I2C_H_ */
