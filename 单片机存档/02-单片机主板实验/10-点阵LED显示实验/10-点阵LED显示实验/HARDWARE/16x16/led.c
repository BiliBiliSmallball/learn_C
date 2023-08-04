#include "led.h"


void LED_Init(void)
{
	P0M1 = 0x00;
	P0M0 = 0xff;
	
	P1M1 = 0x00;
	P1M0 = 0xff;
	
	P2M1 = 0x00;
	P2M0 = 0xff;
	
	P3M1 = 0x00;
	P3M0 = 0xff;
	
}