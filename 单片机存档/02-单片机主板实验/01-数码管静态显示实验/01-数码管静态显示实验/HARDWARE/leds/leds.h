#ifndef __LEDS_H_
#define __LEDS_H_
#include "system.h"

sbit DAT = P1^1;		//����ܽ�P1.1
sbit CLK = P1^0;		//����ܽ�P1.0

void LED_Init(void);
void sendbyte(uint8_t byte); 	   	//�����ֽڵĳ���

#endif
