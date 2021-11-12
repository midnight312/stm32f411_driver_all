#ifndef _RCC_H
#define _RCC_H

#include "main.h"

/*
 *@brief configure HSE
 */
void rcc_HSE_config(void);

/*
 * @grief configure SysTick
 */
void rcc_SysTick_config(uint32_t arr);

/*
 * @brief Increment msTick
 */
void rcc_msIncSysTick(void);

/*
 * @brief Increment msTick
 */
uint32_t rcc_msGetSysTick(void);

/*
 * @brief Increment msTick
 */
void ms_Delay(uint32_t ms);










#endif /* _RCC_H */
