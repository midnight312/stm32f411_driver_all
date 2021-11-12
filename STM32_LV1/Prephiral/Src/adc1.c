#include "adc1.h"

/**
 * @brief ADC gpio PIN : PA0, PA1, PA2
 */
void adc_GPIO_config(void)
{
	//Enable PORTA clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//PA0
	//PA1
	//PA2
	GPIOA->MODER &= ~(0x3FUL << 0);
	GPIOA->MODER |= 0x3FUL << 0;
}

/**
 * @brief ADC single Chanel configuartion
 */
void adc_singleConfig(ADC_SingleSellect_e channel)
{
	//Enable clock ADC
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//Right Alignment right
	ADC1->CR2 &= ~(ADC_CR2_ALIGN);
	//Single conversion
	ADC1->CR2 &= ~(ADC_CR2_CONT);
	//Software triger
	ADC1->CR2 |= ADC_CR2_SWSTART;
	//Same time to
	//PA0, PA1 AND PA2
	ADC1->SMPR2 &= ~(0x1FF << 0);
	ADC1->SMPR2 |= ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP1_2 | ADC_SMPR2_SMP2_2;
	//No off conversion = 1
	ADC1->SQR1 &= ~(ADC_SQR1_L);
	//Rank chanel
	ADC1->SQR3 = channel;
	//Power up ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	//Wait ADC ready
	for(uint8_t i;i < 36;i++);
}

/**
 * @brief ADC start SWSTART
 */
void adc_start(void)
{
	ADC1->SR = 0;
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC1->CR2 |= ADC_CR2_SWSTART;
}

/**
 * @brief ADC stop
 */
void adc_stop(void)
{
	ADC1->SR = 0;
	ADC1->CR2 &= ~(ADC_CR2_SWSTART);

}

/**
 * @brief ADC Poll end of conversion
 */
_Bool adc_pollEndOffConversion(uint32_t timeout)
{
	uint32_t startTick = rcc_msGetSysTick();
	while((ADC1->SR & ADC_SR_EOC) != 0)
	{
		if(rcc_msGetSysTick() - startTick > timeout)
		{
			return 0;
		}
	}
	return 1;
}

/**
 * @brief read ADC
 */
uint16_t adc_readValue(void)
{
	return (ADC1->DR) & 0xFFF;
}

/**
 * @brief enable/disable Interrupt ADC
 */
void adc_Enable_Interrupt(void)
{
	//Enable EOCIE
	ADC1->CR1 |= ADC_CR1_EOCIE;
	//ADC NVIC interrupt
	NVIC_EnableIRQ(ADC_IRQn);
}
void adc_Disable_Interrupt(void)
{
	//Disable EOCIE
	ADC1->CR1 &= ~(ADC_CR1_EOCIE);
	//ADC NVIC interrupt
	NVIC_DisableIRQ(ADC_IRQn);
}


















