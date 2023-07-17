#ifndef __LED_H_
#define __LED_H_

#include "system.h"

#define LED0(x) LED0 = !x;
#define LED1(x) LED1 = !x;
#define LED2(x) LED2 = !x;
#define LED3(x) LED3 = !x;

#define LED0_TOGGLE() LED0 = !LED0;
#define LED1_TOGGLE() LED1 = !LED1;
#define LED2_TOGGLE() LED2 = !LED2;
#define LED3_TOGGLE() LED3 = !LED3;

sbit LED0 = P7^0;
sbit LED1 = P7^1;
sbit LED2 = P7^2;
sbit LED3 = P7^3;

void Led_Configure(void);		//LED≥ı ºªØ≈‰÷√∫Ø ˝


#endif




