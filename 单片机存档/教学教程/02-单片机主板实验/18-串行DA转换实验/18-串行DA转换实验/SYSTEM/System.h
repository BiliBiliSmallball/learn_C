#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include "STC8A.h"//包含系统头文件

#define uint8_t 	unsigned char
#define uint16_t 	unsigned int	
#define uint32_t 	unsigned long
	
//函数声明
void System_Init(void);
void Delay_ms(unsigned int ms);

#endif
