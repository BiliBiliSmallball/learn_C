#ifndef __DAC0832_H__
#define __DAC0832_H__
#include "system.h"

sbit CS    = P0^0;
sbit WR_EN = P0^1;
sbit ILE   = P0^2;
sbit XFRE  = P0^3;

void DAC_Init(void);
void sin(void);

#endif
