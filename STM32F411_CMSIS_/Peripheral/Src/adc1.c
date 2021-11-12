/*
 * adc1.c
 *
 *  Created on: Aug 19, 2021
 *      Author: thanh
 */


#include "adc1.h"

/*
 * @breif ADC GPIO Pin: PA1-POT PA2-X PA3-Y
 */
void adc_GPIO_config(void)
{
	//Enable Clock GPIOA
	RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Configuaration analog mode
	GPIOA->MODER &= ~(0x3FUL << 2);
	GPIOA->MODER |= 0x3FUL << 2;
}

/*
 * @brief ADC single Channel config
 */
void adc_singleConfig(ADC_singleSelect_e channel)
{
	//Enable Clock ADC
	RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//Right Align
	ADC1->CR2 &= ~ADC_CR2_ALIGN;
	//Single conversion
	ADC1->CR2 &= ~ADC_CR2_CONT;
	//Software trigger
	ADC1->CR2 &= ~ADC_CR2_EXTSEL;
	//Same time to
	ADC1->SMPR2 &= ~(0x92UL << 3);
	ADC1->SMPR2 |= 0X92 << 3;
	//No of conversion = 1
	ADC1->SQR1 &= ~(ADC_SQR1_L);
	//Rank chanel
	ADC1->SQR3 = channel;
	//Pown up ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	//Wait for ADC stalibize
	for(uint32_t i = 0;i<=36;i++);
}

/*
 * @brief ADC Start-SWSTART
 */
void adc_start()
{
	ADC1->SR = 0;
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC1->CR2 |= ADC_CR2_SWSTART;
}

/*
 * @brief ADC Stop
 */
void adc_stop()
{
	ADC1->CR2 &= ~ADC_CR2_SWSTART;
}

/*
 * @brief ADC Poll for end conversion
 */
_Bool adc_pollForEndConversion(uint32_t msTimeOut)
{
	uint32_t startTick = rcc_msGetTicks();
	while(ADC1->SR & 0x02UL == 0)
	{
		if(rcc_msGetTicks() - startTick > msTimeOut) return false;
	}
	return true;
}

/*
 * @breif ADC read value
 */
uint16_t adc_readValue(void)
{
	return (ADC1->DR & 0xFFF);
}

/*
 * @breif ADC enable/disabel Interrupt
 */
void adc_enableEOC_IT()
{
	//Enable EOIE
	ADC1->CR1 |= ADC_CR1_EOCIE;
	//Enable NVIC interrupt
	NVIC_EnableIRQ(ADC_IRQn);
}

void adc_disableEOC_IT()
{
	//Disable EOIE
	ADC1->CR1 &= ~ADC_CR1_EOCIE;
	//Disable NVIC interrupt
	NVIC_DisableIRQ(ADC_IRQn);
}

/*
 * @breif ADC Multil-Channel Configuration
 */
void adc_multiChanel_config(void)
{
	//Enable ADC1 clock
	RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//Right align
	ADC1->CR2 &= ~ADC_CR2_ALIGN;
	//Sample time
	ADC1->SMPR2 &= ~(0x92UL << 3);
	ADC1->SMPR2 |= 0X92 << 3;
	//Sortware trigger
	ADC1->CR2 &= ~ADC_CR2_EXTSEL;
	//Sequencer
	//Rank 1 PA1 channel
	ADC1->SQR3 |= 1UL << 0;
	//Rank 2 PA2 channel
	ADC1->SQR3 |= 2UL << (0 + 5*1);
	//Rank 3 PA3 channel
	ADC1->SQR3 |= 3UL << (0 + 5*2);
	//No, of conversion
	ADC1->SQR1 &= ~ADC_SQR1_L;
	ADC1->SQR1 |= ADC_SQR1_L_2;  //Three conversion
	//Enable scan mode
	ADC1->CR1 |= ADC_CR1_SCAN;
	//Enable DMA-ADC register
	ADC1->CR2 |= ADC_CR2_DMA;
	//Signe conversion
	ADC1->CR2 &= ~ADC_CR2_CONT;
	//Pown up ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	//Wait for ADC stalibize
	for(uint32_t i = 0;i<=36;i++);
}

/*
 * @breif ADC Multil-Channel DMA Configuration
 */
void adc_multichanel_DMA_config(uint16_t *adcBuffer)
{
	//DMA2 Stream 0- Channel 0
	//Enable DMA1 clock
	RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	//Clear DMA1 Stream 0 all flag
	DMA2->LISR &= ~(0x3BUL << 0);
	//Dissable DMA1 Stream0
	DMA2_Stream0->CR &= ~DMA_SxCR_EN;
	//Prephireal Address --> DMA_DR
	DMA2_Stream0->PAR = (uint32_t)&(ADC1->DR);
	//Memory Address --> adc_array[3] circle adc_array[0]
	DMA2_Stream0->M0AR = (uint32_t)adcBuffer;
	//no, of tranfer
	DMA2_Stream0->NDTR = 3;
	//Circular / Nomal
	DMA2_Stream0->CR |= DMA_SxCR_CIRC;
	//Sellect DMA1 Stream0 Channel 0
	DMA2_Stream0->CR &= ~DMA_SxCR_CHSEL;
	//Enalble Memory increment
	DMA2_Stream0->CR |= DMA_SxCR_MINC;
	//Dissable Prephiral increment
	DMA2_Stream0->CR &= ~DMA_SxCR_PINC;
	//Size ADC 12 bit, Size Prephiral 16 bit, Size Memory 16 bit
	DMA2_Stream0->CR &= ~DMA_SxCR_MSIZE;
	DMA2_Stream0->CR |= DMA_SxCR_MSIZE_0;
	DMA2_Stream0->CR &= ~DMA_SxCR_PSIZE;
	DMA2_Stream0->CR |= DMA_SxCR_PSIZE_0;
	//Folow control
	DMA2_Stream0->CR &= ~DMA_SxCR_PFCTRL;
	//Sellect Priority
	DMA2_Stream0->CR &= ~DMA_SxCR_PL;
	//Direction = Prephiral to Memory
	DMA2_Stream0->CR &= ~DMA_SxCR_DIR;
	DMA2_Stream0->CR |= DMA_SxCR_DIR_0;
	//Dissable double mode
	DMA2_Stream0->CR &= ~DMA_SxCR_DBM;
	//Enable DMA
	DMA2_Stream0->CR |= DMA_SxCR_EN;
	//Enable tranfer Complete Inrerrupt DMA
	DMA2_Stream0->CR |= DMA_SxCR_TCIE;
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

/*
 * @brief ADC Analog Watdog configuration
 * @prama lowThreshod/highThreshold 0-4095
 */
void adc_AWD_config(uint8_t channel, uint16_t lowThreshold, uint16_t highThreshold)
{
	//Set threshold register
	ADC1->LTR = lowThreshold;
	ADC1->HTR = highThreshold;
	//Select channel
	ADC1->CR1 = channel;
	//Enable AWD interrupt
	ADC1->CR1 |= ADC_CR1_AWDIE;
	//AWD single channel
	ADC1->CR1 |= ADC_CR1_AWDSGL;
	//AWD Regular channel
	ADC1->CR1 &= ~ADC_CR1_JAWDEN;
	ADC1->CR1 |= ADC_CR1_AWDEN;
	//Enale ADC1 interrupt --> NVIC
	NVIC_EnableIRQ(ADC_IRQn);
}

/*
 * @brief ADC1 Temperation
 */
uint16_t adc_Temperature(void)
{
	//Enable Clock ADC
	RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//Right Align
	ADC1->CR2 &= ~ADC_CR2_ALIGN;
	//Single conversion
	ADC1->CR2 &= ~ADC_CR2_CONT;
	//Enable Temperature senser
	ADC->CCR |= ADC_CCR_TSVREFE;
	//ADC Clock
	ADC->CCR &= ~ADC_CCR_ADCPRE;
	//Software trigger
	ADC1->CR2 &= ~ADC_CR2_EXTSEL;
	//Same time to
	ADC1->SMPR2 &= ~(0x7UL << 3);
	ADC1->SMPR2 |= 0x7UL<< 3;
	//No of conversion = 1
	ADC1->SQR1 &= ~(ADC_SQR1_L);
	//ADC1->SQR1 |= ADC_SQR1_L_2;
	//Rank chanel
	ADC1->SQR3 = 18 << 0;
	//Pown up ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	//Wait for ADC stalibize
	for(uint32_t i = 0;i<=36;i++);
}
