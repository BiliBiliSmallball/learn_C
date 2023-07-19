/***************************************************************************************
实验名称：	单片机串口实验

实验模块：	STC8A核心板-V2.1

实验接线：	 STC8A核心板   	---------   PC
				   USB_TTL P1     --------- USB接口
			     注：STC8A核心板用扁对方口USB连接电脑
				
现象描述：	使用扁对方USB线连接核心板和电脑。注意：连接核心板USB_TTL接口，不是下载接口。
			    打开串口调试助手即可进行串口通信

使用STC-ISP下载时请注意在【硬件选项】的第一项【输入用户程序运行时的IRC频率】
软件默认是11.0592MHz	但我们程序用的都是24MHz，所以我们需要手动输入或者下拉选择
24MHz然后再点击下载即可。然后即可看到右下方窗口提示
  . 用户设定频率: 24.000MHz
  . 调节后的频率: 24.000MHz
  . 频率调节误差: 0.000%

更新时间：2022.06.07
*****************************************************************************************/

#include <intrins.h>
#include <stdio.h>
#include "system.h"
#include "led.h"
#include "usart3.h"

void main(void)
{	
	System_Init();										//系统初始化
	Led_Configure();									//LED初始化
	Usart3_Configure(115200);							//串口三初始化
	while(1)
	{	
		Usart3_SendString("HELLO_BOY\n");				//循环打印字符
		Delay_ms(250);									//延时
		LED0_TOGGLE();									//闪烁LED0表示正在运行
		if(usart3_rx_start>0)							//检测是否有数据输入
		{
			Delay_ms(100);								//延时
			Usart3_SendString(usart3_rx_buf);			//发送接收到的数据
			while(usart3_rx_start)						//循环
			{
				usart3_rx_buf[usart3_rx_start] = 0;		//清除接收到并已经发送出去的数据
				usart3_rx_start --;
			}
		}
		Delay_ms(250);									//延时
	}
}

//                                      endfile
