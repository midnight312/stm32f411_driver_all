/*
 * tim.c
 *
 *  Created on: Aug 21, 2021
 *      Author: thanh
 */

#include "tim.h"

/*
 * @brief TIM2 TRGG ADC configuration
 */
void tim_TIM2_config(void)
{
	//Enable TIM2 timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//Count up
	TIM2->CR1 &= ~TIM_CR1_DIR;
	//Periodic
	TIM2->CR1 &= ~TIM_CR1_OPM;
	//MODE TRGO
	TIM2->CR2 &= ~TIM_CR2_MMS;
	TIM2->CR2 |= TIM_CR2_MMS_1;
	//10HZ
	//Prescalar
	TIM2->PSC = 50000 - 1;
	//Period
	TIM2->ARR = 1000 - 1;
	//Update register on event
	TIM2->EGR = 1;
	//Start timer
	TIM2->CR1 |= TIM_CR1_CEN;
}

/*
 * @brief TIM3 delay configuration
 */
void tim_TIM3_delayConfig()
{
	//10000HZ
	//Enable clock tim3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	//Count up
	TIM3->CR1 &= ~TIM_CR1_DIR;
	//Prescalar
	TIM3->PSC = 0;
	//One pulse
	TIM3->CR1 |= TIM_CR1_OPM;
	//Period
	TIM3->ARR = 10000 - 1;
	//Mode reset
	TIM3->CR2 &= TIM_CR2_MMS;

}

/*
 * @brief TIM3 milisecon delay
 */
void tim_TIM3_msDelay(uint32_t msDelay)
{
	//Delay is ms
	TIM3->PSC = (msDelay*10 - 1);
	//Start TIM2
	TIM3->CR1 |= TIM_CR1_CEN;
	//Wait for delay elapse
	while(!(TIM3->SR & 0x01));
	//Clear TIM flag
	TIM3->SR &= ~0x01;
}

/*
 * @brief TIM2 periodic interrupt
 */
void tim_TIM3_periodicInterrupt(uint32_t msDelay)
{
	//10000HZ
	//Enable clock tim3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	//Count up
	TIM3->CR1 &= ~TIM_CR1_DIR;
	//Prescalar
	TIM3->PSC = 0;
	//One pulse
	TIM3->CR1 &= ~TIM_CR1_OPM;
	//Period
	TIM3->ARR = 10000 - 1;
	//Mode reset
	TIM3->CR2 &= TIM_CR2_MMS;

	//Clear update interrupt
	TIM3->CR1 |= TIM_CR1_CEN;
	//Enalbe update interrupt
	TIM3->DIER |= TIM_DIER_UDE;
	//Enable nvic interrupt
	NVIC_EnableIRQ(TIM3_IRQn);
}

/*
 * @brief configuration TIM5CH2 -->PA2
 */
void tim_TIM5_CH2N_GPIO_config()
{
	//Enable GPIOA
	RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Mode Altenane - Push - Pull - Low speek
	GPIOA->MODER |= (3 << 4);
	GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED2;
	//Altenate AF1
	GPIOA->AFR[0] &= ~(GPIO_AFRL_AFRL2);
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_1;
}

/*
 * @brief TIM5 Output Compare OC configuaration
 */
void tim_TIM5_OC_config(uint32_t msPeriod)
{
	//Enable TIM5
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	//Count up
	TIM5->CR1 &= ~TIM_CR1_DIR;
	//Prescalar
	TIM5->PSC = (msPeriod*10 - 1);
	//NO One pulse
	TIM5->CR1 &= ~TIM_CR1_OPM;
	//Period
	TIM5->ARR = 10000 - 1;
	//Mode reset
	TIM5->CR2 &= TIM_CR2_MMS;
	//Clear update interrupt
	TIM5->SR &= ~TIM_SR_UIF;

	/* Output compare channel - TIM5CH2N PA2 */
	//Dissable OC
	TIM5->CCER = 0;
	//Set CH2 as output
	TIM5->CCMR1 &= ~TIM_CCMR1_CC2S;
	//Toggle output
	TIM5->CCMR1 &= ~TIM_CCMR1_OC2M;
	TIM5->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	//Polatity
	TIM5->CCER &= ~TIM_CCER_CC2NP;
	//Counter value to toggle output
	TIM5->CCR2 = 10;
	//
	TIM5->CCMR1 &= ~(TIM_CCMR1_OC2PE);
	TIM5->CCER &= ~(TIM_CCER_CC2P);
	//Enable CH2N output
	TIM5->CCER |= TIM_CCER_CC2E;
	//Slave control reset
	TIM5->SMCR = 0;
	//Enable MOE
	//Enable TIM5
	TIM5->CR1 |= 0x01;
}

/*
 * @brief TIM5 PWM GPIO configuration CH3 PA3
 */
void tim_TIM5_PWM_GPIO_config(void)
{
	//Enable GPIOA
	RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Mode Altenane - Push - Pull - Low speek
	GPIOA->MODER |= (0x3FUL << 4);
	//GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED2;
	//Altenate AF1
	GPIOA->AFR[0] &= ~(GPIO_AFRL_AFRL2);
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_1;
}

/*
 * @brief TIM5 PWM configuratin configuration
 */
void tim_TIM5_PWM_config(void)
{
	/* CH2 CH3 AND CH4 */
	//Enable TIM5
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	//Count up
	TIM5->CR1 &= ~TIM_CR1_DIR;
	//Prescalar
	TIM5->PSC = 0;
	//NO One pulse
	TIM5->CR1 &= ~TIM_CR1_OPM;
	//Period
	TIM5->ARR = 10000 - 1;
	//Mode reset
	TIM5->CR2 &= TIM_CR2_MMS;
	//Clear update interrupt
	TIM5->SR &= ~TIM_SR_UIF;

	//Disable OC
	TIM5->CCER = 0;

	//CH1
	//Set mode output
	TIM5->CCMR1 &= ~TIM_CCMR1_CC2S;
	//PWM mode
	TIM5->CCMR1 &= ~TIM_CCMR1_OC2M;
	TIM5->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;
	//Polarity
	TIM5->CCER &= ~TIM_CCER_CC2P;
	//Set Pulse width - Duty circle
	TIM5->CCR2 = 0;

	//CH2
	//Set mode output
	TIM5->CCMR2 &= ~TIM_CCMR2_CC3S;
	//PWM mode
	TIM5->CCMR2 &= ~TIM_CCMR2_OC3M;
	TIM5->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;
	//Polarity
	TIM5->CCER &= ~TIM_CCER_CC3P;
	//Set Pulse width - Duty circle
	TIM5->CCR3 = 0;

	//CH3
	//Set mode output
	TIM5->CCMR2 &= ~TIM_CCMR2_CC4S;
	//PWM mode
	TIM5->CCMR2 &= ~TIM_CCMR2_OC4M;
	TIM5->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1;
	//Polarity
	TIM5->CCER &= ~TIM_CCER_CC4P;
	//Set Pulse width - Duty circle
	TIM5->CCR4= 0;

	//Enable channel 2, 3 and 4
	TIM5->CCER |= TIM_CCER_CC2E;
	TIM5->CCER |= TIM_CCER_CC3E;
	TIM5->CCER |= TIM_CCER_CC4E;

	//Start TIM5
	TIM5->CR1 |= 0x01;
}

/*
 * @brief RGB TIM5
 */
void tim_TIM5_RGB(uint8_t R, uint8_t G, uint8_t B)
{
	TIM5->CCR2 = (uint16_t)((TIM3->ARR + 0.0f)*(R/255.0f));
	TIM5->CCR3 = (uint16_t)((TIM3->ARR + 0.0f)*(G/255.0f));
	TIM5->CCR4 = (uint16_t)((TIM3->ARR + 0.0f)*(B/255.0f));
}
