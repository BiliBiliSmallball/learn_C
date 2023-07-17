#ifndef __93C46_H
#define __93C46_H

#include "system.h"

#define SPI_GPIO	P6

#define SPI_CS_PIN 	PIN_4
#define SPI_SCL_PIN PIN_5
#define SPI_DO_PIN 	PIN_6
#define SPI_DI_PIN 	PIN_7

#define CS(x)       x?(SetBits(SPI_GPIO,SPI_CS_PIN)):(ClrBits(SPI_GPIO,SPI_CS_PIN))		                   
#define SCL(x)      x?(SetBits(SPI_GPIO,SPI_SCL_PIN)):(ClrBits(SPI_GPIO,SPI_SCL_PIN))               

#define DI()  	    P67                 
#define DO(x)     	x?(SetBits(SPI_GPIO,SPI_DO_PIN)):(ClrBits(SPI_GPIO,SPI_DO_PIN))	                    

void AT93C46_Hardwarw_Init(void);
void Write46(unsigned char indata);
unsigned char Read46(void);
void Sendbit (uint8_t IO);
void EWEN46 (void);
void EWDS46 (void);
void ERAL46 (void);
char AT93C46_Read_Byte (unsigned char addr);
void AT93C46_Write_Byte (unsigned char addr,char thedata);
void AT93C46_Read(uint16_t ReadAddr,uint8_t *Buffer,uint16_t Buf_len);
void AT93C46_Write(uint16_t WriteAddr,uint8_t *Buffer,uint16_t Buf_len);
uint8_t AT93C46_Check(void);

#endif
