#include "uart.h"

/**
 * @brief UART1 GPIO Configuration
 */
void uart_UART1_GPIO_config(void)
{
	//PA9-TX PA10-RX
	//Enable clock GPIOA
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN);
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Mode Alternate
	GPIOA->MODER &= ~(GPIO_MODER_MODE15);
	GPIOA->MODER |= GPIO_MODER_MODER15_1;
	GPIOA->MODER &= ~(GPIO_MODER_MODE10);
	GPIOA->MODER |= GPIO_MODER_MODER10_1;
	//Speed max
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR15);
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15_1 | GPIO_OSPEEDER_OSPEEDR15_0;
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR10);
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10_1 | GPIO_OSPEEDER_OSPEEDR10_0;
	//Map PA0, PA10 to UART1
	GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH1);
	GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH2);
	GPIOA->AFR[1] |= GPIO_AFRH_AFRH7_0 | GPIO_AFRH_AFRH7_1 | GPIO_AFRH_AFRH7_2;
	GPIOA->AFR[1] |= GPIO_AFRH_AFRH2_0 | GPIO_AFRH_AFRH2_1 | GPIO_AFRH_AFRH2_2;
	//
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD15);
}

/**
 * @brief UART1 Configuration
 */
void uart_UART1_config(void)
{
	//Dissable all flag and uart
	USART1->SR = 0;
	//Enable UART1 clock
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	//Disnable UART1
	USART1->CR1 &= ~(USART_CR1_UE);
	//Parity even
	USART1->CR1 &= ~(USART_CR1_PS);
	//Parity control enable
	USART1->CR1 &= ~(USART_CR1_PCE);
	//USART1->CR1 |= USART_CR1_PCE;
	//Word length 8 bit
	USART1->CR1 &= ~(USART_CR1_M);
	//Stop bit to 1
	USART1->CR2 &= ~(USART_CR2_STOP);
	//USART1->CR2 |= (USART_CR2_STOP_1);
	//Dissable HW Flow Control
	USART1->CR3 &= ~(USART_CR3_RTSE);
	USART1->CR3 &= ~(USART_CR3_CTSE);
	//Dissable Smart care
	USART1->CR3 &= ~(USART_CR3_SCEN);
	//Set baurate 115200
	USART1->BRR = 0;
	//USART1->BRR |= 52 << 4 | 1 << 0;
	USART1->BRR |= 625 << 4;
	//CLEAR something as clk and LIN
	USART1->CR2 &= ~(USART_CR2_LINEN | USART_CR2_CLKEN );
	USART1->CR3 &= ~(USART_CR3_HDSEL | USART_CR3_IREN);
	USART1->CR1 |= USART_CR1_UE;
	//Enable transmit
	USART1->CR1 |= USART_CR1_TE;
	//Enable receive
	USART1->CR1 |= USART_CR1_RE;
	USART1->SR &= ~(USART_SR_TC);
}

/**
 * @brief UART transmit
 */
_Bool uart_UART1_transmit(uint8_t *data, uint8_t len, uint8_t timeout)
{
	//Wait TXE start on transmit
	//Write DR as TXE flag is HIGHT (TX buffer empty)
	uint8_t *pData;
	pData = data;
	uint8_t dataIdex = 0;
	uint32_t startTick = rcc_msGetSysTick();
	while(dataIdex < len )
	{
		if(USART1->SR & USART_SR_TXE) //TX buffer empty
		{
			USART1->DR = (uint8_t)(*pData & 0xFFU);
			dataIdex++;
			//ms_Delay(100);
		}
		else
		{
			if((rcc_msGetSysTick() - startTick) >= timeout)
			{
				return 0;
			}
		}
	}
	//wait for busy flag
	while(USART1->SR & USART_SR_TC != 1)
	{
		if((rcc_msGetSysTick() - startTick) >= timeout)
		{
			return 0;
		}
	}
	USART1->SR &= ~(USART_SR_TC);
	ms_Delay(1000);
	return 1;
}
_Bool uart_translate(uint8_t data,uint8_t timeout)
{
	uint32_t startTick = rcc_msGetSysTick();
	if(USART1->SR & USART_SR_TXE) //TX buffer empty
	{
		USART1->DR = data;
		//ms_Delay(100);
	}
	else
	{
		if((rcc_msGetSysTick() - startTick) >= timeout)
		{
			return 0;
		}
	}
	//wait for busy flag
	while(USART1->SR & USART_SR_TC != 1)
	{
		if((rcc_msGetSysTick() - startTick) >= timeout)
		{
			return 0;
		}
	}
	USART1->SR &= ~(USART_SR_TC);
	return 1;
}

/**
 * @brief UART receive
 */
_Bool uart_UART1_receive(uint8_t *data, uint8_t len, uint8_t timeout)
{
	uint8_t dataRemain = len;
	uint32_t startTick = rcc_msGetSysTick();
	while(dataRemain > 0)
	{
		if(USART1->SR & USART_SR_RXNE) //TX buffer empty
		{
			*data++ = (uint8_t)(USART1->DR & 0xFF);
			dataRemain--;
		}
		else
		{
			if((rcc_msGetSysTick() - startTick) >= timeout)
			{
				return 0;
			}
		}
		return 1;
	}
}

