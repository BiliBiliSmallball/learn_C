#include "leds.h"

uint8_t code tab[] = {0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,
					          0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};//0-F在数码管上显示的16进制数

void LED_Init(void)
{
	P1M1 = 0x00;
	P1M0 = 0xff;
}

void sendbyte(uint8_t byte) 	   	//发送字节的程序
{     
	uint8_t num,c;  
	num = tab[byte];		   	//取段码
	for(c = 0; c < 8; c++) 		//发送8位段码
	{ 
		CLK = 0; 
		DAT = num&0x01; 		//发送最低位数据
		CLK = 1; 
		num>>=1; 				//数据右移一位
	       
	} 
} 
