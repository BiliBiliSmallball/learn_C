#include "nixie.h"

void Nixie_Init(void)
{
	P0M1 = 0x00;
	P0M0 = 0xff;
	
	P1M1 = 0x00;
	P1M0 = 0xff;
}