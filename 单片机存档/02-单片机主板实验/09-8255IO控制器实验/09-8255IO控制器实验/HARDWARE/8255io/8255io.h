#ifndef __8255IO_H_
#define __8255IO_H_

sbit RD_ = P3^0; 
sbit WR_ = P3^1; 
sbit CS_ = P3^2;   
sbit A1_ = P3^3;	
sbit A0_ = P3^4;   
  				
#define DATA_IO  P2

void Write_8255(char x,uint8_t y);
uint8_t Read_8255(char x);
void IO_8255_Init(void);
#endif