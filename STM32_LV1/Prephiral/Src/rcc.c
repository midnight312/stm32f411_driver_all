#include "rcc.h"

//ms stick
static __IO uint32_t msTicks = 0;

void rcc_HSE_config(void)
{
	/*
	 *
	 * Configuration HSE parameter --> STM32F411 clock tree
	 * system clock --> 96MHZ
	 * prephiral clock --> 48 MHZ
	 *
	 * HSE = 8MHZ
	 * PLL_M = 8
	 * PLL_N = 192
	 * PLL_P = 2
	 * PLL_Q = 4
	 * APB1 pascalar = 2 --> 48MHZ
	 * APB2 pascalar = 1 --> 96MHZ
	 *
	 * I2S Configuration --> 100MHZ
	 *
	 * AHB = 96 MHZ
	 * PLLI2S_M = 8
	 * PLLI2S_N = 200
	 * PLLI2S_R = 2
	 *
	 */

	uint32_t timeout = 0;

	//Dissable all interrupt
	RCC->CIR = 0x00000000UL;
	//Dissable internal high speed and wait HSI dissable
	RCC->CR &= ~(RCC_CR_HSION);
	timeout = 0xFF;
	//while((RCC->CR & RCC_CR_HSIRDY ) && (timeout > 0)){ timeout--;};
	//Dissable PLL and wait PLL dissable
	RCC->CR &= ~(RCC_CR_PLLON);
	timeout = 0xFFFF;
	while((RCC->CR & RCC_CR_PLLRDY) && (timeout > 0)){ timeout--;};
	//PLL_M = 8
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_3;
	//PLL_N = 192
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |= 0xC0 << RCC_PLLCFGR_PLLN_Pos;
	//PLL_P = 2
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP);
	//PLL_Q = 4
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLQ);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLQ_2;

	/* HSE Osillator Enable */
	//Enable HSE Ociallator and wait ready
	RCC->CR &= ~(RCC_CR_HSEON);
	RCC->CR |= RCC_CR_HSEON;
	timeout = 0xFF;
	while(((RCC->CR & RCC_CR_HSERDY) == 0) & (timeout > 0)){ timeout--;};
	//Select HSE as PLL source
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLSRC);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	//Enable PLL and wait PLL ready
	RCC->CR |= RCC_CR_PLLON;
	timeout = 0xFFF;
	while(((RCC->CR & RCC_CR_PLLRDY) == 0) && (timeout > 0)){ timeout--;};

	/* Flash prefetch and wait state */
	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	FLASH->ACR |= FLASH_ACR_LATENCY_3WS;
	FLASH->ACR |= FLASH_ACR_PRFTEN;    //ENABLE prefetch buffer
	//Select PLL as main system clock and wait ready
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |= RCC_CFGR_SW_1;
	timeout= 0xFF;
	while(((RCC->CFGR & RCC_CFGR_SWS) >> 2 != 0x2UL ) && (timeout > 0)){ timeout--;};


	//Prephiral clock setup
	//APB1 prescaler
	RCC->CFGR &= ~(RCC_CFGR_PPRE2);
	//APB2 prescaler
	RCC->CFGR &= ~(RCC_CFGR_PPRE1);
	RCC->CFGR |= RCC_CFGR_PPRE2_1;

}

/*
 *@grief configure SysTick
 */
void rcc_SysTick_config(uint32_t arr)
{
	//Reset control register
	SysTick->CTRL = 0;
	//Set reload value
	SysTick->LOAD = arr - 1;
	//Priority systick interrupt (NVIC)
	NVIC_SetPriority(SysTick_IRQn, 0);
	//Reset systick value to 0
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/*
 * @brief Increment msTick
 */
void rcc_msIncSysTick(void)
{
	msTicks++;
}

/*
 * @brief Increment msTick
 */
uint32_t rcc_msGetSysTick(void)
{
	return msTicks;
}

/*
 * @brief Increment msTick
 */
void ms_Delay(uint32_t ms)
{
	uint32_t startTick = rcc_msGetSysTick();
	while((rcc_msGetSysTick() - startTick) < ms);
	msTicks = 0;
}

/*
 * @brief SysTick Interrupt Callback
 */
void SysTick_Handler(void)
{
	NVIC_ClearPendingIRQ(SysTick_IRQn);
	rcc_msIncSysTick();
}
