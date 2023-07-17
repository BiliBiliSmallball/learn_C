#include "system.h"//ϵͳ�ļ� �������޸�
#include <intrins.h>

/***********************************************
�������ƣ�Delay_ms
��    �ܣ�STC8ϵ�е�Ƭ��1ms��ʱ����
��ڲ�����ms:��ʱ�ĺ�����
�� �� ֵ����	
��    ע��ʾ����ʵ�⣺1.01ms���ڲ�ʱ�ӣ�24MHz           
************************************************/
void Delay_ms(unsigned int ms)
{
  unsigned int i;
  while( (ms--) != 0)
  {
    for(i = 0; i < 1850; i++); 
  }             
}

/***********************************************
�������ƣ�Delay_us
��    �ܣ�STC8ϵ�е�Ƭ��1us��ʱ����
��ڲ�����us:��ʱ��΢����
�� �� ֵ����  
��    ע���ڲ�ʱ�ӣ�24MHz
΢�뼶��ʱ������24MHz��ϵͳƵ���£�ִ��һ
��ָ����Ҫ166ns���ң�û�а취ȡ�þ�׼��1us
����Ҫ��׼��us��ʱ����ʹ�ö�ʱ����
Delay_us(1);  ԼΪ1.7us
Delay_us(10);  ԼΪ12.5us
Delay_us(10);  ԼΪ117.4us
Delay_us(1000);  ԼΪ1165us
************************************************/
void Delay_us(uint16_t us)  
{
  uint8_t i;
  while (us--)
  {
    _nop_();
    _nop_();
    i = 3;
    while (--i);
  }
}

/***********************************************
�������ƣ�System_Init
��    �ܣ���Ƭ��ϵͳ��ʼ��
��ڲ�������
�� �� ֵ����	
��    ע��STC-ISP���������ѡ��IRCƵ�ʣ�24MHz	
          ���µĺ����ͺ궨�壬��ο�
		      STC8A.H�ļ��е�ע��
************************************************/
void System_Init(void)
{		
	Delay_ms(300);							        //��ʱ�ȴ��ϵ��ȶ�
	SetBits(P_SW2,EAXFR);					      //����������⹦�ܼĴ���
	SetBits(IRC24MCR,ENIRC24M);		      //ʹ���ڲ�24M IRC	
	while (!(IRC24MCR & IRC24MST));			//�ȴ�ʱ���ȶ�
	ClrBits(CKSEL,Bits_ALL);      			//ѡ���ڲ�24M IRC��ʱ�Ӳ����
	ClrBits(CLKDIV,Bits_ALL);     			//��ʱ�Ӳ���Ƶ
	ClrBits(P_SW2,EAXFR);					      //�رշ������⹦�ܼĴ��� 
	
	//��λ������IO��P54
	ClrBits(RSTCFG,P54RST);
	
	//ȫ���˿�����Ϊ����	
	//P0�˿�����Ϊ����
	P0_Mode_HighZ(PIN_ALL);
	//P1�˿�����Ϊ����
	P1_Mode_HighZ(PIN_ALL);
	//P2�˿�����Ϊ����
	P2_Mode_HighZ(PIN_ALL);
	//P4�˿�����Ϊ����
	P4_Mode_HighZ(PIN_ALL);
	//P5�˿�����Ϊ����
	P5_Mode_HighZ(PIN_ALL);
	//P6�˿�����Ϊ����
	P6_Mode_HighZ(PIN_ALL);
	//P7�˿�����Ϊ����
	P7_Mode_HighZ(PIN_ALL);	
	
	
	//��P30 P31 ����Ϊ׼˫��ڣ���������
	P3_Mode_PullUp(PIN_0|PIN_1);	
	//P3�����˿�����Ϊ����
	P3_Mode_HighZ(PIN_2|PIN_3|PIN_4|PIN_5|PIN_6|PIN_7);
}


