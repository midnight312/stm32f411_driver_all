#include "exti.h"

/*
 * @brief Button EXTI configuration
 */
void exti_PB_EXTI(void)
{
	//Configuration PA0 as Input Floating
	//Enable from SYSCFG
	SYSCFG->EXTICR[0] = 0;
	//Dissable mark
	EXTI->IMR |= EXTI_IMR_IM0;
	//Enable Rising edge only
	EXTI->RTSR |= EXTI_RTSR_TR0;
	EXTI->FTSR &= ~(EXTI_FTSR_TR0);
	//Set priority
	NVIC_SetPriority(EXTI0_IRQn,5);
	//Enable interrupt
	NVIC_EnableIRQ(EXTI0_IRQn);
}
