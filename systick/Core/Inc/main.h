#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f411xe.h"

#define read(addr,mask)  *((unsigned long int *)(addr)) &  mask
#define write(addr,value) *((unsigned long int *)(addr)) = value

// define rcc-clock
#define BASE_ADDRES_RCC     0x40023800u
#define RCC_AHB1ENR         (BASE_ADDRES_RCC + 0x30u)
 //define GPIO
#define BASE_ADDRES_GPIOD   0x40020C00u
#define GPIO_MODE           (BASE_ADDRES_GPIOD + 0x00u)
#define GPIO_MODE_INPUT     0x00u
#define GPIO_MODE_OUTPUT    0x01u
#define GPIO_MODO_ALT       0x03u

#define GPIO_BSRR           (BASE_ADDRES_GPIOD + 0x18u)
#define GPIOD_OTYPER        (BASE_ADDRES_GPIOD + 0x04u)
#define GPIO_ODR            (BASE_ADDRES_GPIOD + 0x14u)
//gpioa
#define BASE_ADDRES_GPIOA   0x40020000u
#define GPIO_MODEA         (BASE_ADDRES_GPIOA + 0x00u)
#define GPIO_IDR           (BASE_ADDRES_GPIOA + 0x10u)



#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
