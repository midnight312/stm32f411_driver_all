#include "User_Uart_Cfg.h"


static const User_Uart_HWConfigType User_Uart_HWConfig[USER_UART_NUMBERCHANEL_USER]
{
	{
		USER_UART_CHANNEL_USART1,                  /* HW channel ID */
		USER_UART_SOURCECLOCK_CHANNEL_USART1,      /* Source clck for HW channel ID */
		USER_UART_BAUDRATECHANE_USART1,            /* Baudrate */
		USER_UART_PARITY_NONE,                     /* Parity Mode */
		USER_UART_STOPBIT_1,					   /* Stop bit */
		USER_UART_SLIP_DISABLE                     /* Use slip protocol */
	},
	{
		USER_UART_CHANNEL_USART2,                  /* HW channel ID */
		USER_UART_SOURCECLOCK_CHANNEL_USART2,      /* Source clck for HW channel ID */
		USER_UART_BAUDRATECHANE_USART2,            /* Baudrate */
		USER_UART_PARITY_NONE,                     /* Parity Mode */
		USER_UART_STOPBIT_1,					   /* Stop bit */
		USER_UART_SLIP_DISABLE                     /* Use slip protocol */
	}
};
