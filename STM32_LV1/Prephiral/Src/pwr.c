#include "pwr.h"

/**
 * @brief Enter sleep mode
 */
void pwr_enterSleep(void)
{
	//Dissable systick interrupt ( Avoid wake up the MCU)
	SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk);
	//Set-clear sleep exit ( clear is enable to sleep from exti)
	SCB->SCR &= ~(SCB_SCR_SLEEPONEXIT_Msk);
	//Clear Sleep Deep = Stop Mode
	SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
	//Put the device into sleep __WFI()
	__WFI();
	//On wakeup
	SysTick->CTRL |= (SysTick_CTRL_TICKINT_Msk);
}

/**
 * @brief Enter stop mode
 */
void pwr_enterStop(void)
{
	//Dissable systick interrupt ( Avoid wake up the MCU)
	SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk);
	//Clear sleep exit
	SCB->SCR &= ~(SCB_SCR_SLEEPONEXIT_Msk);
	//Set DEEP bit
	SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);
	//Clear PDDS on PWR
	PWR->CR &= ~(PWR_CR_PDDS);
	//Put device into low-power
	__WFI();
	//Resume systick interrupt
	SysTick->CTRL |= (SysTick_CTRL_TICKINT_Msk);
}

/**
 * @brief Enter standby mode
 */
void pwr_enterStandby(void)
{
	//Enable WAKEUP functionality
	PWR->CSR |= PWR_CSR_EWUP;
	//Disable systick interrupt
	SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk);
	//Set DEEP
	SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);
	//Set PDDR on PWR
	PWR->CR |= (PWR_CR_PDDS);
	//Clear sleep exit
	SCB->SCR &= ~(SCB_SCR_SLEEPONEXIT_Msk);
	//Clear standby flag
	PWR->CR |= PWR_CR_CSBF;
	//Clear WUF
	PWR->CSR |= (PWR_CSR_WUF);
	//Standby mode
	__WFI();
	//Wakeup -> reset
}
