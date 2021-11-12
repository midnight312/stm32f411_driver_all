/*
 * rtc.c
 *
 *  Created on: Aug 29, 2021
 *      Author: thanh
 */

#include "rtc.h"

/*
 * @brief RTC LSE configuration
 */
void rtc_LSE_config(void)
{
	//Enable PWR clock
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	//Enable write access to backup domain
	PWR->CR &= ~PWR_CR_DBP;
	PWR->CR |= PWR_CR_DBP;
	//Check if LSE is allready to clock source -->return
	uint32_t RCC_bdcr = RCC->BDCR;
	RCC->CSR |= RCC_CSR_LSION;
	while(RCC->CR & RCC_CSR_LSIRDY == 0);
	if((RCC_bdcr & RCC_BDCR_RTCSEL_1) && (RCC_bdcr & ~RCC_BDCR_RTCSEL_0))
	{
		printf("LSI allready sellect! \n");
		return;
	}
	RCC->CSR |= RCC_CSR_LSION;
	while(RCC->CR & RCC_CSR_LSIRDY == 0);
	//Reset backup domain (change clock source)
	__IO uint32_t tempRead = 0;
	tempRead = (RCC->BDCR & ~(RCC_BDCR_RTCSEL));
	RCC->BDCR = RCC_BDCR_BDRST;
	RCC->BDCR = 0;
	//Restore value
	RCC->BDCR = tempRead;
	//Enable LSE and wait for ready
	//RCC->BDCR |= RCC_BDCR_LSEON;
	//while(!(RCC->BDCR & RCC_BDCR_LSIRDY));
	//Sellect LSE as source
	RCC->BDCR |= RCC_BDCR_RTCSEL_1;
	//Enable RTC
	RCC->BDCR |= RCC_BDCR_RTCEN;
}

/*
 * @brief RTC prephiral configuration
 */
void rtc_config(void)
{
	//Connect to shadow
	RTC->CR &= ~RTC_CR_BYPSHAD;
	//RTC->CR |= RTC_CR_BYPSHAD;
	RTC->WPR = 0xCA;
	RTC->WPR = 0x53;
	//Access shadow register
	RTC->CR &= ~(RTC_CR_BYPSHAD);
	//Set INT
	RTC->ISR |= RTC_ISR_INIT;
	while(!(RTC->ISR & RTC_ISR_INITF));
	//Set clock 1HZ
	RTC->PRER &= ~(RTC_PRER_PREDIV_A | RTC_PRER_PREDIV_S);
	RTC->PRER |= (0x7F << 16) | (0x2FFF << 0);

	RTC->TR |= 1 << 19;

	//SET TIME
	//Convert Typedef Time Date into time.h library structure
	struct tm myTime;
	struct tm *myTimePtr = &myTime;
	time_t timeSecs;
	//Copy 	parameter from typedef to time library specific
	myTimePtr->tm_hour = 0;
	myTimePtr->tm_min = 0;
	myTimePtr->tm_sec  = 0;

	myTimePtr->tm_mday = 1;
	myTimePtr->tm_mon = 10;
	myTimePtr->tm_year = 2021;
	//Call make time function to convert nomal timeDate to Unix counter
	timeSecs = mktime(myTimePtr);
	//Set STM32 RTC counter value
	rtc_setUnixTime((uint32_t)timeSecs);
	//Reset INT
	RTC->ISR &= ~RTC_ISR_INIT;


	//Enable alarm A
	//RTC->CR |= RTC_CR_ALRAE;
	//RTC->CR |= RTC_CR_ALRAIE;
	//
	//Check for ongoing operation

	//Enter configuration
	//Set prescaler
	//Exit initialisation

}
/*
 * @brief RTC set Unix Counter
 */
void rtc_setUnixTime(uint32_t Unix)
{
	RTC->SSR = Unix;
}

/*
 * @brief RTC get Unix Counter
 */
uint32_t rtc_getUnixTime(void)
{
	return (uint32_t)(RTC->SSR);
}

/*
 * @brief Set time and date
 * Note: no need to set week day
 */
void rtc_getTimeDate(RTC_TimeDate_t *pTimeDate)
{
	struct tm myTime;
	struct tm *myTimePtr = &myTime;
	time_t timeSecs;
	//Get STM32 Unix counter

	timeSecs = (time_t)rtc_getUnixTime();
	//time.h library convert back to nomal timeDate
	myTimePtr = gmtime(&timeSecs);
	//Return to user
	pTimeDate->hour = myTimePtr->tm_hour;
	pTimeDate->min = myTimePtr->tm_min;
	pTimeDate->sec = myTimePtr->tm_sec;

	pTimeDate->wday = myTimePtr->tm_mday ;
	pTimeDate->month = myTimePtr->tm_mon +1;
	pTimeDate->year = myTimePtr->tm_year ;
}

/*
 * @brief Set time and date
 */
void rtc_setTimeDate(RTC_TimeDate_t *pTimeDate)
{
	//Set INT
	RTC->ISR |= RTC_ISR_INIT;
	//Convert Typedef Time Date into time.h library structure
	struct tm myTime;
	struct tm *myTimePtr = &myTime;
	time_t timeSecs;
	//Copy 	parameter from typedef to time library specific
	myTimePtr->tm_hour = pTimeDate->hour;
	myTimePtr->tm_min = pTimeDate->min;
	myTimePtr->tm_sec  = pTimeDate->sec;

	myTimePtr->tm_mday = pTimeDate->wday;
	myTimePtr->tm_mon = pTimeDate->month - 1;
	myTimePtr->tm_year = pTimeDate->year;
	//Call make time function to convert nomal timeDate to Unix counter
	timeSecs = mktime(myTimePtr);
	//Set STM32 RTC counter value
	rtc_setUnixTime((uint32_t)timeSecs);
	//Reset INT
	RTC->ISR &= ~RTC_ISR_INIT;
}
