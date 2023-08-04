#ifndef __DS18B20_H_
#define __DS18B20_H_

#include "system.h"

uint8_t DS18B20_Init(void);
uint8_t DS18B20_Read_Byte(void);
uint8_t DS18B20_Read_Bit(void);
uint8_t DS18B20_Answer_Check(void);
void  DS18B20_GPIO_Config(void);
void  DS18B20_Mode_IPU(void);
void  DS18B20_Mode_Out(void);
void  DS18B20_Rst(void);
void  DS18B20_Search_Rom(void);
void  DS18B20_Write_Byte(uint8_t dat);
float DS18B20_Get_Temp(uint8_t i);


#endif
