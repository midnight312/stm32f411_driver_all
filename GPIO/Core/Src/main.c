#include "main.h"

void init_pin(void)
{
	//output led
	unsigned int tempreg;
	tempreg = read_reg(GPIO_MODE, ~(0x03u << 24));
	tempreg = tempreg | GPIO_MODE_OUTPUT << 24;
	write_reg(GPIO_MODE,tempreg);
    //input button
    tempreg = read_reg(GPIO_MODEA,~(0x03u << 0));
    tempreg = tempreg | GPIO_MODE_INPUT << 0;
    write_reg(GPIO_MODEA,tempreg);

}
void led_on(unsigned long int pinLed)
{

	unsigned int tempreg;
	tempreg = read_reg(GPIO_BSRR, ~(1u << pinLed));
	tempreg = tempreg | 1u << pinLed;
	write_reg(GPIO_BSRR,tempreg);

}
void led_off(unsigned long int pinLed)
{
	
	unsigned int tempreg;
	tempreg = read_reg(GPIO_BSRR, 1u << pinLed + 16u);
	tempreg = tempreg | 1u << pinLed + 16u;
	write_reg(GPIO_BSRR,tempreg);

}
void delay(unsigned int timeout)
{
	unsigned int t1,t2;
	for(t1 = 0; t1 < timeout; t1++)
	{
		for(t2 = 0;t2 < 0x0FFF;t2++)
		{
			asm("nop");
		}
	}
}
void ennable_clock(void)
{
//led
	unsigned int tempreg;
	tempreg = read_reg(RCC_AHB1ENR, ~(1u << 3));
	tempreg = tempreg | 1u << 3;
	write_reg(RCC_AHB1ENR,tempreg);
//button
	tempreg = read_reg(RCC_AHB1ENR, ~(1u << 0));
	tempreg = tempreg | 1u << 0;
	write_reg(RCC_AHB1ENR,tempreg);
 
}
void main(void)
{
	printf("hello world !!!");
	unsigned int temple = 0u;
	ennable_clock();
	init_pin();
	led_on(LED4);
	while(1)
	{
		temple = read_reg(GPIO_IDR,(1u << 0));
		if(temple == 0)
		{
			led_on(LED4);
		}
		else 
		{
			led_off(LED4);
		}
	}
}
