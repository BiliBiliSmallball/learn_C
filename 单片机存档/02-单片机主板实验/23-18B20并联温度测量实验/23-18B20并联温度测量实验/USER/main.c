/***************************************************************************
ʵ�����ƣ�	DS18B20�¶ȶ�ȡʵ��

ʵ��ģ�飺	STC8A���İ�v2.1����������12864ͼ��Һ��

ʵ����ߣ�	STC8A���İ�   ---------   Һ����ʾ����12864��
							P2.0      ---------      CS1
							P2.1      ---------      CS2
							P2.2      ---------      RS
							P2.3      ---------      RW
							P2.4      ---------      RE
            P0.0~P0.7   ---------      DB0~DB8

          STC8A���İ�   ---------   �¶ȴ�����
				      P2.7      ---------     1WIRE
														
����������	���������й��������ȼ���Ƿ����������ڣ�����������������ʾ�¶�

��    ע�������������J13�ڽ�������ñ���������ֻ��SEN2���á�

ʹ��STC-ISP����ʱ��ע���ڡ�Ӳ��ѡ��ĵ�һ������û����������ǵ�IRCƵ�ʡ�
���Ĭ����11.0592MHz	�����ǳ����õĶ���24MHz������������Ҫ�ֶ������������ѡ��
24MHzȻ���ٵ�����ؼ��ɡ�Ȼ�󼴿ɿ������·�������ʾ
  . �û��趨Ƶ��: 24.000MHz
  . ���ں��Ƶ��: 24.000MHz
  . Ƶ�ʵ������: 0.000%

����ʱ�䣺2018.9.14
***************************************************************************/

#include <intrins.h>
#include "system.h"
#include "lcd12864.h"
#include "DS18B20.h"
#include "stdio.h"

extern unsigned char DS18B20_SensorNum;
uint8_t Disbuf[6] = {"     "};
char ID[10] = {0};

void main(void)
{
    float temp = 0;
    uint16_t  temper;
    uint8_t i = 0;

    System_Init();						//ϵͳ��ʼ��
    LCD12864_Software_Init();       	//��ʼ��12864Һ��
    DS18B20_Init();

    while(1)
    {
        DS18B20_Search_Rom();

        if(DS18B20_SensorNum)
        {
            Show_Num(2, 0, " DS18B20 OK  ");
            Show_Num(0, 1, "Num : ");  //��ʾ����

            if(DS18B20_SensorNum == 1)
            {
                Show_Num(6, 1, "1");    				//��ʾ����
            }
            else if(DS18B20_SensorNum == 2)
            {
                Show_Num(6, 1, "2");    				//��ʾ����
            }

            for(i = 0; i < 2; i++)
            {
                Show_Num(0, 2, "temp1:");
                Show_Num(0, 3, "temp2:");
                Show_Hz(6, 2, 9);
                Show_Hz(6, 3, 9);
                temp = DS18B20_Get_Temp(i);//��ȡ�¶�
                temper = temp * 100;
                Disbuf[0] = temper / 1000 % 10 + 0x30;
                Disbuf[1] = temper / 100 % 10 + 0x30;
                Disbuf[2] = '.';
                Disbuf[3] = temper / 10 % 10 + 0x30;
                Disbuf[4] = temper % 10 + 0x30;
                Show_Num(6, 2 + i, (char*)Disbuf); //��ʾ�¶�

                if(DS18B20_SensorNum < 2)
                {
                    Show_Num(6, 3, "      ");
                    break;
                }
            }
        }
        else
        {

            ClearScreen(0);
            Delay_ms(500);
            Show_Num(2, 0, "DS18B20 ERROR");
        }

        Delay_ms(500);
    }
}

//                                      endfile
