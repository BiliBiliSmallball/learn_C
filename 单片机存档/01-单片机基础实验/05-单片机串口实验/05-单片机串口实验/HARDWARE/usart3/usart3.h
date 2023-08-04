#ifndef __USART3_H_
#define __USART3_H_

#include "system.h"
#include "intrins.h"

#define FOSC 24000000UL          //ϵͳƵ��

#define MAX_NUM 100				//�洢��������ֽ�

#define NONE_PARITY     0       //��У��
#define ODD_PARITY      1       //��У��
#define EVEN_PARITY     2       //żУ��
#define MARK_PARITY     3       //���У��
#define SPACE_PARITY    4       //�հ�У��

#define PARITYBIT NONE_PARITY 

extern bit busy;

extern uint8_t usart3_rx_buf[100];
extern uint8_t usart3_rx_start;

void Usart3_Configure(uint32_t baud);		//����3��ʼ�����ú���
void Usart3_SendChar(uint8_t Udat);		//����3���ͺ���	
void Usart3_SendString(uint8_t *PBuf);	//����3�����ַ���������

#endif
