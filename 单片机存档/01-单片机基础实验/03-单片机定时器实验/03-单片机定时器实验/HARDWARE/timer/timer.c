#include "system.h"
#include "led.h"
#include "timer.h"

uint16_t time0_cnt = 0;
/**************************************************
�������ƣ�Timer0_Configure
����˵������ʱ��0��ʼ�����ú���
���������	��			
�� �� ֵ��	��			
**************************************************/
void Timer0_Configure(void)
{
	ClrBits(AUXR,T0x12);//��ʱ��0ʱ��12Tģʽ
	//���ö�ʱ��0ģʽ ʮ��λ�Զ����ط�ʽ
	ClrBits(TMOD,T0_GATE|T0_CT|T0_M1|T0_M0);
	//��ʱ 1ms ����һ���ж� 
	TL0 = 0x30;			//���ö�ʱ��ֵ
	TH0 = 0xF8;			//���ö�ʱ��ֵ
	TF0 = 0;			//���TF0��־
	TR0 = 1;			//��ʱ��0��ʼ��ʱ 
	ET0 = 1;			//ʹ��T0�ж�
	EA	= 1;			//ʹ�����ж�    
}

/**************************************************
�������ƣ�Timer0_IRQHandler(void) interrupt TIMER0_VECTOR
����˵������ʱ��0�жϷ�����  TIMER0_VECTOR ��ʱ��0�ж�	
���������	��			
�� �� ֵ��	��			
**************************************************/
void Timer0_IRQHandler(void) interrupt TIMER0_VECTOR
{
	time0_cnt++;				//��������1
	if(time0_cnt%1000==0)		//�ж�ֵ����ֵ
	{
		LED0_TOGGLE();			//��LED0�˿�״̬ȡ��,Ƶ��Ϊ2Hz
	}
	if(time0_cnt%500==0)		//�ж�ֵ����ֵ
	{
		LED1_TOGGLE();			//��LED1�˿�״̬ȡ��,Ƶ��Ϊ5Hz
	}
	if(time0_cnt%250==0)		//�ж�ֵ����ֵ
	{
		LED2_TOGGLE();			//��LED2�˿�״̬ȡ��,Ƶ��Ϊ10Hz
	}
	if(time0_cnt%125==0)		//�ж�ֵ����ֵ
	{
		LED3_TOGGLE();			//��LED3�˿�״̬ȡ��,Ƶ��Ϊ25Hz
	}
	if(time0_cnt==1000)			//�ж�ֵ����ֵ
	{
		time0_cnt=0;			//����������
	}
}

//                                      endfile
