#ifndef __74HC165_H__
#define __74HC165_H__
#include "system.h"

sbit SF  = P1^2;
sbit CLK = P1^0;
sbit SDA = P1^1;

void GPIO_Init(void);
uint8_t receive(void) ;

#endif
