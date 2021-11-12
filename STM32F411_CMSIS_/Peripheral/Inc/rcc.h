/*
 * rcc.h
 *
 *  Created on: Aug 9, 2021
 *      Author: thanh
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "main.h"

/*
 * @brief HSE Configuaration
 */
void rcc_HSE_Config(void);

/*
 * @brief Systick configuration
 */
void rcc_SYSTICk_config(uint32_t arr);

/*
 * @brief Increment ms Tick
 */
void rcc_msTicks(void);

/*
 * @brief Get ms stick
 */
uint32_t rcc_msGetTicks(void);

/*
 * @brief ms Delay
 */
void rcc_msDelay(uint32_t ms);

/*
 * @brief SysTick Interrupt Callback
 */
void SysTick_Handler(void);

#endif /* INC_RCC_H_ */
