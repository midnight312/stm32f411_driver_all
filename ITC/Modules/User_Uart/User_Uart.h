#ifndef _User_Uart_H_
#define _User_Uart_H_


extern void User_Uart_Init(User_Uart_ConfigType *UartConfig);
extern Std_ReturnType User_Uart_AsyncTransmit(uint8_t u8ChanelId, uint8_t* dataPtr, uint16_t dataLen);
extern Std_ReturnType User_Uart_AsyncReceive(uint8_t u8ChanelId, uint8_t* dataPtr, uint16_t dataLen, uint16_t *remain);
























#endif  /* _User_Uart_H_ */
