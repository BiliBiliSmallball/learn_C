#ifndef __ENCODE_H_
#define __ENCODE_H_

#include <system.h>

#define	CODE_GPIO 	P2
#define B_PIN		PIN_5
#define A_PIN		PIN_6
#define C_PIN		PIN_7

#define B_IN()		P25
#define A_IN()		P26
#define D_IN()		P27

void Encode_Hardware_Init(void);
void Encode_Test(void);

#endif

