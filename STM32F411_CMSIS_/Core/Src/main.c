#include "main.h"

_Bool extiFlag        = false;
_Bool stateLed        = false;
_Bool uartDmaRxFlag   = false;
_Bool uartDmaTxFlag   = false;
_Bool spiDmaRxFlag   = false;
_Bool spiDmaTxFlag   = false;
_Bool adcEOC          = false;
_Bool adcAwd          = false;

float Temperature = 0;
uint16_t adc_value    = 0;
uint16_t adcBuffer[3] = {0};

//Picture
extern const unsigned char qqq[153600];
extern const unsigned char gImage_d[230400];
extern const unsigned char hhh[153600];
extern const unsigned char gImage_vvv[153600];

int main(void)
{
	//MAX 100 MHZ
	rcc_HSE_Config();
	rcc_SYSTICk_config(100000);
	//Printf to usart1
	usart_USART1_GPIO_config();
	usart_USART1_config();
	usart_USART1_DMA_config();
	//LED config
	gpio_LED_config();
	//BUTTON config
	gpio_BUTTON_config();
	//EXTI PB1 config
	exti_BP_EXTI();
	//ADC configuration
	//adc_GPIO_config();
	//adc_Temperature();
	//adc_singleConfig(ADC_singleSelect_Potentimeter);
	//adc_enableEOC_IT();
	//adc_multiChanel_config();
	//adc_multichanel_DMA_config(adcBuffer);

	//TIM configuration
	//tim_TIM2_config();
	//tim_TIM3_delayConfig();
	//tim_TIM3_delayConfig(1000);
	//tim_TIM5_CH2N_GPIO_config();
	//tim_TIM5_OC_config(300);

	//RTC Configuration




	//CRC
	//crc_enable();
	//crc_reset();
	//crc_accumulate(0x00112233);
	//crc_accumulate(0x11223344);
	//__IO uint32_t crcVal = crc_read();
	//SPI config
	spi_SPI1_GPIO_config();
	spi_SPI1_DMA_config();

	//I2C
	//i2c_I2C1_GPIO_config();
	//i2c_I2C1_config();


	/* ILI9341 */
	//char text[] = "Program starting...";
	//ILI9341_Init(LCD_CS_GPIO_Port, LCD_CS_Pin, LCD_DC_GPIO_Port, LCD_DC_Pin, LCD_RST_GPIO_Port, LCD_RST_Pin);
	//ILI9341_setRotation(2);
	//ILI9341_Fill(COLOR_NAVY);
	//ILI9341_printText(text, 2, 6, COLOR_WHITE, COLOR_NAVY, 2);
	//ILI9341_printNumb(3121999, 120, 120, COLOR_RED, COLOR_NAVY, 2);


	//ILI9341_printImage(0,0,320,240,qqq, 76800*2);

	printf("Program starting ...\n");

	uint8_t tBuff[3];
	uint8_t rBuff = 0x00;
	tBuff[0] = 0x11;
	tBuff[1] = 0x22;
	tBuff[2] = 0x33;

	while(1)
	{
		usart_USART1_DMA_transmit(tBuff,3);

		gpio_LED_display();
		rcc_msDelay(3000);
	}
}


void EXTI0_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(EXTI0_IRQn);

	//Application
	EXTI->IMR &= ~EXTI_IMR_IM0;
	extiFlag = true;
	//gpio_LED_display();
	//rcc_msDelay(20);
	EXTI->PR |= EXTI_PR_PR0;
	EXTI->IMR |= EXTI_IMR_IM0;
}

//UART DMA RX
void DMA2_Stream5_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(DMA2_Stream5_IRQn);

	if(DMA2->HISR & DMA_HISR_TCIF5)
	{
		//Disaable DMA
		DMA2_Stream5->CR &= ~DMA_SxCR_EN;
		//Clear Flag
		DMA2->HIFCR |= 0xFUL << 8;
		//Notify application
		uartDmaRxFlag = true;

	}
	//Tranfer error
	if(DMA2->HISR & DMA_HISR_TEIF5)
	{
		DMA2->HIFCR |= DMA_HIFCR_CTEIF5;
	}
}

//UART DMA TX
void DMA2_Stream7_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(DMA2_Stream7_IRQn);

	if(DMA2->HISR & DMA_HISR_TCIF7)
	{
		//Disaable DMA
		DMA2_Stream7->CR &= ~DMA_SxCR_EN;
		//Clear Flag
		DMA2->HIFCR |= 0xFUL << 24;
		//Notify application
		uartDmaTxFlag = true;
	}
	//Tranfer error
	if(DMA2->HISR & DMA_HISR_TEIF7)
	{
		DMA2->HIFCR |= DMA_HIFCR_CTEIF7;
	}
}

//UART IT RX
void USART1_IRQHandler(void)
{
	//READY TO READ
	if(USART1->SR & USART_SR_RXNE)
	{

	}
	//ERROR OVER
	if(USART1->SR & USART_SR_ORE)
	{

	}
	//TRANSMIT COMPLIT
	if(USART1->SR & USART_SR_TC)
	{

	}
	//Clear all flag USART1
	USART1->CR1 &= ~USART_SR_RXNE;
	USART1->CR1 &= ~USART_SR_TC;
	USART1->CR1 &= ~USART_SR_ORE;
}

//SPI DMA TX
void DMA2_Stream2_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(DMA2_Stream2_IRQn);
	//TX
	if(DMA2->LISR & DMA_LISR_TCIF2)
	{
		//Disaable DMA
		DMA2_Stream2->CR &= ~DMA_SxCR_EN;
		//Clear Flag
		DMA2->LIFCR |= (0xFUL << 18);
		//Notify application
		spiDmaTxFlag = true;
	}
	//Tranfer error
	//if(DMA2->LISR & DMA_LISR_TEIF2)
	//{
	//	DMA2->LIFCR |= DMA_LIFCR_CTEIF2;
	//}
}

//ADC INTERRRUPT
void ADC_IRQHandler(void)
{
	if(ADC1->SR & ADC_SR_EOC)
	{
		adc_value = adc_readValue();
		NVIC_ClearPendingIRQ(ADC_IRQn);
		adcEOC = true;
	}
	if(ADC1->SR & ADC_SR_AWD)
	{
		ADC1->SR &= ~ADC_SR_AWD;
		//Single to application
		adcAwd = true;
	}
	NVIC_ClearPendingIRQ(ADC_IRQn);
}

//ADC multial interrupt complete
void DMA2_Stream0_IRQHandler(void)
{
	if(DMA2->LISR & DMA_LISR_TCIF0)
	{
		//Clear interrupt
		NVIC_ClearPendingIRQ(DMA2_Stream0_IRQn);
		//Clear all flag
		DMA2->LISR &= ~(0x3BUL << 0);
		//Application
		adcEOC = true;
	}
}

//TIMER INTERRUPT
void TIM3_IRQHandler(void)
{
	if(TIM3->SR & TIM_SR_UIF)
	{
	//Clear all flag
	TIM3->CR1 |= TIM_CR1_CEN;
	//Application

	}
}


