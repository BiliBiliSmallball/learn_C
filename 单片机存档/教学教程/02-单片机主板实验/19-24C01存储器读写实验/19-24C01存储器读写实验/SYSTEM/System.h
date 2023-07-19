#ifndef __SYSTEM_H__
#define __SYSTEM_H__

//����ϵͳͷ�ļ�
#include "stc8a8k64s4a12.h"

#define uint8_t 	unsigned char
#define uint16_t 	unsigned int	
#define uint32_t 	unsigned long
	
//��������
void System_Init(void);
void Delay_ms(unsigned int ms);
void Delay_us(uint16_t us) ;
#endif