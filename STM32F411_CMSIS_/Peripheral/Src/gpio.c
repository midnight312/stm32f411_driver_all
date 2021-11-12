/*
 * gpio.c
 *
 *  Created on: Aug 12, 2021
 *      Author: thanh
 */


#include "gpio.h"

/*
 * @brief GPIO config pin LED PD12-15
 */
void gpio_LED_config(void)
{
	//Enable GPIOD
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIODEN);
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	//Configuration mode
	GPIOD->MODER &= 0xFF << 24;
	GPIOD->MODER |= 0x55 << 24;
	//PUSH-PULL
	GPIOD->OTYPER &= ~(0xF << 12);
	//Configuration speed LOW
	GPIOD->OSPEEDR &= ~(0xFF << 24);

}
/*
 * @brief Write state to the LED
 */
void gpio_LED_write(uint8_t LED_PIN,uint8_t state)
{
	state = !state;
	GPIOD->BSRR |= 0x1UL << (LED_PIN + state*16);
}

/*
 * @brief Toggle LED
 */
void gpio_LED_toggle(uint8_t LED_PIN, uint32_t delay)
{
	gpio_LED_write(LED_PIN,1);
	rcc_msDelay(delay);
	gpio_LED_write(LED_PIN,0);
	rcc_msDelay(delay);
}
void gpio_LED_display()
{
	uint8_t i = LED_GREEN;
	for(i;i<=LED_BLUE;i++)
	{
		gpio_LED_write(i,0);
	}
	for(i = LED_GREEN;i<=LED_BLUE;i++)
	{
		gpio_LED_write(i,1);
		rcc_msDelay(100);
		gpio_LED_write(i,0);

	}
}

/*
 * @grief GPIO configuratin button B1 PA0
 */
void gpio_BUTTON_config(void)
{
	//Enable clock GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Configuaration PA0 as Input
	GPIOD->MODER &= ~GPIO_MODER_MODE0;
	//Pull no PULL UP- no PULL DOWN
	GPIOD->PUPDR &= ~GPIO_PUPDR_PUPD0;

}

/*
 * @brief GPIO read BUTTON B1
 */
_Bool gpio_BUTTON_read()
{
	return (GPIOA->IDR & GPIO_IDR_IDR_0);
}

/*
 * @brief write state to the port and pin
 */
void gpio_WritePin(GPIO_TypeDef *port,uint8_t pin, uint8_t state)
{
	state = !state;
	port->BSRR |= 0x1UL << (pin + state*16);
}

