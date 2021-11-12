#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f411xe.h"



#define read_reg(addr,mask)  *((unsigned long int *)(addr)) &  mask
#define write_r(addr,value) *((unsigned long int *)(addr)) = value




#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
