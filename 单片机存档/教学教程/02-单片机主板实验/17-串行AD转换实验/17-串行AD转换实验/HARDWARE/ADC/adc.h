#ifndef __ADC_H__
#define __ADC_H__
#include "system.h"

sbit CLK = P1^0;  //ʱ�Ӷ˿�
sbit SDA = P1^1;  //���ݶ˿�
sbit CS  = P1^2;  //Ƭѡ�˿�

void ADC_Init(void);
uint8_t read(void);

#endif