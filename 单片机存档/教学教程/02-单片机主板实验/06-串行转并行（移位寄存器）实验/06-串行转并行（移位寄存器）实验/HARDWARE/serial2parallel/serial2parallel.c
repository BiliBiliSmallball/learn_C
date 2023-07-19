#include "system.h"
#include "serial2parallel.h"

void Serial_Hardware_Init(void)
{
	P2_Mode_PullUp(Serial_SDA_PIN|Serial_SCL_PIN);
}

void Serial2Parallel(unsigned char byte) 	        //�����ֽڵĳ���
{     
	unsigned char c = 0;  
	for(c = 0; c < 8; c++) 		
	{ 
		SCL(0);
		SDA((byte&0x80));
		SCL(1);
		byte<<=1; 				        //��������һλ 
	} 
} 

