#include "system.h"
#include "led.h"
#include "exti.h"

/**************************************************
�������ƣ�Exti_Configure
����˵�����ⲿ�ж����ú���		
���������	��			
�� �� ֵ��	��			
**************************************************/
void Exti_Configure(void)
{
	EX0 = 1;   	//�����ⲿ�ж�0  ��P3.2
	IT0 = 1;	//�½��ش���   IT0=0ʱ �������½����ᴥ�� 
	EX1 = 1;   	//�����ⲿ�ж�1  ��P3.3
	IT1 = 1;	//�½��ش���   IT1=0ʱ �������½����ᴥ�� 
	EA = 1;		//�������ж�
}

/**************************************************
�������ƣ�Exti0_IRQHandler() interrupt INT0_VECTOR
����˵�����жϷ�����
			INT0_VECTOR 	�ⲿ�ж�0�ж�
���������	��			
�� �� ֵ��	��			
**************************************************/
void Exti0_IRQHandler() interrupt INT0_VECTOR
{
	LED0_TOGGLE();
	LED1_TOGGLE();
}

/**************************************************
�������ƣ�Exti1_IRQHandler() interrupt INT1_VECTOR
����˵�����жϷ�����
			INT1_VECTOR 	�ⲿ�ж�1�ж�
���������	��			
�� �� ֵ��	��			
**************************************************/
void Exti1_IRQHandler() interrupt INT1_VECTOR
{
	LED2_TOGGLE();
	LED3_TOGGLE();
}

//                                      endfile
