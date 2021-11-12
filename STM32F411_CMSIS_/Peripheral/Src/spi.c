/*
 * spi.c
 *
 *  Created on: Aug 30, 2021
 *      Author: thanh
 */


#include "spi.h"

/*
 * @brief SPI1 GPIO configuration --> LCD ILI9341
 * SPI1 PA6-MISO PA7-MOSI PA5-SCK PB6-CS
 * SPI2 PC2-DO PC3-DIN PB5-TS_CS PB10-SCK
 * PA9-RST
 * PC7-DC
 */
const uint16_t crc_pr = 0x1234;

void spi_SPI1_GPIO_config(void)
{
	/* SPI1 */
	//Enable GPIO A,B,C
	RCC->AHB1ENR &= ~(0x7UL << 0);
	RCC->AHB1ENR |= 0x7UL << 0;
	//MODE alternate
	GPIOA->MODER &= ~(0x3FUL << 10);
	GPIOA->MODER |= 0x2A << 10;
	//HIGH speed
	GPIOA->OSPEEDR &= ~(0x3FUL << 10);
	GPIOA->OSPEEDR |= 0x3FUL << 10;
	//MAP AF5
	GPIOA->AFR[0] &= ~(0xFFF << 20);
	GPIOA->AFR[0] |= 0x555 << 20;

	/* SPI2 */
	GPIOC->MODER &= ~(0xFUL << 2);
	GPIOC->MODER |= 0xAUL << 2;
	GPIOB->MODER &= ~(0x3UL << 20);
	GPIOB->MODER |= 0x1UL << 21;
	//HIGH speed
	GPIOC->OSPEEDR &= ~(0xFUL << 2);
	GPIOC->OSPEEDR |= 0xFUL << 2;
	GPIOB->OSPEEDR &= ~(0x3UL << 20);
	GPIOB->OSPEEDR |= 0x3UL << 20;
	//MAP AF5
	GPIOC->AFR[0] &= ~(0xFF << 8);
	GPIOC->AFR[0] |= 0x55 << 8;
	GPIOB->AFR[1] &= ~(0xFUL << 8);
	GPIOB->AFR[1] |= 0x5UL << 8;

	//CS
	GPIOB->MODER &= ~(GPIO_MODER_MODE6);
	GPIOB->MODER |= GPIO_MODER_MODE6_0;
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT6);

	GPIOB->MODER &= ~(GPIO_MODER_MODE5);
	GPIOB->MODER |= GPIO_MODER_MODE5_0;
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT5);

	//DC and RST output push-pull
	//RST-PA9
	GPIOA->MODER &= ~(GPIO_MODER_MODE9);
	GPIOA->MODER |= GPIO_MODER_MODE9_0;
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT9;

	//PC7-DC
	GPIOC->MODER &= ~(GPIO_MODER_MODE7);
	GPIOC->MODER |= GPIO_MODER_MODE7_0;
	GPIOC->OTYPER &= ~GPIO_OTYPER_OT7;

}

/*
 * @brief SPI prephiral configuration
 */
void spi_SPI1_config(void)
{
	/* SPI1 */
	//Enable spi clock
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	//Clear all flag
	__IO uint32_t temRed = SPI1->SR;
	SPI1->SR = 0;
	//Sellect baurate Fpclk/2
	SPI1->CR1 &= ~(SPI_CR1_BR);
	//SPI1->CR1 |=   SPI_CR1_BR_1 | SPI_CR1_BR_2 | SPI_CR1_BR_0;
	//Sellect CPOL and CPAL
	SPI1->CR1 &= ~(SPI_CR1_CPHA);
	SPI1->CR1 &= ~(SPI_CR1_CPOL);
	//Set data fame 8/16 bit Motorola
	SPI1->CR1 &= ~(SPI_CR1_DFF);
	SPI1->CR2 &= ~(SPI_CR2_FRF);
	//Mode master
	SPI1->CR1 |= SPI_CR1_MSTR;
	//MSB first
	SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);
	//Duplex
	SPI1->CR1 &= ~(SPI_CR1_BIDIMODE);
	SPI1->CR1 &= ~(SPI_CR1_RXONLY);
	//Slave sellect
	SPI1->CR1 |= (SPI_CR1_SSI | SPI_CR1_SSM);

	/*Enable CRC */
	//crc_enable();
	//SPI1->CRCPR = crc_pr;
	//SPI1->CR1 &= ~SPI_CR1_CRCNEXT;
	//SPI1->CR1 |= SPI_CR1_CRCEN;

	//Enable SPI
	SPI1->CR1 |= SPI_CR1_SPE;
	//Clear all flag
	temRed = SPI1->SR;
	SPI1->SR = 0;

	/* SPI2 */
	/*
	//Enable spi clock
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	//Sellect baurate Fpclk/2
	SPI1->CR1 &= ~(SPI_CR1_BR);
	//Sellect CPOL and CPAL
	SPI1->CR1 &= ~(SPI_CR1_CPHA);
	SPI1->CR1 &= ~(SPI_CR1_CPOL);
	//Set data fame 8/16 bit Motorola
	SPI1->CR1 &= ~(SPI_CR1_DFF);
	SPI1->CR2 &= ~(SPI_CR2_FRF);
	//Mode master
	SPI1->CR1 |= SPI_CR1_MSTR;
	//MSB first
	SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);
	//Duplex
	SPI1->CR1 &= ~(SPI_CR1_BIDIMODE);
	SPI1->CR1 &= ~(SPI_CR1_RXONLY);
	//Slave sellect
	SPI1->CR1 &= ~(SPI_CR1_SSI | SPI_CR1_SSM);
	//Enable SPI
	SPI1->CR1 |= SPI_CR1_SPE;
	//Clear all flag
	__IO uint32_t tempRed = SPI1->SR;
	*/
}

/*
 * @brief SPI DMA configuration
 */
void spi_SPI1_DMA_config(void)
{
	/* SPI1 */
	//Enable spi clock
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	//Clear all flag
	__IO uint32_t temRed = SPI1->SR;
	SPI1->SR = 0;
	//Sellect baurate Fpclk/2
	SPI1->CR1 &= ~(SPI_CR1_BR);
	//SPI1->CR1 |=   SPI_CR1_BR_1 | SPI_CR1_BR_2;
	//Sellect CPOL and CPAL
	SPI1->CR1 &= ~(SPI_CR1_CPHA);
	SPI1->CR1 &= ~(SPI_CR1_CPOL);
	//Set data fame 8/16 bit Motorola
	SPI1->CR1 &= ~(SPI_CR1_DFF);
	SPI1->CR2 &= ~(SPI_CR2_FRF);
	//Mode master
	SPI1->CR1 |= SPI_CR1_MSTR;
	//MSB first
	SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);
	//Duplex
	SPI1->CR1 &= ~(SPI_CR1_BIDIMODE);
	SPI1->CR1 &= ~(SPI_CR1_RXONLY);
	//Slave sellect
	SPI1->CR1 |= (SPI_CR1_SSI | SPI_CR1_SSM);

	//Enable SPI1 DMA in SPI
	SPI1->CR2 &= ~(SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
	SPI1->CR2 |= (SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
	//Enable clock DMA2
	RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	/* TX DMA2 Stream2 channel 2 */
	//Dissable DMA for configuration register
	DMA2_Stream2->CR &= ~(DMA_SxCR_EN);
	//Clear channel 2 flag
	DMA2->LIFCR |= (0xFUL << 18);
	//Prephiral address SPI1->DR
	DMA2_Stream2->PAR = (uint32_t)&(SPI1->DR);
	//Sellect Stream2 channel 2
	DMA2_Stream2->CR |= DMA_SxCR_CHSEL_1;
	//Follow control
	DMA2_Stream2->CR &= ~DMA_SxCR_PFCTRL;
	//Sellect priority
	DMA2_Stream2->CR &= ~DMA_SxCR_PL;
	//Mode nomal/circle
	DMA2_Stream2->CR &= ~DMA_SxCR_CIRC;
	//Increment address/memory
	DMA2_Stream2->CR &= ~DMA_SxCR_PINC;
	DMA2_Stream2->CR &= ~DMA_SxCR_MINC;
	DMA2_Stream2->CR |= DMA_SxCR_MINC;
	//Set data size
	DMA2_Stream2->CR &= ~DMA_SxCR_MSIZE;
	DMA2_Stream2->CR &= ~DMA_SxCR_PSIZE;
	//Direction memory to prephiral
	DMA2_Stream2->CR &= ~DMA_SxCR_DIR;
	DMA2_Stream2->CR |= DMA_SxCR_DIR_0;
	//Dissable double mode
	DMA2_Stream2->CR &= ~DMA_SxCR_DBM;
	//Enable DMA channel interrupt
	DMA2_Stream2->CR &= ~DMA_SxCR_TCIE;
	DMA2_Stream2->CR |= DMA_SxCR_TCIE;
	DMA2_Stream2->CR |=   DMA_SxCR_TEIE | DMA_SxCR_DMEIE;


	/* RX DMA2 Stream0 channel 3 */
	//Dissable DMA for configuration register
	DMA2_Stream0->CR &= ~(DMA_SxCR_EN);
	//Clear channel 2 flag
	DMA2->LIFCR &= ~(0x1FUL << 16);
	//Prephiral address SPI1->DR
	DMA2_Stream0->PAR = (uint32_t)&(SPI1->DR);
	//Sellect Stream2 channel 3
	DMA2_Stream0->CR |= DMA_SxCR_CHSEL_1 | DMA_SxCR_CHSEL_0;
	//Follow control
	DMA2_Stream0->CR &= ~DMA_SxCR_PFCTRL;
	//Sellect priority
	DMA2_Stream0->CR &= ~DMA_SxCR_PL;
	//Mode nomal/circle
	DMA2_Stream0->CR &= ~DMA_SxCR_CIRC;
	//Increment address/memory
	DMA2_Stream0->CR &= ~DMA_SxCR_PINC;
	DMA2_Stream0->CR &= ~DMA_SxCR_MINC;
	DMA2_Stream0->CR |= DMA_SxCR_MINC;
	//Set data size
	DMA2_Stream0->CR &= ~DMA_SxCR_MSIZE;
	DMA2_Stream0->CR &= ~DMA_SxCR_PSIZE;
	//Direction prephiral to memory
	DMA2_Stream0->CR &= ~DMA_SxCR_DIR;
	//Dissable double mode
	DMA2_Stream0->CR &= ~DMA_SxCR_DBM;
	//Enable DMA channel interrupt
	DMA2_Stream0->CR &= ~DMA_SxCR_TCIE;
	DMA2_Stream0->CR |= DMA_SxCR_TCIE;
	DMA2_Stream0->CR |=   DMA_SxCR_TEIE | DMA_SxCR_DMEIE;

	//Interrupt
	NVIC_SetPriority(DMA2_Stream2_IRQn,6);
	NVIC_EnableIRQ(DMA2_Stream2_IRQn);
	NVIC_SetPriority(DMA2_Stream0_IRQn,6);
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);

	/*Enable CRC */
	//crc_enable();
	//SPI1->CRCPR = crc_pr;
	//SPI1->CR1 &= ~SPI_CR1_CRCNEXT;
	//SPI1->CR1 |= SPI_CR1_CRCEN;

	//Enable SPI
	SPI1->CR1 |= SPI_CR1_SPE;
	//Clear all flag
	temRed = SPI1->SR;
	SPI1->SR = 0;

}

/*
 * @brief SPI transmit
 */
_Bool spi_SPI1_transmit(uint8_t *pData, uint8_t len, uint32_t timeOut)
{
	uint8_t dataIdx = 0;
	uint8_t crc_val = 0;
	uint32_t startTick = rcc_msGetTicks();
	//Enable spi if not
	SPI1->CR1 |= SPI_CR1_SPE;
	while(dataIdx < len)
	{
		//TXE
		//if(dataIdx == len - 1)
		//{
		//	SPI1->CR1 |= SPI_CR1_CRCNEXT;
		//}
		if(SPI1->SR & SPI_SR_TXE)
		{
			SPI1->DR = pData[dataIdx];
			dataIdx++;
		}
		else
		{
			if(rcc_msGetTicks() - startTick  > timeOut) return false;
		}
		//crc_val = (uint8_t)(SPI1->TXCRCR & 0x00FF) ;
	}
	//SPI1->DR = crc_val;
	while(SPI1->SR & SPI_SR_BSY)
	{
		if(rcc_msGetTicks() - startTick  > timeOut) return false;
	}
	//Clear overun DR SR
	__IO uint32_t tempRead = SPI1->DR;
	tempRead = SPI1->SR;

	return true;
}

/*
 * @brief UART1 DMA Transmit
 */
void spi_SPI1_DMA_transmit(uint8_t *data,uint8_t len)
{
	//Clear channel 4 flag
	DMA2->LIFCR |= (0xFUL << 18);
	//Memory address
	DMA2_Stream2->M0AR = (uint32_t)data;
	//No, of tranfer
	DMA2_Stream2->NDTR = len;
	//Enable DMA for configuratio register
	DMA2_Stream2->CR |= DMA_SxCR_EN;
}

/*
 * @brief SPI receive
 */
_Bool spi_SPI1_receive(uint8_t *pData, uint8_t len, uint32_t timeOut)
{
	uint8_t dataIdx = 0;
	uint8_t crc_val = 0;
	uint32_t startTick = rcc_msGetTicks();
	//Enable spi if not
	SPI1->CR1 |= SPI_CR1_SPE;
	while(dataIdx < len)
	{
		//TXE
		if(dataIdx == len - 1)
		{
			crc_val = SPI1->DR;
			break;
		}
		if(SPI1->SR & SPI_SR_RXNE)
		{
			pData[dataIdx] = SPI1->DR;
			dataIdx++;
		}
		else
		{
			if((rcc_msGetTicks() - startTick)  > timeOut) return false;
		}
	}
	while(SPI1->SR & SPI_SR_BSY)
	{
		if((rcc_msGetTicks() - startTick)  > timeOut) return false;
	}
	//Clear overun DR SR
	__IO uint32_t tempRead = SPI1->DR;
	tempRead = SPI1->SR;
	if(crc_val != (uint8_t)(SPI1->RXCRCR & 0x00FF))
	{
		printf("Data recive error !!!/n");
	}
	return true;
}
