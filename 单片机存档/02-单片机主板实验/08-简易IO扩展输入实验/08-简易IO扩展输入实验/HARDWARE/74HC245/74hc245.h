#ifndef __74HC245_H__
#define __74HC245_H__
#include "system.h"//����ϵͳͷ�ļ�

sbit OE = P1^0;	//245�������
sbit TR = P1^1;	//���͡���������

void IO_Init(void);

#endif
