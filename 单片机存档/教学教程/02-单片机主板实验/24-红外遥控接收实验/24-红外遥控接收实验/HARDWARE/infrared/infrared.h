#ifndef __INFRARED_H_
#define __INFRARED_H_

#include "system.h"

#define READ_RX()		P27

void Infrared_Hardware_Init(void);
void Infrared_SendDate( uint8_t *  irdate, uint8_t lenght );
uint8_t IR_RC_Time(void);
uint8_t Infrared_RecvByte(void);
void WRITE_IR(uint8_t num);


#endif
