#include "spi.h"

/*
 * @brief SPI GPIO configuration
 */
void spi_GPIO_config()
{
	//MOSI-PA7 MISO-PA6 SCK-PA5 NSS-PA4
	//Enable clocl port A
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN);
	//Mode alternate SPI
	GPIOA->MODER &= ~(0XAA << 8);
	GPIOA->MODER |= (0XAA << 8);
	//Speed max
	GPIOA->OSPEEDR |= 0xFF << 8;
	//MOSI & SCK output push-pull
	//MISO floating input
	GPIOA->OTYPER |= GPIO_OTYPER_OT6;
	//MAP alternate
	GPIOA->AFR[0] &= ~(0xFFFF << 16);
	GPIOA->AFR[0] |= 0x5555 << 16;
}

/*
 * @brief SPI configuration
 */
void spi_config()
{
	//Enable SPI clock
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	//Clock phase
	SPI1->CR1 |= SPI_CR1_CPHA;
	//Clock polariry
	SPI1->CR1 |= SPI_CR1_CPOL;
	//Mode Master/Slave
	SPI1->CR1 |= SPI_CR1_MSTR;
	//Baurate
	SPI1->CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_0 | SPI_CR1_BR_0;
	//MSB first
	SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);
	//Duplex
	SPI1->CR1 &= ~(SPI_CR1_RXONLY);
	//Data format
	SPI1->CR1 &= ~(SPI_CR1_DFF);
	//Slave select
	SPI1->CR1 &= ~(SPI_CR1_SSM);
	//Enable SPI
	SPI1->CR1 |= (SPI_CR1_SPE);
	//Clear all flag
	volatile uint32_t tempRd = SPI1->SR;
}

/*
 * @brief SPI transmit
 */
_Bool spi_transmit(uint8_t *pData,uint8_t len, uint32_t timeout)
{
	uint8_t dataIdex = 0;
	uint32_t statickStart = rcc_msGetSysTick();
	while(dataIdex < len)
	{
		if(SPI1->SR & SPI_SR_TXE)
		{
			SPI1->DR = pData;
			dataIdex++;
		}
		else
		{
			if(rcc_msGetSysTick()- statickStart > timeout) return 0;
		}
	}
	while(SPI1->SR & SPI_SR_BSY)
	{
		if(rcc_msGetSysTick()- statickStart > timeout) return 0;
	}
	//Clear overun
	volatile uint32_t tempRead = SPI1->DR;
	tempRead = SPI1->DR;
}

/*
 * @brief SPI receive
 */
_Bool spi_receive(uint8_t *pData,uint8_t len, uint32_t timeout)
{

}
