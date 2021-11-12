/*
 * crc.c
 *
 *  Created on: Sep 1, 2021
 *      Author: thanh
 */


#include "crc.h"

/*
 * @brief CRC enable
 */
void crc_enable(void)
{
	//Enable clock CRC
	RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN;
	//Initiate CRC reset
	crc_reset();
}
void crc_disable(void)
{
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_CRCEN);
}

/*
 * @brief CRC reset
 */
void crc_reset(void)
{
	CRC->CR = 1;
}

/*
 * @brief CRC accumulate
 */
void crc_accumulate(uint32_t value32)
{
	CRC->DR = value32;
}

/*
 * @brief CRC read
 */
uint32_t crc_read(void)
{
	return CRC->DR;
}
