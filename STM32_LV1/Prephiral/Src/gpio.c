#include "gpio.h"

#define BB_BASE
#define BB_RCC_AHBENR_OFSET   0x23830
#define BB_PIN_3              3
#define BB_ADDR_AHB1ENR       *(uint32_t *)(BB_BASE + BB_RCC_AHBENR_OFSET*32 + BB_PIN_3*4)

/*
 * @brief GPIO configuration PD12( LED4 ), PD13( LED3 ), PD14( LED5 ), PD15( LED6 )
 */
void gpio_LED_Config(void)
{
	//Enable GPIOD
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	//BB_ADDR_AHB1ENR = 1;
	//Mode Output
	GPIOD->MODER &= ~(0xFFUL << 24);
	GPIOD->MODER |= 0x55UL << 24;
	//Push-Pull
	GPIOD->OTYPER &= ~(0xFUL << 12);

}

/*
 * @brief Write/Toggle function
 */
void gpio_LED_Write(_Bool state,uint8_t LED_number)
{
	if(state)
	{
		GPIOD->BSRR |= 1 << LED_number;
	}
	else
	{
		GPIOD->BSRR |= 1 << (LED_number + 16);
	}
}
void gpio_LED_Toggle(uint8_t LED_number,uint32_t delay)
{
	gpio_LED_Write(1, LED_number);
	ms_Delay(delay);
	gpio_LED_Write(0, LED_number);
	ms_Delay(delay);
}

/*
 * @brief BUTTON GPIO configuration B1 (PA0)
 */
void gpio_PB_Config(void)
{
	//Enable clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Configuration Input
	GPIOA->MODER &= ~(GPIO_MODER_MODE0);
	//Configuration No Pull-up, Pull-down
	GPIOA->OTYPER |= GPIO_OTYPER_OT0;
}

/*
 * Get Status Button B1
 */
_Bool gpio_PB_read(void)
{
	return (GPIOA->IDR & GPIO_IDR_IDR_0);
}
