#include "system.h"
#include "adc0809.h" 

/******************************************************************
��������	ADC0809_Hardware_Init
���ܣ�	Ӳ����ʼ������������оƬ��GPIO��
������	��
����ֵ��	��
******************************************************************/
void ADC0809_Hardware_Init(void)
{
	P6_Mode_PullUp(PIN_ALL);
	P6_Mode_HighZ(PIN_ADC0809_EOC);
	P7_Mode_HighZ(PIN_ALL);
}

/******************************************************************
��������	ADC0809_Convert
���ܣ�	ADC0809ģ��ת������
������	��
����ֵ��	��
******************************************************************/
uint8_t ADC0809_Convert(uint8_t chlx)
{
	uint8_t temp = 0;
	//������ַ��ѡ��ͨ��
	_A_((chlx)&0x01);
	_B_((chlx>>1)&0x01);
	_C_((chlx>>2)&0x01);										
	Delay_us(2);
	//��¼ͨ��
	ADC0809_ALE_SET;
	Delay_us(2);
	ADC0809_START_SET;
	Delay_us(2);
	ADC0809_ALE_CLR;
	Delay_us(2);
	ADC0809_START_CLR;
	Delay_us(20);
	//�ȴ����ݻ����Ķ�ȡ�ź�
	while(ADC0809_EOC_READ==1);
	//ʹ�ܶ˸�׼����ȡ
	ADC0809_OE_SET;	 
	Delay_us(150);
	//��ò���ֵ
	temp=ADC0809_DATA_READ;
	Delay_us(50);
	//ʹ�ܶ����Ͷ�ȡ���
	ADC0809_OE_CLR;
	//���ز���ֵ
	return temp;
}
