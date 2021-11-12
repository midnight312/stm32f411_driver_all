/*
 * rtc.h
 *
 *  Created on: Aug 29, 2021
 *      Author: thanh
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include "main.h"

typedef struct RTC_TimeDate_TAG
{
	uint8_t hour;
	uint8_t min;
	uint8_t sec;

	uint8_t wday;
	uint8_t mday;
	uint8_t month;
	uint8_t year;
}RTC_TimeDate_t;
/*
 * @brief RTC LSE configuration
 */
void rtc_LSE_config(void);

/*
 * @brief RTC prephiral configuration
 */
void rtc_config(void);

/*
 * @brief RTC set Unix Counter
 */
void rtc_setUnixTime(uint32_t Unix);

/*
 * @brief RTC get Unix Counter
 */
uint32_t rtc_getUnixTime(void);

/*
 * @brief Set time and date
 * Note: no need to set week day
 */
void rtc_getTimeDate(RTC_TimeDate_t *pTimeDate);

/*
 * @brief Set time and date
 */
void rtc_setTimeDate(RTC_TimeDate_t *pTimeDate);



#endif /* INC_RTC_H_ */
