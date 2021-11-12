#ifndef __MAIN_H
#define __MAIN_H

#define LED3 13
#define LED4 12
#define LED5 14
#define LED6 15

#define write_reg(addr, value)  *((unsigned long int *)(addr)) = value
#define read_reg(addr,mask)     *((unsigned long int *)(addr)) & mask

#define __I  volatile const  //read only
#define __O  volatile        //write only
#define __IO volatile        //read/write

//signed integer typed

typedef signed char  int8_t;
typedef signed short int16_t;
typedef signed long  int_32_t;

//usinged integer typed

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;

typedef enum {FALSE = 0, TRUE	 = !FALSE} bool;
typedef enum {SET = 1, RESET = !SET} BitAction;
typedef enum {ENABLE = 1, DISABLE = !ENABLE} FunctionalState;
#define IS_FUNCTIONSTATE_OK(state) ((state == DISABLE) || (state == ENABLE))
typedef enum {ERROR = 0, SUCCERS = !ERROR} ErrorState;
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
