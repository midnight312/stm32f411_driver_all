/*
 * main.h
 *
 *  Created on: Aug 9, 2021
 *      Author: thanh
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rcc.h"
#include "usart.h"
#include "gpio.h"
#include "exti.h"
#include "adc1.h"
#include "tim.h"
#include "rtc.h"
#include <time.h>
#include "spi.h"
#include "crc.h"
#include "MY_ILI9341.h"
#include "i2c.h"
#include "pwr.h"

//#include "TSC2046.h"


#define Avg_Slope .0025
#define V25       .76
#define Vsense    3.3/4096

//Define DC, RST, CS for ILI9341
#define TS_DO_Pin GPIO_PIN_2
#define TS_DO_GPIO_Port GPIOC
#define T_DIN_Pin GPIO_PIN_3
#define T_DIN_GPIO_Port GPIOC
#define LCD_DC_Pin 7
#define LCD_DC_GPIO_Port GPIOC
#define LCD_RST_Pin 9
#define LCD_RST_GPIO_Port GPIOA
#define TS_CS_Pin 5
#define TS_CS_GPIO_Port GPIOB
#define LCD_CS_Pin 6
#define LCD_CS_GPIO_Port GPIOB



#endif /* MAIN_H_ */
