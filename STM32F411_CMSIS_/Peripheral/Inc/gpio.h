/*
 * gpio.h
 *
 *  Created on: Aug 12, 2021
 *      Author: thanh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

#define LED_GREEN 12
#define LED_ORANG 13
#define LED_RED   14
#define LED_BLUE  15

#define GPIO_PIN_SET    1
#define GPIO_PIN_RESET  0

/*
 * @brief GPIO config pin LED PD12-15
 */
void gpio_LED_config(void);
/*
 * @brief Write stae to the LED
 */
void gpio_LED_write(uint8_t LED_PIN,uint8_t state);

/*
 * @brief Toggle LED
 */
void gpio_LED_toggle(uint8_t LED_PIN, uint32_t delay);

/*
 * @brief Display LED
 */
void gpio_LED_display(void);

/*
 * @grief GPIO configuratin button B1 PA0
 */
void gpio_BUTTON_config(void);

/*
 * @brief GPIO read BUTTON B1
 */
_Bool gpio_BUTTON_read();

/*
 * @brief write state to the port and pin
 */
void gpio_WritePin(GPIO_TypeDef *port,uint8_t pin, uint8_t state);


#endif /* INC_GPIO_H_ */
