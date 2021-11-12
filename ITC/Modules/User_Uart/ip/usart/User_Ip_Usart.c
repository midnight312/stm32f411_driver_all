#include "Uset_Ip_Uart.h"
#define "User_Ip_Register.h"




static User_Ip_Usart_Type *const User_Ip_Usart_BaseAddress[USER_IP_INSTANCE_COUNT] = USER_IP_USART_BASE_PTRS;

extern void Uswr_Ip_Usart_DeInit(User_Uart_HWConfigType *HWConfig)
{

}

extern void Uswr_Ip_Usart_Init(User_Uart_HWConfigType *HWConfig)
{
	uint8_t u8ChannelID = HWConfig->u8HWChanelID;
	User_Ip_Usart_Type *Usart = User_Ip_Usart_BaseAddress[u8ChannelID];
	uint8_t u8temp;

	User_Ip_Usart_Deinit(Usart);
	Usart->CR1 &= ~USER_IP_USART_CR1_TE_MASK;
	Usart->CR1 &= ~USER_IP_USART_CR1_RE_MASK;
	//Set up for USART
	User_Ip_Usart_SetBaudrate(Usart, HWConfig->u32SourceClock, HWConfig->u32Baudrate);
	User_Ip_Usart_SetParityMode(Usart, HWConfig->ParityMode);
	User_Ip_Usart_SetStopBitCount(Usart, HWConfig->StopBitCount);
	/* Enable interrupt */

}
