#include "system.h"
#include "adc0809.h" 

/******************************************************************
函数名：	ADC0809_Hardware_Init
功能：	硬件初始化，设置连接芯片的GPIO口
参数：	无
返回值：	无
******************************************************************/
void ADC0809_Hardware_Init(void)
{
	P6_Mode_PullUp(PIN_ALL);
	P6_Mode_HighZ(PIN_ADC0809_EOC);
	P7_Mode_HighZ(PIN_ALL);
}

/******************************************************************
函数名：	ADC0809_Convert
功能：	ADC0809模数转化函数
参数：	无
返回值：	无
******************************************************************/
uint8_t ADC0809_Convert(uint8_t chlx)
{
	uint8_t temp = 0;
	//三个地址线选择通道
	_A_((chlx)&0x01);
	_B_((chlx>>1)&0x01);
	_C_((chlx>>2)&0x01);										
	Delay_us(2);
	//记录通道
	ADC0809_ALE_SET;
	Delay_us(2);
	ADC0809_START_SET;
	Delay_us(2);
	ADC0809_ALE_CLR;
	Delay_us(2);
	ADC0809_START_CLR;
	Delay_us(20);
	//等待传递回来的读取信号
	while(ADC0809_EOC_READ==1);
	//使能端高准备读取
	ADC0809_OE_SET;	 
	Delay_us(150);
	//获得采样值
	temp=ADC0809_DATA_READ;
	Delay_us(50);
	//使能端拉低读取完毕
	ADC0809_OE_CLR;
	//返回采样值
	return temp;
}
