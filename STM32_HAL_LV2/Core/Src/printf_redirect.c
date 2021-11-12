/*
 * printf_redirect.c
 *
 *  Created on: Jun 17, 2021
 *      Author: thanh
 */


#include "uart1.h"

//int __io_putchar(int ch);
//int _write(int file, char *ptr, int len);
//
//int __io_putchar(int ch)
//{
//	uint8_t c[1];
//	c[0] = ch & 0x00FF;
//	HAL_UART_Transmit(&huart1, &c[0], 1, 100);
//	return ch;
//}
//int _write(int file, char *ptr, int len)
//{
//	int dataIndx;
//	for(dataIndx = 0; dataIndx < len; dataIndx++)
//	{
//		__io_putchar(*ptr++);
//
//	}
//	return len;
//}
