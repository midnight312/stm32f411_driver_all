#include "User_Uart.h"
#include "User_Uart_Types.h"

static User_Uart_ConfigType *UartConfigPtr = NULL;

void User_Uart_Init(User_Uart_ConfigType *UartConfig)
{
	uint8_t u8ChannelCount;
	User_Uart_HWConfigType HWconfig;


	UartConfigPtf = UartConfig;

	/* Enable clock for UART */


	for(u8ChannelCount = 0u; u8ChannelCount < UartConfigPtr->numberChanel; u8ChannelCount ++)
	{
		HWconfig->ParityMode = UartConfigPtr->ChannelConfig[u8ChannelCount].ParityMode;
		HWconfig->SlipStatus = UartConfigPtr->ChannelConfig[u8ChannelCount].SlipStatus;
		HWconfig->StopBitCount = UartConfigPtr->ChannelConfig[u8ChannelCount].StopBitCount;
		HWconfig->u8HWChanelID = UartConfigPtr->ChannelConfig[u8ChannelCount].u8HWChanelID;
		HWconfig->u32SourceClock = UartConfigPtr->ChannelConfig[u8ChannelCount].u32SourceClock;
		HWconfig->u32Baudrate = UartConfigPtr->ChannelConfig[u8ChannelCount].u32Baudrate;

		User_Uart_Ipw_Init(&HWconfig);
	}

}

Std_ReturnType User_Uart_AsyncTransmit(uint8_t u8ChanelId, uint8_t* dataPtr, uint16_t dataLen)
{
	uint8_t u8conut;
	uint8_t ChannelID = 0xFFu;
	Std_ReturnType ret = E_NOT_OK;

	if(UartConfigPtr == NULL)
	{
		return E_NOT_OK;
	}
	for(u8cont = 0; u8conut < UartConfigPtr->numberChanel; u8conut++)
	{
		if(UartConfigPtr->ChannelConfig[u8conut].u8HWChanelID ==  u8ChanelId)
		{
			ChannelID = u8conut;
			break;
		}
	}
	if(ChannelID == 0xFFu)
	{
		return E_NOT_OK;
	}
	if(UartConfigPtr->ChannelConfig[ChannelID].SlipStatus == USER_UART_SLIP_ENABLE)
	{
		ret = User_Slip_SendFrame(u8ChanelId, dataPtr, dataLen);
	}
	else
	{
		ret = User_Uart_Ipw_AsyncTransmit(u8ChanelId, dataPtr, dataLen);
	}
	return ret;
}
Std_ReturnType User_Uart_AsyncReceive(uint8_t u8ChanelId, uint8_t* dataPtr, uint16_t dataLen, uint16_t *remain)
{
	uint8_t u8conut;
	uint8_t ChannelID = 0xFFu;
	uint16_t DataLength = 0x00u;
	Std_ReturnType ret = E_NOT_OK;

	if(UartConfigPtr == NULL)
	{
		return E_NOT_OK;
	}
	for(u8cont = 0; u8conut < UartConfigPtr->numberChanel; u8conut++)
	{
		if(UartConfigPtr->ChannelConfig[u8conut].u8HWChanelID ==  u8ChanelId)
		{
			ChannelID = u8conut;
			break;
		}
	}
	if(ChannelID == 0xFFu)
	{
		return E_NOT_OK;
	}
	if(UartConfigPtr->ChannelConfig[ChannelID].SlipStatus == USER_UART_SLIP_ENABLE)
	{
		/*
		ret = User_Slip_SendFrame(u8ChanelId, dataPtr, dataLen);
		if(DataLength > dataLen || E_NOT_OK == ret)
		{
			*remain = -dataLen;
			return E_NOT_OK;
		}
		if(DataLength <= dataLen)
		{
			*remain = DataLength - dataLen;
		}
		*/
	}
	else
	{
		ret = User_Uart_Ipw_AsyncTransmit(u8ChanelId, dataPtr, dataLen);
	}
	return ret;
}
