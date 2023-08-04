#ifndef __DAC_H__
#define __DAC_H__
#include "system.h"

sbit SCLK    = P2 ^ 0;
sbit Data_in = P2 ^ 1;
sbit LOAD    = P2 ^ 2;
sbit LDAC    = P2 ^ 3;

void DAC_Init(void);
void DAC_Start(uint8_t DA_DATA);
void Output_channel(uint8_t channel);
void Write_RNG(uint8_t RNG_value);

#endif