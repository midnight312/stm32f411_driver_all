/*
 * pwr.c
 *
 *  Created on: Sep 11, 2021
 *      Author: thanh
 */

#include "pwr.h"

/**
 * @brief Enter sleep mode
 */
void pwr_enterSleep(void)
{
	//Dissable systick interrupt
	SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
	//Clear sleep on exit
	SCB->SCR |= (SCB_SCR_SLEEPONEXIT_Msk);
	//Clear sleep deep
	SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
	//Enable wakeup
	SCB->SCR |= SCB_SCR_SEVONPEND_Msk;
	//Put the device into sleep __WFI();
	__WFI();
	//On wakeup --> Resume systick interrupt
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
}
