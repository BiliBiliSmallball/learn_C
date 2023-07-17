#include "74hc245.h"

void IO_Init(void)
{
	
	P0_Mode_OUT_PP(0xFF);
	P1_Mode_OUT_PP(0x03);
	
}

