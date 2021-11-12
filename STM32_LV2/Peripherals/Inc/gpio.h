/*
 * gpio.h
 *
 *  Created on: Jun 21, 2021
 *      Author: thanh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

//Define Pin Led on board
#define LED_GREEN   GPIO_PIN_12
#define LED_ORANGE  GPIO_PIN_13
#define LED_3       GPIO_PIN_14
#define LED_4	    GPIO_PIN_15


/*
 * @brief GPIO configuration
 */
void gpio_LED_config(void);

/*
 * @brief LEDs write/toggle
 */
void gpio_LED_write(uint32_t LED_PIN,_Bool state);
void gpio_LED_toggle(uint32_t LED_PIN);

/*
 * @brief button configuration
 */
void gpio_PB_config(void);

_Bool gpio_PB_read(void);

#endif /* INC_GPIO_H_ */
