/*
 * uart.h
 *
 *  Created on: Aug 10, 2021
 *      Author: thanh
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "main.h"

/*
 * @brief UART GPIO configuration
 */
void usart_USART1_GPIO_config(void);

/*
 * @brief UART configuration
 */
void usart_USART1_config(void);

/*
 * @brief UART1 transmit
 */
_Bool usart_USART1_transmit(uint8_t *data,uint8_t len, uint32_t timeOut);

/*
 * @brief UART1 receive
 */
_Bool usart_USART1_receive(uint8_t *data,uint8_t len, uint32_t timeOut);

/*
 * @brief UART1 DMA Configuratin
 */
void usart_USART1_DMA_config(void);

/*
 * @brief UART1 DMA Transmit
 */
void usart_USART1_DMA_transmit(uint8_t *data,uint8_t len);

/*
 * @brief UART1 DMA receive
 */
void usart_USART1_DMA_receive(uint8_t *data,uint8_t len);

/*
 * @brief UART1 interrupt Transmits
 */
_Bool usart_USART1_IT_transmit(uint8_t *data,uint8_t len);

/*
 * @brief UART1 interrupt Receive
 */
_Bool usart_USART1_IT_receive(uint8_t *data,uint8_t len);

#endif /* INC_USART_H_ */
