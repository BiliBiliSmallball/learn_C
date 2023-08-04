#include "adc.h"

void ADC_Init(void)
{
	
	P1M1 = 0x02;
	P1M0 = 0xfd;
	CLK=0;          //初始化时钟端口
	CS=1;        		//片选	
}

//读取转换数值
uint8_t read(void)
{
 	uint8_t i=0,value=0;
	CS=1;        	//片选
	Delay_us(100);    	//等待转换
	CS=0;
	Delay_us(3);
	for(i=0;i<8;i++)
	{
		CLK=1;	         //产生上升沿
		value=value<<1;  //数据左移一位
		if(SDA==1)
        value=value+1;  //读取数值
		CLK=0;
	}
	return value;        //返回数据
}