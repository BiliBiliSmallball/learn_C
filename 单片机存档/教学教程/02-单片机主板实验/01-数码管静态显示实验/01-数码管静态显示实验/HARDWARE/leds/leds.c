#include "leds.h"

uint8_t code tab[] = {0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,
					          0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};//0-F�����������ʾ��16������

void LED_Init(void)
{
	P1M1 = 0x00;
	P1M0 = 0xff;
}

void sendbyte(uint8_t byte) 	   	//�����ֽڵĳ���
{     
	uint8_t num,c;  
	num = tab[byte];		   	//ȡ����
	for(c = 0; c < 8; c++) 		//����8λ����
	{ 
		CLK = 0; 
		DAT = num&0x01; 		//�������λ����
		CLK = 1; 
		num>>=1; 				//��������һλ
	       
	} 
} 
