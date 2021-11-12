/*
 * uart.c
 *
 *  Created on: Aug 10, 2021
 *      Author: thanh
 */

#include "usart.h"

/*
 * @brief UART GPIO configuration
 */
void usart_USART1_GPIO_config(void)
{
	//PA15-TX PB7-RX
	//Enable clock GPIOA
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN);
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOBEN);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOBEN);
	//Config mode Alternate
	GPIOA->MODER &= ~(GPIO_MODER_MODE15);
	GPIOA->MODER |= GPIO_MODER_MODE15_1;
	GPIOB->MODER &= ~(GPIO_MODER_MODE7);
	GPIOB->MODER |= GPIO_MODER_MODE7_1;
	//Speed max
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED15_1 | GPIO_OSPEEDR_OSPEED15_0;
	//GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED10_1 | GPIO_OSPEEDR_OSPEED10_0;
	GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED7_1 | GPIO_OSPEEDR_OSPEED7_0;
	//MAP PA9 and PA10 to USART1
	GPIOA->AFR[1] |= GPIO_AFRH_AFRH7_0 | GPIO_AFRH_AFRH7_1 | GPIO_AFRH_AFRH7_2;
	GPIOB->AFR[0] |= GPIO_AFRH_AFRH7_0 | GPIO_AFRH_AFRH7_1 | GPIO_AFRH_AFRH7_2;
}

/*
 * @brief UART configuration
 */
void usart_USART1_config(void)
{
	//Disable all flag
	USART1->SR = 0;
	//Enable clock for usart1
	RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN;
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	//Enable USART
	USART1->CR1 &= ~USART_CR1_UE;
	USART1->CR1 |= USART_CR1_UE;
	//Dissable parity control
	USART1->CR1 &= ~(USART_CR1_PCE);
	//Word length 8 bit
	USART1->CR1 &= ~(USART_CR1_M);
	//Stopbit to 1
	USART1->CR2 &= ~(USART_CR2_STOP);
	//Dissable HW folow control
	USART1->CR3 &= ~(USART_CR3_RTSE);
	USART1->CR3 &= ~(USART_CR3_CTSE);
	//Dissable smart care
	USART1->CR3 &= ~(USART_CR3_SCEN);
	//Set baurate 115200
	USART1->BRR |= 54 << 4 | 4 << 0;
	//Clear something clk and lin
	USART1->CR2 &= ~(USART_CR2_LINEN | USART_CR2_CLKEN );
	USART1->CR3 &= ~(USART_CR3_HDSEL | USART_CR3_IREN);

	//Enable transmit
	USART1->CR1 |= USART_CR1_TE;
	//Enable receive
	USART1->CR1 |= USART_CR1_RE;
	//USART1->SR &= ~(USART_SR_TC);
}

/*
 * @brief UART1 transmit
 */
_Bool usart_USART1_transmit(uint8_t *data,uint8_t len, uint32_t timeOut)
{
	//Wait on TXE start transmit
	//Write to DR as TXE flag is high
	uint8_t dataIdx = 0;
	uint32_t startTick = rcc_msGetTicks();
	while(dataIdx<len)
	{
		if(USART1->SR & USART_SR_TXE) //Tx buffer empty
		{
			USART1->DR = data[dataIdx];
			dataIdx++;
		}
		else
		{
			if((rcc_msGetTicks() - startTick) > timeOut) return false;
		}
	}
	//Wait for busy flag
	while(USART1->SR & USART_SR_TC != 1)
	{
		if((rcc_msGetTicks() - startTick) > timeOut) return false;
	}
	//USART1->SR &= ~(USART_SR_TC);
	return true;
}


/*
 * @brief UART1 receive
 */
_Bool usart_USART1_receive(uint8_t *data,uint8_t len, uint32_t timeOut)
{
	uint8_t dataRemain = len;
	uint32_t startTick = rcc_msGetTicks();
	while(dataRemain > 0)
	{
		if(USART1->SR & USART_SR_RXNE) //TX EMPTY
		{
			*data++ = (uint8_t)(USART1->DR & 0xFF);
			dataRemain--;
		}
		else
		{
			if(rcc_msGetTicks() - startTick > timeOut) return false;
		}
	}
	return true;
}

/*
 * @brief UART1 DMA Configuratin
 */
void usart_USART1_DMA_config(void)
{
	//Enable UART DMA in UART
	USART1->CR3 |= USART_CR3_DMAR | USART_CR3_DMAT;
	//Enable DMA2 clock
	RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	//**TX channel 4 configuration -CH4 stream 7 DMA2
	//Dissable DMA for configuration register
	DMA2_Stream7->CR &= ~DMA_SxCR_EN;
	//Clear channel 4 flag
	DMA2->HISR &= ~(0xFUL << 24);
	//Prephiral address UART1->DR
	DMA2_Stream7->PAR = (uint32_t)&(USART1->DR);
	//Sellect chanel 4 DMA2 stream7
	DMA2_Stream7->CR |= DMA_SxCR_CHSEL_2;
	//Folow control
	DMA2_Stream7->CR &= ~DMA_SxCR_PFCTRL;
	//Sellect priority
	DMA2_Stream7->CR &= ~DMA_SxCR_PL;
	//DMA2_Stream7->CR |= DMA_SxCR_PL_1;
	//
	//Mode nomal/circular
	DMA2_Stream7->CR &= ~DMA_SxCR_CIRC;
	//Memory/Prephiral increment
	DMA2_Stream7->CR &= ~DMA_SxCR_PINC;
	DMA2_Stream7->CR &= ~DMA_SxCR_MINC;
	DMA2_Stream7->CR |= DMA_SxCR_MINC;
	//Set data size
	DMA2_Stream7->CR &= ~DMA_SxCR_MSIZE;
	DMA2_Stream7->CR &= ~DMA_SxCR_PSIZE;
	//Dirrection memory TO prephireal
	DMA2_Stream7->CR &= ~DMA_SxCR_DIR;
	DMA2_Stream7->CR |= DMA_SxCR_DIR_0;
	//Dissable dobble mode
	DMA2_Stream7->CR &= ~DMA_SxCR_DBM;
	//Enalbe DMA channel interrupt
	DMA2_Stream7->CR &= ~DMA_SxCR_TCIE;
	DMA2_Stream7->CR |= DMA_SxCR_TCIE;
	DMA2_Stream7->CR |=   DMA_SxCR_TEIE | DMA_SxCR_DMEIE;
	//Enable DMA for configuratio register
	//DMA2_Stream7->CR |= DMA_SxCR_EN;

	//**RX chanel 4 configuratin -CH5 stream 5 DMA2

	//Dissable DMA for configuratio register
	DMA2_Stream5->CR &= ~DMA_SxCR_EN;
	//Clear channel 4 flag
	DMA2->HISR &= ~(0xFUL << 8);
	//Prephiral address UART1->DR
	DMA2_Stream5->PAR = (uint32_t)&(USART1->DR);
	//Sellect chanel 4 DMA2 stream7
	DMA2_Stream5->CR &= ~DMA_SxCR_CHSEL;
	DMA2_Stream5->CR |= DMA_SxCR_CHSEL_2;
	//Folow control
	DMA2_Stream5->CR &= ~DMA_SxCR_PFCTRL;
	//Sellect priority
	DMA2_Stream5->CR &= ~DMA_SxCR_PL;
	DMA2_Stream5->CR |= DMA_SxCR_PL_1;
	//
	//Mode nomal/circular
	DMA2_Stream5->CR &= ~DMA_SxCR_CIRC;
	//Memory/Prephiral increment
	DMA2_Stream5->CR &= ~DMA_SxCR_PINC;
	DMA2_Stream5->CR &= ~DMA_SxCR_MINC;
	DMA2_Stream5->CR |= DMA_SxCR_MINC;
	//Set data size
	DMA2_Stream5->CR &= ~DMA_SxCR_MSIZE;
	DMA2_Stream5->CR &= ~DMA_SxCR_PSIZE;
	//Dirrection prephireal to memory
	DMA2_Stream5->CR &= ~DMA_SxCR_DIR;
	//Dissable dobble mode
	DMA2_Stream5->CR &= ~DMA_SxCR_DBM;
	//Enalbe DMA channel interrupt
	DMA2_Stream5->CR &= ~(0xFUL << 1);
	DMA2_Stream5->CR |= (0xBUL << 1);

	//Enable DMA interrupt

	NVIC_SetPriority(DMA2_Stream7_IRQn,6);
	NVIC_EnableIRQ(DMA2_Stream7_IRQn);
	NVIC_SetPriority(DMA2_Stream5_IRQn,6);
	NVIC_EnableIRQ(DMA2_Stream5_IRQn);

}

/*
 * @brief UART1 DMA Transmit
 */
void usart_USART1_DMA_transmit(uint8_t *data,uint8_t len)
{
	//Clear channel 4 flag
	DMA2->HIFCR |= 0xFUL << 24;
	//Memory address
	DMA2_Stream7->M0AR = (uint32_t)data;
	//No, of tranfer
	DMA2_Stream7->NDTR = len;
	//Enable DMA for configuratio register
	DMA2_Stream7->CR |= DMA_SxCR_EN;

}

/*
 * @brief UART1 DMA receive
 */
void usart_USART1_DMA_receive(uint8_t *data,uint8_t len)
{
	//Clear overun error, if any
	__IO uint32_t readTmp;
	readTmp = USART1->SR;
	readTmp = USART1->DR;
	(void)readTmp;//Prevent compiler warning
	//Clear channel 4 flag
	DMA2->HIFCR |= 0xFUL << 8;
	//Memory address
	DMA2_Stream5->M0AR = (uint32_t)data;
	//No, of tranfer
	DMA2_Stream5->NDTR = len;
	//Enable DMA channel
	DMA2_Stream5->CR |= DMA_SxCR_EN;
}

/*
 * @brief UART1 interrupt Transmits
 */
_Bool usart_USART1_IT_transmit(uint8_t *data,uint8_t len)
{
	uint8_t timeOut = 0xFF;
	//Transmit complete
	USART1->CR1 &= ~USART_CR1_TCIE;
	USART1->CR1 |= USART_CR1_TCIE;
	//Set priority
	NVIC_SetPriority(USART1_IRQn,10);
	//Enable NVIC
	NVIC_EnableIRQ(USART1_IRQn);
	//Wait on TXE start transmit
	//Write to DR as TXE flag is high
	uint8_t dataIdx = 0;
	uint32_t startTick = rcc_msGetTicks();
	while(dataIdx<len)
	{
		if(USART1->SR & USART_SR_TXE) //Tx buffer empty
		{
			USART1->DR = data[dataIdx];
			dataIdx++;
		}
		else
		{
			if((rcc_msGetTicks() - startTick) > timeOut) return false;
		}
	}
	//Wait for busy flag
	while(USART1->SR & USART_SR_TC != 1)
	{
		if((rcc_msGetTicks() - startTick) > timeOut) return false;
	}
	//USART1->SR &= ~(USART_SR_TC);
	return true;
}

/*
 * @brief UART1 interrupt Receive
 */
_Bool usart_USART1_IT_receive(uint8_t *data,uint8_t len)
{
	//Ready to read
	USART1->CR1 &= ~USART_CR1_RXNEIE;
	USART1->CR1 |= USART_CR1_RXNEIE;
	//Set priority
	NVIC_SetPriority(USART1_IRQn,9);
	//Enable NVIC
	NVIC_EnableIRQ(USART1_IRQn);
}

