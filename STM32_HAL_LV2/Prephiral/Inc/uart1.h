/*
 * uart1.h
 *
 *  Created on: Jun 17, 2021
 *      Author: thanh
 */

#ifndef INC_UART1_H_
#define INC_UART1_H_

#include "main.h"

extern UART_HandleTypeDef huart1;

/*
 * @brief UART1 GPIO Config
 */
void uart_UART1_GPIO_config(void);

/*
 * @brief UART1 Config
 */
_Bool uart_UAR1_config();

#endif /* INC_UART1_H_ */
