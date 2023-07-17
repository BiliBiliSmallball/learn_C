#ifndef __LCD1602_H__
#define __LCD1602_H__
#include "system.h"

sbit E  = P1^2;			//����ܽ�
sbit RW = P1^1;
sbit RS = P1^0;

void LCD1602Write_data(uint8_t i);	//LCD1602д����
void LCD1602Write_com(uint8_t i);	  //LCD1602дָ��
void LCD1602_Init(void);		        //LCD1602��ʼ��


#endif
