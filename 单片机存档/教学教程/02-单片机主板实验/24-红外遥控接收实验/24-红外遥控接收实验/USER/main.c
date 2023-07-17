/*************************************************************************************
实验名称： 红外收发实验

硬件模块：	STC8A核心板v2.1、主板区： 12864图形液晶、红外传输

硬件接线：	注：STC8A核心板P4上需要加上连接P3.2--INT0的跳帽

          STC8A核心板   -------------   12864图形液晶
							P2.0      -------------       CS1
							P2.1      -------------       CS2
							P2.2      -------------       RS
							P2.3      -------------       RW
							P2.4      -------------       RE
				 P0.0~P0.7      -------------       DB0~DB7

          STC8A核心板   -------------   红外传输
			      	P1.1      -------------     TXD
				      P2.7      -------------     RXD

实验现象：本实验需要两个实验箱，按上述接线分别接好每个实验箱上的接线，将程序分别下载到两个实验箱核心板上，
          将两个试验箱上的红外发射区相对，按下发射端核心板上的INT0按键发送数据液晶显示屏上显示红外发送OK，
          接收端液晶显示屏上显示接收到的红外数据。

          使用STC-ISP下载时请注意在【硬件选项】的第一项【输入用户程序运行是的IRC频率】
          软件默认是11.0592MHz	但我们程序用的都是24MHz，所以我们需要手动输入或者下拉选择
          24MHz然后再点击下载即可。然后即可看到右下方窗口提示
          . 用户设定频率: 24.000MHz
          . 调节后的频率: 24.000MHz
          . 频率调节误差: 0.000%

更新时间：   2022-06-08
****************************************************************************************/
#include <intrins.h>
#include "system.h"
#include "lcd12864.h"
#include "infrared.h"
#include "key.h"
#include "pwm.h"

char ir_senddata[9] = {"12345678"};
char ir_recvdata[9] = {"        "};

void main(void)
{
    uint8_t key_value = 0, i = 0;
    System_Init();						//系统初始化
    Infrared_Hardware_Init();           //红外初始化
    LCD12864_Software_Init();           //液晶初始化
    Show_Num(1, 0, "infrared test");

    while(1)
    {
        if(!KEY0)						//按键发送
        {
            Infrared_SendDate( ir_senddata, 8 );	//红外发送八个字节数据
            Show_Num(0, 1, "infrared send OK");
            Show_Num(0, 3, "data:");
            Show_Num(8, 3, ir_senddata);

            while(!KEY0);						//松开按键后清屏

            Show_Num(0, 1, "                ");
            Show_Num(0, 3, "                ");
        }

        if(!READ_RX())					//检测到接收
        {
            if(IR_RC_Time() == 1)			//是信息头
            {
                for(i = 0; i < 8; i++)		//接收八个字节
                {
                    ir_recvdata[i] = Infrared_RecvByte();
                }

                Show_Num(0, 2, "receive: OK");
                Show_Num(0, 3, "data:");
                Show_Num(8, 3, ir_recvdata);
                Delay_ms(500);					//等待500ms后清屏
                Show_Num(0, 2, "                ");
                Show_Num(0, 3, "                ");
            }
        }
    }
}

//                                      endfile
