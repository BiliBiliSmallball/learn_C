#include "system.h"
#include "usart3.h"

uint8_t usart3_rx_buf[MAX_NUM] = 0;
uint8_t usart3_rx_start = 0;

/**************************************************
�������ƣ�Usart3_Configure
����˵��������3��ʼ�����ú���		
���������baud ������			
�� �� ֵ��	��			
**************************************************/
void Usart3_Configure(uint32_t baud)
{
 	S3CON = 0x10;
	T2L  = (65536 - FOSC / baud / 4);
    T2H  = (65536 - FOSC / baud / 4) >> 8;
    AUXR = 0x14;                		//������ʱ��
    IE2 = ES3;                 			//ʹ�ܴ���3�ж�
    EA = 1;								//�������ж�
	SetBits(P_SW2,S3_S);				//����3����																
	P5_Mode_PullUp(PIN_0|PIN_1);		//����Ϊ׼˫���
}
/**************************************************
�������ƣ�Usart3_IRQHandler(void) interrupt UART_VECTOR
����˵��������3�жϷ����� UART3_VECTOR	����3�ж�
���������	��			
�� �� ֵ��	��			
**************************************************/
void Usart3_IRQHandler(void) interrupt UART3_VECTOR using 1
{
    if (S3CON & S3RI)
    {	
		if(usart3_rx_start>=MAX_NUM)
			usart3_rx_start = 0;
        usart3_rx_buf[usart3_rx_start++] = S3BUF;                  		
        S3CON &= ~S3RI;         		
    }
	
}

/**************************************************
�������ƣ�Usart3_SendChar 
����˵��������3���ͺ���			
���������Udat	1λ16���Ƶ�����		
�� �� ֵ��	��			
**************************************************/
void Usart3_SendChar(uint8_t dat) 
{
	
    S3BUF = dat;					//д���ݵ����ݼĴ���
	while(!(S3CON&S3TI));
	S3CON&=~S3TI;
}

/**************************************************
�������ƣ�Usart3_SendString
����˵��������3�����ַ���������			
���������*PBuf ָ����������ַ���
ע�⣺����������ʱ������0x00ʱ��������Ϊ�����ݵĽ�β
�� �� ֵ��	��			
**************************************************/
void Usart3_SendString(uint8_t *PBuf)
{
	while (*PBuf)						//����ַ���������־
	{	
		Usart3_SendChar(*PBuf++);		//���͵�ǰ�ַ�
	}
}

//                                      endfile
