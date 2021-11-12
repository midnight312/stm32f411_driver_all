#ifndef _TIMER_H
#define _TIMER_H

#include "main.h"

/**
 * @brief Timer2 delay config
 */
void tim_TIM2_delayConfig(void);

/**
 * @brief Timer 2 delay ms
 */
void tim_TIM2_delayMs(uint32_t ms);

/**
 * @brief Tim2 priodic
 */

void tim_TIM2_priodicConfig(uint32_t ms);

/**
 * @brief Congiguration TIM2_CH2 -->PA1    //error
 */
void tim_TIM2_CH2N_config(void);

/**
 * @brief TIM2 output compare (OC) configuration
 */
void tim_TIM2_OC_config(uint32_t ms);










#endif /* _TIMER_H */
