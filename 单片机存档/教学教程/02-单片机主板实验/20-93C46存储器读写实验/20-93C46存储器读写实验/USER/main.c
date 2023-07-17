/****************************************************************************************************
ʵ�����ƣ�	93C46�洢����дʵ��

ʵ��ģ�飺	STC8A���İ�v2.1����������EEPROM��12864ͼ��Һ��

ʵ����ߣ�  STC8A���İ�   -------------   12864ͼ��Һ��
								P2.0      -------------       CS1
								P2.1      -------------       CS2
								P2.2      -------------       RS
								P2.3      -------------       RW
								P2.4      -------------       RE
					 P0.0~P0.7      -------------       DB0~DB7
           ע��STC8A���İ�P4����Ҫ��������P3.2--INT0��P3.3--INT1����ñ

             STC8A���İ�  -------------    EEPROM
								P6.4      -------------     CS
								P6.5      -------------     CLK
								P6.6      -------------     DI
								P6.7       -------------    O

����������	���������й��������ȼ���Ƿ����������ڣ�
            �������������������Ļ��ʾ���¶�Ӧ������93C46���ж�����д��
			      ������������Ļ����ʾ��93C46 ERROR!����ʱ��������ߡ�

ʹ��STC-ISP����ʱ��ע���ڡ�Ӳ��ѡ��ĵ�һ������û����������ǵ�IRCƵ�ʡ�
���Ĭ����11.0592MHz	�����ǳ����õĶ���24MHz������������Ҫ�ֶ������������ѡ��
24MHzȻ���ٵ�����ؼ��ɡ�Ȼ�󼴿ɿ������·�������ʾ
  . �û��趨Ƶ��: 24.000MHz
  . ���ں��Ƶ��: 24.000MHz
  . Ƶ�ʵ������: 0.000%

����ʱ�䣺2022-06-08
**********************************************************************************************************/

#include <intrins.h>
#include "system.h"
#include "lcd12864.h"
#include "key.h"
#include "93C46.h"

//Ҫд�뵽93C46���ַ�������
const uint8_t TEXT_Buffer[] = {" Hello world!"}; //�ַ������������룬��󲻿ɳ���127�ֽ�����
#define SIZE sizeof(TEXT_Buffer)

void main(void)
{
    uint8_t key = 0;
    uint8_t datatemp[SIZE];
    System_Init();						//ϵͳ��ʼ��
    Key_Configure();					//������ʼ��
    AT93C46_Hardwarw_Init();	        //��ʼ����93C46���ӵ�Ӳ���ӿ�
    LCD12864_Software_Init();       	//��ʼ��12864Һ��

    while(1)
    {
        while(AT93C46_Check())//��ⲻ��93C46
        {
            ClearScreen(0);//����
            Show_Num(2, 1, "93C46 ERROR!  ");
            Show_Num(2, 2, "93C46 ERROR!  ");
            Delay_ms(500);
            Show_Num(0, 1, "                ");
            Show_Num(0, 2, "                ");
            Delay_ms(500);
        }

        Show_Num(0, 0, "K1:Write K2:Read"); //��ʼ����
        //��ȡɨ���ֵ
        key = Key_Scan();

        switch(key)
        {
            case KEY0_NUM:
                Show_Num(0, 1, "StartWrite93C46");
                AT93C46_Write(0, (uint8_t*)TEXT_Buffer, SIZE);
                Show_Num(0, 2, "Write Finished!"); //��ʾ�������
                Show_Num(0, 3, "                "); //��ʾ�������ַ���
                Delay_ms(500);
                Delay_ms(500);
                break;

            case KEY1_NUM:
                Show_Num(0, 1, "StartReadAT93C46");
                AT93C46_Read(0, datatemp, SIZE);
                Delay_ms(1);
                Show_Num(0, 2, "The Data Is:    "); //��ʾ�������
                Show_Num(0, 3, (char*)datatemp); //��ʾ�������ַ���
                Delay_ms(500);
                Delay_ms(500);
                break;

            default:
                break;
        }

        key = 0;
    }
}

//                                      endfile
