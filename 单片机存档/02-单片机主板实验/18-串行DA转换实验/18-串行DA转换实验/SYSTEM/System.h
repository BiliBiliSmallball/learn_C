#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include "STC8A.h"//����ϵͳͷ�ļ�

#define uint8_t 	unsigned char
#define uint16_t 	unsigned int	
#define uint32_t 	unsigned long
	
//��������
void System_Init(void);
void Delay_ms(unsigned int ms);

#endif
