/***************************************************************************
ʵ�����ƣ�	IC����дʵ��

ʵ��ģ�飺	STC8A���İ�v2.1��12864ͼ��Һ����IC��

ʵ����ߣ�	P4����Ҫ��������P3.2--INT0��P3.3--INT1����ñ
			    STC8A���İ�   ---------   Һ����ʾ����12864��
							P2.0      ---------      CS1
							P2.1      ---------      CS2
							P2.2      ---------      RS
							P2.3      ---------      RW
							P2.4      ---------      RE		   
				 P0.0~P0.7      ---------      DB0~DB7	
				 
            STC8A���İ�  ---------   IC����
				       P2.6      ---------   SCL
				       P2.7      ---------   SDA	    
						
����������	���������й��������ȼ���Ƿ����������ڣ������ڼ�����������Ļ��ʾ���¶�Ӧ������IC�����ж�����д��
			������������Ļ����ʾ��ICcard ERROR!����ʱ��������ߣ���Ԫ�����Ƿ��𺦡�
			ע��������ʹ�õİ���Ϊ���İ��ϵ�KEY1��д����KEY2��������

ʹ��STC-ISP����ʱ��ע���ڡ�Ӳ��ѡ��ĵ�һ������û����������ǵ�IRCƵ�ʡ�
���Ĭ����11.0592MHz	�����ǳ����õĶ���24MHz������������Ҫ�ֶ������������ѡ��
24MHzȻ���ٵ�����ؼ��ɡ�Ȼ�󼴿ɿ������·�������ʾ
  . �û��趨Ƶ��: 24.000MHz
  . ���ں��Ƶ��: 24.000MHz
  . Ƶ�ʵ������: 0.000%
  
����ʱ�䣺2022-06-08
***************************************************************************/

#include <intrins.h>
#include "system.h"
#include "iic.h"
#include "lcd12864.h"
#include "24C02.h"
#include "key.h"

//Ҫд�뵽24c01���ַ�������
const uint8_t TEXT_Buffer[]={" Hello world!"};//�ַ������������룬��󲻿ɳ���127�ֽ�����
#define SIZE sizeof(TEXT_Buffer)

void main(void)
{
	uint8_t key = 0;
	uint8_t datatemp[SIZE];
	System_Init();						//ϵͳ��ʼ��
	Key_Configure();					//������ʼ��
	IIC_Hardware_Init();	        	//��ʼ����IC�����ӵ�Ӳ���ӿ�	 	 	
    LCD12864_Software_Init();       	//��ʼ��12864Һ��
	while(1)
	{
		while(IC_24Cxx_Check())//��ⲻ��24c01
        {
            ClearScreen(0);//����
            Show_Num(2,1,"ICcard ERROR! ");
            Show_Num(2,2,"ICcard ERROR! ");
            Delay_ms(500);
            Show_Num(0,1,"                ");
            Show_Num(0,2,"                ");
            Delay_ms(500);
        }        
        Show_Num(0,0,"K1:Write K2:Read");   //��ʼ����
		//��ȡɨ���ֵ
		key = Key_Scan();
		switch(key)
		{
			case KEY0_NUM:	
				Show_Num(0,1,"Start WriteCard ");
				IC_24Cxx_Write(0,(uint8_t*)TEXT_Buffer,SIZE);
				Show_Num(0,2,"Write Finished!");//��ʾ�������
				Show_Num(0,3,"                ");//��ʾ�������ַ���
				Delay_ms(500);
				Delay_ms(500);
				break;
			case KEY1_NUM:	 
				Show_Num(0,1,"Start Read Card ");
				IC_24Cxx_Read(0,datatemp,SIZE);
				Delay_ms(1);
				Show_Num(0,2,"The Data Is:    ");//��ʾ�������
				Show_Num(0,3,(char*)datatemp);//��ʾ�������ַ���
				Delay_ms(500);
				Delay_ms(500);
				break;
			default:	
				break;
		}
		key=0;
	}
}

//                                      endfile
