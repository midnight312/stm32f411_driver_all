#ifndef _UART_H_
#define _UART_H_

#include "main.h"

/**
 * @brief UART1 GPIO Configuration
 */
void uart_UART1_GPIO_config(void);

/**
 * @brief UART1 Configuration
 */
void uart_UART1_config(void);

/**
 * @brief UART transmit
 */
_Bool uart_UART1_transmit(uint8_t *data, uint8_t len, uint8_t timeout);

/**
 * @brief UART receive
 */
_Bool uart_UART1_receive(uint8_t *data, uint8_t len, uint8_t timeout);







#endif /* _UART_H_ */
