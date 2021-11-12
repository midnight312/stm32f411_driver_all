/*
 * rcc.c
 *
 *  Created on: Aug 9, 2021
 *      Author: thanh
 */


#include "rcc.h"

static __IO uint32_t msTick = 0;

/*
 * HSE Configuaration
 */
void rcc_HSE_Config(void)
{
	/*
	 * Configuration Parameter --> STM32F411 Clock tree
	 *
	 * HSE = 8MHZ
	 * PLLM = 4
	 * PLLN = 100
	 * PLLP = 2
	 * Cotex prescalar = 1
	 * --> Clock 100 MHZ
	 *
	 * APB1 prescalar = 2 --> 50 MHZ
	 * APB2 prescalar = 1 --> 100 MHZ
	 * ADC prescalar  = 1 --> 100 MHZ
	 */
	uint8_t timeOut = 0xFF;
	/* Dissable interrupt */
	RCC->CIR = 0;
	//Dissable HSI
	RCC->CR &= ~(RCC_CR_HSION);
	//Dissable PLL and Wait for it dissable
	RCC->CR &= ~RCC_CR_PLLON;
	while(((RCC->CR & RCC_CR_PLLON) == 0) && timeOut > 0)
	{
		timeOut--;
	}
	timeOut = 0xFF;

	/* PLL configuration */
	//PLLM

	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_2;
	//PLLN
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_6 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_2;
	//PLLP
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP);
	/* HSE Oscillator */
	//Enable HSE clock
	RCC->CR &= ~RCC_CR_HSEON;
	RCC->CR |= RCC_CR_HSEON;
	//Enable LSI clock
	RCC->CR |= RCC_CR_HSION;
	//Wait for it stalibize
	while(((RCC->CR & RCC_CR_HSERDY) == 0) && timeOut > 0)
	{
		timeOut--;
	}
	//Enable LSI clock
	RCC->CR |= RCC_CR_HSION;
	//Wait for it stalibize
	timeOut = 0xFF;
	while(((RCC->CR & RCC_CR_HSIRDY) == 0) && timeOut > 0)
	{
		timeOut--;
	}
	//Sellect HSE as PLL source
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC_HSE;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	//Enable PLL
	RCC->CR &= ~RCC_CR_PLLON;
	RCC->CR |= RCC_CR_PLLON;
	//Wait for it stalibize
	timeOut = 0xFF;
	while(((RCC->CR & RCC_CR_PLLRDY) == 0) && timeOut > 0)
	{
		timeOut--;
	}
	/* Flash prefetch and wait state */
	//4WS =< 64 MHZ
	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	FLASH->ACR |= FLASH_ACR_LATENCY_3WS;
	//Enable prefetch buffer
	FLASH->ACR |= FLASH_ACR_PRFTEN;
	//Sellect PLL as main system clock
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |= RCC_CFGR_SW_1;
	//Wait for PLL clock active source
	timeOut = 0xFF;
	while(((RCC->CFGR & RCC_CFGR_SWS) >> 2 != 0x2UL) && timeOut > 0)
	{
		timeOut--;
	}

	/* Peripherals clock setup */
	//AHB
	RCC->CFGR &= ~(RCC_CFGR_RTCPRE);
	//APB2
	RCC->CFGR &= ~(RCC_CFGR_PPRE2);
	//APB1
	RCC->CFGR &= ~(RCC_CFGR_PPRE1);
	RCC->CFGR |= RCC_CFGR_PPRE1_2;
}

/*
 * @brief Systick configuration
 */
void rcc_SYSTICk_config(uint32_t arr)
{
	//Reset control register
	SysTick->CTRL = 0;
	//Set the reload value
	SysTick->LOAD = arr - 1;
	//Set priority systick interrupt (NVIC)
	NVIC_SetPriority(SysTick_IRQn,0);
	//Reset systick value to 0
	SysTick->VAL = 0;
	//Enable NVIC
	NVIC_EnableIRQ(SysTick_IRQn);
	//Enable systick from control register
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

}

/*
 * @brief Increment ms Tick
 */
void rcc_msTicks(void)
{
	msTick++;
}

/*
 * @brief Get ms stick
 */
uint32_t rcc_msGetTicks(void)
{
	return msTick;
}

/*
 * @brief ms Delay
 */
void rcc_msDelay(uint32_t ms)
{
	uint32_t startTicks = rcc_msGetTicks();
	while(rcc_msGetTicks() - startTicks < ms);
	msTick = 0;
}

/*
 * @brief SysTick Interrupt Callback
 */
void SysTick_Handler(void)
{
	NVIC_ClearPendingIRQ(SysTick_IRQn);
	rcc_msTicks();
}
