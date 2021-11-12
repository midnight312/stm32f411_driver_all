/*
 * gpio.h
 *
 *  Created on: Jun 21, 2021
 *      Author: thanh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

/*
 * @brief GPIO configuration
 */
void gpio_LED_config(void);

/*
 * @brief LEDs write/toggle
 */
void gpio_LED_write(_Bool state);
void gpio_LED_toggle(void);

/*
 * @brief button configuration
 */
void gpio_PB_config(void);

_Bool gpio_PB_read(void);

#endif /* INC_GPIO_H_ */
