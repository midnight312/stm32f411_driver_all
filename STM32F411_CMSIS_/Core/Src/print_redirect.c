/*
 * print_redirect.c
 *
 *  Created on: Aug 12, 2021
 *      Author: thanh
 */


#include "usart.h"

int __io_putchar(int ch);
int _write(int file,char* ptr, int len);

int __io_putchar(int ch)
{
	uint8_t c[1];
	c[0] = ch & 0x00FF;
	usart_USART1_transmit(&c,1,100);

	return ch;
}
int _write(int file,char* ptr, int len)
{
	int dataIdx;
	for(dataIdx = 0; dataIdx < len;dataIdx++)
	{
		__io_putchar(*ptr++);
	}
	return len;
}
