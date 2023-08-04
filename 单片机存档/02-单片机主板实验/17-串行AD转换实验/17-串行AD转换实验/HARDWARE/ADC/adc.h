#ifndef __ADC_H__
#define __ADC_H__
#include "system.h"

sbit CLK = P1^0;  //时钟端口
sbit SDA = P1^1;  //数据端口
sbit CS  = P1^2;  //片选端口

void ADC_Init(void);
uint8_t read(void);

#endif