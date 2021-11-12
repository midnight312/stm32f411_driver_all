/*
 * crc.h
 *
 *  Created on: Sep 1, 2021
 *      Author: thanh
 */

#ifndef INC_CRC_H_
#define INC_CRC_H_

#include "main.h"

/*
 * @brief CRC enable
 */
void crc_enable(void);
void crc_disable(void);

/*
 * @brief CRC reset
 */
void crc_reset(void);

/*
 * @brief CRC accumulate
 */
void crc_accumulate(uint32_t value32);

/*
 * @brief CRC read
 */
uint32_t crc_read(void);

#endif /* INC_CRC_H_ */
