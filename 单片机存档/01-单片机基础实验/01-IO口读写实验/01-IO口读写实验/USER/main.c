/***************************************************************************
实验名称：	按键检测实验

实验模块：	STC8A核心板v2.1

实验接线：	P4上需要加上连接P3.2--INT0和P3.3--INT1的跳帽
				    
						
现象描述：	按下按键INT0，左边两个灯点亮。按下INT1，右边两个灯点亮
			    一个按键未按下则全部熄灭。

使用STC-ISP下载时请注意在【硬件选项】的第一项【输入用户程序运行是的IRC频率】
软件默认是11.0592MHz	但我们程序用的都是24MHz，所以我们需要手动输入或者下拉选择
24MHz然后再点击下载即可。然后即可看到右下方窗口提示
  . 用户设定频率: 24.000MHz
  . 调节后的频率: 24.000MHz
  . 频率调节误差: 0.000%
  
更新时间：2022.06.07
***************************************************************************/

#include <intrins.h>
#include "system.h"
#include "led.h"
#include "key.h"


void main(void)
{
	uint8_t key = 0;
	System_Init();						//系统初始化
	Key_Configure();					//按键初始化
	Led_Configure();					//LED初始化
	while(1)
	{
		//获取扫描键值
		key = Key_Scan();
		switch(key)
		{
			case KEY0_NUM:	LED0(1);	//点亮DS1
							LED1(1);	//点亮DS2
							break;
			case KEY1_NUM:	LED2(1);	//点亮DS3
							LED3(1);	//点亮DS4
							break;
			default:		LED0(0);	//LED全部熄灭
							LED1(0);	
							LED2(0);	
							LED3(0);
							break;
		}
		key=0;
	}
}

//                                      endfile
