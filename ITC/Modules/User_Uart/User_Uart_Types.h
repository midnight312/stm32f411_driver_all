#ifndef _User_Uart_Types_H_
#define _User_Uart_Types_H_

typedef enum __User_Uart_SlipStatus_t
{
	USER_UART_STOPBIT_1		= 0x1U,
	USER_UART_STOPBIT_2		= 0x2U

} User_Uart_StopBitCount_t;

typedef enum __User_Uart_ParityMode_t
{
	USER_UART_PARITY_NONE = 0x0U,
	USER_UART_PARITY_EVEN = 0x1U,
	USER_UART_PARITY_OOO  = 0x2U

} User_Uart_ParityMode_t;

typedef enum __User_Uart_SlipStatus_t
{
	USER_UART_SLIP_ENABLE		= 0x0U,
	USER_UART_SLIP_DISABLE		= 0x1U

} User_Uart_SlipStatus_t;

typedef struct __User_Uart_ConfigType
{
	uint8_t 					u8HWChanelID;
	uint32_t 					u32SourceClock;
	uint32_t                    u32Baudrate;
	User_Uart_ParityMode_t 		ParityMode;
	User_Uart_SlipStatus_t 		SlipStatus;
	User_Uart_StopBitCount_t 	StopBitCount;
}User_Uart_HWConfigType;

typedef struct
{
	uint8_t numberChanel;
	uint8_t numberHarware;
	User_Uart_HWConfigType *ChannelConfig;
} User_Uart_ConfigType;


























#endif  /* _User_Uart_Types_H_ */
