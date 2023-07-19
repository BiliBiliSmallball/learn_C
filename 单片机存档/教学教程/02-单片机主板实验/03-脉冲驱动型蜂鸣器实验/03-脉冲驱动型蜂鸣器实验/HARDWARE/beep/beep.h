#ifndef __BEEP_H_
#define __BEEP_H_

#include "system.h"

#define BEEP(x) BEEP = x;

#define BEEP_TOGGLE() BEEP = !BEEP;

sbit BEEP = P1^2;

void Beep_Configure(void);		//·äÃùÆ÷³õÊ¼»¯ÅäÖÃº¯Êı


#endif




