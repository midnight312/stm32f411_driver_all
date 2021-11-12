/*
 * exti.c
 *
 *  Created on: Aug 13, 2021
 *      Author: thanh
 */

#ifndef SRC_EXTI_C_
#define SRC_EXTI_C_

#include "exti.h"

/*
 * Button EXTI configuration
 */
void exti_BP_EXTI(void)
{
	//Configuraton PA0 as input floating
	//Enable from SYSCFG
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;
	//Unbloock interrupt mark
	EXTI->IMR |= EXTI_IMR_IM0;
	//Set rising edge only
	EXTI->RTSR |= EXTI_RTSR_TR0;
	//Set priority
	NVIC_SetPriority(EXTI0_IRQn,0);
	//Enable interrupt
	NVIC_EnableIRQ(EXTI0_IRQn);
}

#endif /* SRC_EXTI_C_ */
