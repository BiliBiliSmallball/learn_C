/***************************************************************************
实验名称：	DS18B20温度读取实验

实验模块：	STC8A核心板v2.1、主板区：12864图形液晶

实验接线：	STC8A核心板   ---------   液晶显示区（12864）
							P2.0      ---------      CS1
							P2.1      ---------      CS2
							P2.2      ---------      RS
							P2.3      ---------      RW
							P2.4      ---------      RE
            P0.0~P0.7   ---------      DB0~DB8

          STC8A核心板   ---------   温度传感器
				      P2.7      ---------     1WIRE
														
现象描述：	程序在运行过程中首先检测是否有器件存在，如有器件存在则显示温度

备    注：并联检测需在J13口接上跳线帽，单独检测只有SEN2可用。

使用STC-ISP下载时请注意在【硬件选项】的第一项【输入用户程序运行是的IRC频率】
软件默认是11.0592MHz	但我们程序用的都是24MHz，所以我们需要手动输入或者下拉选择
24MHz然后再点击下载即可。然后即可看到右下方窗口提示
  . 用户设定频率: 24.000MHz
  . 调节后的频率: 24.000MHz
  . 频率调节误差: 0.000%

更新时间：2018.9.14
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

    System_Init();						//系统初始化
    LCD12864_Software_Init();       	//初始化12864液晶
    DS18B20_Init();

    while(1)
    {
        DS18B20_Search_Rom();

        if(DS18B20_SensorNum)
        {
            Show_Num(2, 0, " DS18B20 OK  ");
            Show_Num(0, 1, "Num : ");  //显示数量

            if(DS18B20_SensorNum == 1)
            {
                Show_Num(6, 1, "1");    				//显示数量
            }
            else if(DS18B20_SensorNum == 2)
            {
                Show_Num(6, 1, "2");    				//显示数量
            }

            for(i = 0; i < 2; i++)
            {
                Show_Num(0, 2, "temp1:");
                Show_Num(0, 3, "temp2:");
                Show_Hz(6, 2, 9);
                Show_Hz(6, 3, 9);
                temp = DS18B20_Get_Temp(i);//获取温度
                temper = temp * 100;
                Disbuf[0] = temper / 1000 % 10 + 0x30;
                Disbuf[1] = temper / 100 % 10 + 0x30;
                Disbuf[2] = '.';
                Disbuf[3] = temper / 10 % 10 + 0x30;
                Disbuf[4] = temper % 10 + 0x30;
                Show_Num(6, 2 + i, (char*)Disbuf); //显示温度

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
