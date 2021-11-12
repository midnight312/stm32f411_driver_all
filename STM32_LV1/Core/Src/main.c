#include "main.h"

_Bool extiFlag        = 0;
_Bool adcEoc          = 0;
__IO int16_t adcValue = 0;
_Bool ledState        = 0;

int main(void)
{
	//Dissable WATCHDOG
	//WWDG->CR &= ~(WWDG_CR_WDGA);

	rcc_HSE_config();
	rcc_SysTick_config(96000);
	gpio_LED_Config();
	//gpio_PB_Config();
	//exti_PB_EXTI();

	//adc_GPIO_config();
	//adc_singleConfig(ADC_SingleSellect_Device1);
	//adc_Enable_Interrupt();
	//tim_TIM2_delayConfig();
	//tim_TIM2_priodicConfig(1000);
	//tim_TIM2_CH2N_config();
	//tim_TIM2_OC_config(1000);
	//pwr_enterStandby();
	uart_UART1_GPIO_config();
	uart_UART1_config();
	//spi_GPIO_config();
	//spi_config();
	char c = 'a';
	uint8_t tBuft[8];
	uint8_t rBuft[8];
	uint8_t* x[1];
	x[0] = c;
	for(int i = 0;i<8;i++)
	{
		rBuft[i] = i + 66;
	}
	//int a = strlen(rBuft);
	while(1)
	{
		uart_translate(&c,100);
		ms_Delay(1000);
		//gpio_LED_Toggle(LED4,1000);

	}
}
void EXTI0_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(EXTI0_IRQn);
	EXTI->PR |= 1UL << 0;
	//Application
	extiFlag = 1;

}
void ADC_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(ADC_IRQn);
	if(((ADC1->SR) & (ADC_SR_EOC)) != 1)
	{
		adcValue = adc_readValue();
		adcEoc = 1;

	}
}
void TIM2_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(TIM2_IRQn);
	if(TIM2->SR & TIM_SR_UIF)
	{
		TIM2->SR &= ~TIM_SR_UIF;
	}
	ledState ^= 1;
	gpio_LED_Write(ledState,LED5);
}
