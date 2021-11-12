#include "main.h"
// init clock systick 96mhz
void init_clock(void)
{
	volatile uint32_t timeout;
	uint32_t tempreg;
	/* dissable all interrupt */
	RCC->CIR = 0x00000000;
	/* dissable Internal hight speed */
	RCC->CR &= ~0x00000001;
	/* Wait still HSI dissable */
	timeout = 0x0;
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
	RCC->PLLCFGR |= 0x8U << 24 | 0xC8U << 6 | 0x8U << 0;
	/* ENABLE PLL */
	RCC->CR |= 1 << 24;
	/* Wait PLL ready */
	timeout = 0xFFFFFF;

	while((!(RCC->CR & (1 << 25))) && (timeout > 0))
	{
		timeout--;
	}
	/* HSE enable */
	RCC->CR |= 1 << 16;
	/* WAIT HSE ENABLE */
	timeout = 0xFFFF;
	while((!(RCC->CR & (0x1U << 17))) && (timeout > 0))
	{
		timeout--;
	}
	/* HSE USE SYSCLOCK */
	RCC->CFGR &= ~(0x3U << 0);
	RCC->CFGR |= 1U << 0;
	/* WAIT SYSTEM CLOCK READY */
	timeout = 0x0FFFFFFF;
	while(((RCC->CFGR & (0x3U << 2)) != (1 << 2)) && (timeout > 0))
	{
		timeout--;
	}
	RCC->CFGR &= ~(0xFFF0);
	RCC->CFGR |= 1 << 12;
}

void init_all(void)
{
	//clock
	unsigned int tempreg;
	tempreg = read(RCC_AHB1ENR, ~(1u << 3));
	tempreg = tempreg | 1u << 3;
	write(RCC_AHB1ENR,tempreg);
	//GPIO
	//unsigned int tempreg;
	tempreg = read(GPIO_MODE, ~(0x03u << 24));
	tempreg = tempreg | GPIO_MODE_OUTPUT << 24;
	write(GPIO_MODE,tempreg);
	//Systick
	SysTick->CTRL = 0x0000000u;
	//SysTick->CTRL = 0x0000004u;
	SysTick->VAL  = 0x0000000u;
}
void led_on(unsigned long int pinLed)
{

	unsigned int tempreg;
	tempreg = read(GPIO_BSRR, ~(1u << pinLed));
	tempreg = tempreg | 1u << pinLed;
	write(GPIO_BSRR,tempreg);

}
void led_off(unsigned long int pinLed)
{

	unsigned int tempreg;
	tempreg = read(GPIO_BSRR, 1u << pinLed + 16u);
	tempreg = tempreg | 1u << pinLed + 16u;
	write(GPIO_BSRR,tempreg);

}
void systick_start(unsigned int value)
{
	SysTick->LOAD = value;
	SysTick->VAL  = 0x0000000u;
	SysTick->CTRL = 0x00000001u;
}
unsigned int get_state_stick(void)
{
	unsigned int tempreg;
	tempreg = read(SysTick->CTRL, 1u << 16);
	tempreg = tempreg >> 16;
	return tempreg;
}
void delay(unsigned int time)
{
	while(time--)
	{
		systick_start(0x30D3);
		while(  0 == get_state_stick()){};
	}
}
void main(void)
{
	init_clock();
	init_all();
	while(1)
	{
		led_on(12);
		delay(1000);
		led_off(12);
		delay(1000);
	}

}
