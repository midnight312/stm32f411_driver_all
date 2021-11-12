/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rcc.h"
#include "uart1.h"
#include "gpio.h"
#include "tim.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
_Bool buttonInterrupt = false;

int main(void)
{

  HAL_Init();
  //rcc_systemClockConfig();
  //UART
  uart_UART1_GPIO_config();
  uart_UAR1_config();
  //GPIO
  gpio_LED_config();
  exti_buttonConfig();
  //TIM
  //tim_TIM3_config(400);
  //HAL_TIM_Base_Start_IT(&htim3);
  /*
  tim_TIM3_PWM_GPIO_config();
  tim_TIM3_PWM_config();
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);

  //RED
  tim_PWM_setRGB(255, 0, 0);
  //BLUE
  tim_PWM_setRGB(0, 255, 0);
  //GREEN
  tim_PWM_setRGB(0, 0, 255);
  //CYAN
  tim_PWM_setRGB(0, 255, 255);
  //MAGRNET
  tim_PWM_setRGB(255, 0, 255);

  //TIM-OC
  //tim_TIM4_OC_GPIO_config();
  //tim_TIM4_OC_config(1000);

  //Start chanel 1
  //HAL_TIMEx_OCN_Start(&htim4, TIM_CHANNEL_1);
  //Start chanel 2
  //HAL_TIMEx_OCN_Start(&htim4, TIM_CHANNEL_2);

  //TIM encoder
  tim_TIM5_ENCODER_GPIO_config();
  tim_TIM5_ENCODER_config();
  printf("Encoder is starting ...\n");
  HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_1l);
  int encoderCount;
  uint8_t encoderDir;
  */
  printf("Programing is starting ...\n");
  while (1)
  {

	  //printf("hello-%d\n",count);
	  //HAL_UART_Transmit(&huart1, &a, 1, 100);

	  //HAL_Delay(1000);
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_0)
	{
		buttonInterrupt ^= 1;
		//EXTI->IMR &= ~(EXTI_IMR_IM0);
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM3)
	{
		gpio_LED_toggle();
		HAL_Delay(1000);
	}
}
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
int __io_putchar(int ch)
{
	uint8_t c[1];
	c[0] = ch & 0x00FF;
	HAL_UART_Transmit(&huart1, &c[0], 1, 100);
	return ch;
}
int _write(int file, char *ptr, int len)
{
	int dataIndx;
	for(dataIndx = 0; dataIndx < len; dataIndx++)
	{
		__io_putchar(*ptr++);

	}
	return len;
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
