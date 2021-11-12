#ifndef _GPIO_H
#define _GPIO_H

#include "main.h"

//define LED
#define LED3  13
#define LED4  12
#define LED5  14
#define LED6  15

/*
 * @brief LED GPIO configuration PD12( LED4 ), PD13( LED3 ), PD14( LED5 ), PD15( LED6 )
 */
void gpio_LED_Config(void);

/*
 * @brief Write/Toggle function
 */
void gpio_LED_Write(_Bool state,uint8_t LED_number);
void gpio_LED_Toggle(uint8_t LED_number,uint32_t delay);

/*
 * @brief BUTTON GPIO configuration B1 (PA0)
 */
void gpio_PB_Config(void);

/*
 * Get Status Button B1
 */
_Bool gpio_PB_read(void);


















#endif /* GPIO_H */
