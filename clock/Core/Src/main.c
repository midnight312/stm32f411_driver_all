#include "main.h"


void delay(unsigned long int time)
{
	while(time--)
	{
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");

	}
}

void init_all(void)
{
	volatile uint32_t timeout;
	//uint32_t tempreg;
	/* dissable all interrupt */
	RCC->CIR = 0x00000000;
	/* dissable Internal hight speed */
	RCC->CR &= ~0x00000001;
	/* Wait still HSI dissable */
	timeout = 0xFFF;
	while((RCC->CR & (1 << 1)) != 0 && timeout > 0)
	{
		timeout--;
	}

	/* dissable PLL */
	RCC->CR &= ~(1 << 24);
	/* Wait PLL dissable */
	timeout = 0xFFFFFF;
	while((RCC->CR & (1 << 25)) != 0 && timeout > 0)
	{
		timeout--;
	}
	  /* Configure the main PLL clock source, predivider and multiplication factor. */
	RCC->PLLCFGR &= ~(0x0F037FFF);
	RCC->PLLCFGR |= 0x8U << 24 | 1U << 16 | 0x150U << 6 | 0x7U << 0;
	/* ENABLE PLL */
	RCC->CR |= 1 << 24;
	/* Wait PLL ready */
	timeout = 0xFFFFFF;
	while((RCC->CR & (1U << 25)) && (timeout > 0))
	{
		timeout--;
	}
	/* HSE USE SYSCLOCK */
	RCC->CFGR &= ~(0x3U << 0);
	RCC->CFGR |= 1U << 0;
	/* WAIT SYSTEM CLOCK READY */
	timeout = 0x0FFFFFFF;
	while(((RCC->CFGR & (0x3U << 2)) != (2 << 2)) && (timeout > 0))
	{
		timeout--;
	}
	RCC->CFGR &= ~(0xFFF0);
	RCC->CFGR |= 1 << 12;
}

void main(void)
{
	init_all();

	while(1)
	{

	}

}

