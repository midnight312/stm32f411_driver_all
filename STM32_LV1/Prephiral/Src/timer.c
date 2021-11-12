#include "timer.h"

/**
 * @brief Timer2 delay config
 */
void tim_TIM2_delayConfig(void)
{
	//Enable clock for timer2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//Count up
	TIM2->CR1 |= (TIM_CR1_DIR);
	//One pulse mode
	TIM2->CR1 |= (TIM_CR1_OPM);
	//Mode-->reset
	TIM2->CR2 &= ~(TIM_CR2_MMS);
	//Prescalar 10KHZ
	TIM2->PSC = 0;
    //Prior
	TIM2->ARR = 9600 - 1;
	//UEV only overflow
	TIM2->CR1 |= TIM_CR1_URS;
}

/**
 * @brief Timer 2 delay ms
 */
void tim_TIM2_delayMs(uint32_t ms)
{
		//Reset CNT
		TIM2->CNT = 0;
		TIM2->PSC = (ms*10) - 1;
		//Enable timer2
		TIM2->CR1 |= 0x01;
		while(!(TIM2->SR & TIM_SR_UIF));
		TIM2->SR &= 0;
}

/**
 * @brief Tim2 priodic
 */
void tim_TIM2_priodicConfig(uint32_t ms)
{
	//Clear Flag
	TIM2->SR = 0;
	//Enable clock for timer2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//Count up
	TIM2->CR1 &= ~(TIM_CR1_DIR);
	//Priodic
	TIM2->CR1 &= ~(TIM_CR1_OPM);
	//Mode-->reset
	TIM2->CR2 &= ~(TIM_CR2_MMS);
	//Prescalar 10KHZ
	TIM2->PSC = 9600 - 1;
	//Prior
	TIM2->ARR = (ms*10) - 1;
	//UEV only overflow
	TIM2->CR1 |= TIM_CR1_URS;
	//Enable priodic
	TIM2->DIER |= TIM_DIER_UIE;
	//Enable NVIC
	NVIC_EnableIRQ(TIM2_IRQn);
	//Enable tricgger
	//TIM2->DIER |= TIM_DIER_TIE;
	//Start delay Priodic
	TIM2->CR1 |= 0x01;
}

/**
 * @brief Congiguration TIM2_CH2 -->PA1
 */
void tim_TIM2_CH2N_config(void)
{
	//Enable clock GPIOA
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN);
	//Alternate mode - Push-Pull - LOW Speed
	GPIOA->MODER &= ~(GPIO_MODER_MODE1);
	GPIOA->MODER |= (GPIO_MODER_MODE1_0);
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT1);
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED1);
	//Alternate AF1
	GPIOA->AFR[0] &= ~(GPIO_AFRL_AFRL1);
	GPIOA->AFR[0] |= (GPIO_AFRL_AFRL1_0);
	SYSCFG->EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI0_PA);
}

/**
 * @brief TIM2 output compare (OC) configuration
 */
void tim_TIM2_OC_config(uint32_t ms)
{
	//Clear Flag
	TIM2->SR = 0;
	//Enable clock for timer2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//Count up
	TIM2->CR1 &= ~(TIM_CR1_DIR);
	//Priodic
	TIM2->CR1 &= ~(TIM_CR1_OPM);
	//Mode-->reset
	TIM2->CR2 &= ~(TIM_CR2_MMS);
	//Prescalar 10KHZ
	TIM2->PSC = 9600 - 1;
	//Prior
	TIM2->ARR = (ms*10) - 1;
	//UEV only overflow
	//TIM2->CR1 |= TIM_CR1_URS;

	/* Output compare chanel 2 Tim2 */
	//Disable OC
	TIM2->CCER = 0;
	//Set CH2N as output
	TIM2->CCMR1 &= ~(TIM_CCMR1_CC2S);
	//Toggle output
	TIM2->CCMR1 &= ~(TIM_CCMR1_OC2M);
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_1;
	//Polarity
	TIM2->CCER &= ~(TIM_CCER_CC2NP);
	//Counter value to toggle out
	TIM2->CCR2 = 10;
	//
	TIM2->CCMR1 &= ~(TIM_CCMR1_OC2PE);
	TIM2->CCER &= ~(TIM_CCER_CC2P);
	//Enable CH2N
	TIM2->CCER |= TIM_CCER_CC2E;
	//Slave control reset
	TIM2->SMCR = 0;
	//Enable MOE
	//Enable tim2
	TIM2->CR1 |= 0x01;
}
