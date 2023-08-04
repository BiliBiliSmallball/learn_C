#include "adc.h"

void ADC_Init(void)
{
	
	P1M1 = 0x02;
	P1M0 = 0xfd;
	CLK=0;          //��ʼ��ʱ�Ӷ˿�
	CS=1;        		//Ƭѡ	
}

//��ȡת����ֵ
uint8_t read(void)
{
 	uint8_t i=0,value=0;
	CS=1;        	//Ƭѡ
	Delay_us(100);    	//�ȴ�ת��
	CS=0;
	Delay_us(3);
	for(i=0;i<8;i++)
	{
		CLK=1;	         //����������
		value=value<<1;  //��������һλ
		if(SDA==1)
        value=value+1;  //��ȡ��ֵ
		CLK=0;
	}
	return value;        //��������
}