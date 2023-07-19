#ifndef __SERIAL2PARALLEL_H_
#define __SERIAL2PARALLEL_H_

#include "system.h"

#define Serial_GPIO		P2
#define Serial_SDA_PIN	PIN_0
#define Serial_SCL_PIN	PIN_1

#define SCL(x)	x?SetBits(Serial_GPIO,Serial_SCL_PIN):ClrBits(Serial_GPIO,Serial_SCL_PIN)
#define SDA(x)	x?SetBits(Serial_GPIO,Serial_SDA_PIN):ClrBits(Serial_GPIO,Serial_SDA_PIN)

void Serial_Hardware_Init(void);
void Serial2Parallel(unsigned char byte);




#endif


