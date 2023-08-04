#ifndef __KEY_H_
#define __KEY_H_

#include "system.h"

//�����˿�
#define KEY_PORT		P3					

//��������	
#define KEY0_PIN		PIN_2
#define KEY1_PIN		PIN_3

//�������·��صİ���ֵ
#define KEY0_NUM		(uint8_t)1		
#define KEY1_NUM		(uint8_t)2

sbit  KEY0=P3^2;
sbit  KEY1=P3^3;

void Key_Configure(void);			//������ʼ�����ú���
uint8_t Key_Scan(void);				//����ɨ�躯��

#endif

