#ifndef __LEDS_H_
#define __LEDS_H_
#include "system.h"

sbit DAT = P1^1;		//定义管脚P1.1
sbit CLK = P1^0;		//定义管脚P1.0

void LED_Init(void);
void sendbyte(uint8_t byte); 	   	//发送字节的程序

#endif
