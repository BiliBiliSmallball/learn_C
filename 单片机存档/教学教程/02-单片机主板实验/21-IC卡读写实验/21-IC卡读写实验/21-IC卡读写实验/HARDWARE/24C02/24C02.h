#ifndef __24C02_H
#define __24C02_H

#include "system.h"

#define AT24C01		127
#define AT24C02		255
#define AT24C04		511
#define AT24C08		1023
#define AT24C16		2047
#define AT24C32		4095
#define AT24C64		8191
#define AT24C128	16383
#define AT24C256	32767  

#define EE_TYPE AT24C01

void IC_24Cxx_Init(void);
void IC_24Cxx_WaitLenByte(uint16_t WriteAddr,uint32_t wdata,uint8_t length);
uint32_t IC_24Cxx_ReadLenByte(uint16_t ReadAddr,uint8_t length);

void IC_24Cxx_Read(uint16_t ReadAddr,uint8_t *Buffer,uint16_t Buf_len);
void IC_24Cxx_Write(uint16_t WriteAddr,uint8_t *Buffer,uint16_t Buf_len);
uint8_t IC_24Cxx_Check(void);
void IC_24Cxx_Write_Byte(uint16_t WriteAddr,uint8_t wdata);
uint8_t IC_24Cxx_Read_Byte(uint16_t ReadAddr);


#endif


