#include "74hc245.h"

void IO_Init(void)
{
	
	P0M1 = 0xff;
	P0M0 = 0x00;
	
	P1M1 = 0x00;
	P1M0 = 0xff;
	
	P2M1 = 0x00;
	P2M0 = 0xff;
	
}

