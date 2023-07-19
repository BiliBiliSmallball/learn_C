/***************************************************************************
实验名称：	IC卡读写实验

实验模块：	STC8A核心板v2.1、12864图形液晶、IC卡

实验接线：	P4上需要加上连接P3.2--INT0和P3.3--INT1的跳帽
			    STC8A核心板   ---------   液晶显示区（12864）
							P2.0      ---------      CS1
							P2.1      ---------      CS2
							P2.2      ---------      RS
							P2.3      ---------      RW
							P2.4      ---------      RE		   
				 P0.0~P0.7      ---------      DB0~DB7	
				 
            STC8A核心板  ---------   IC卡区
				       P2.6      ---------   SCL
				       P2.7      ---------   SDA	    
						
现象描述：	程序在运行过程中首先检测是否有器件存在，如有期间存在则根据屏幕显示按下对应按键对IC卡进行读或则写。
			如无器件，屏幕会提示：ICcard ERROR!，这时候请检查接线，和元器件是否损害。
			注：程序中使用的按键为核心板上的KEY1（写）、KEY2（读）。

使用STC-ISP下载时请注意在【硬件选项】的第一项【输入用户程序运行是的IRC频率】
软件默认是11.0592MHz	但我们程序用的都是24MHz，所以我们需要手动输入或者下拉选择
24MHz然后再点击下载即可。然后即可看到右下方窗口提示
  . 用户设定频率: 24.000MHz
  . 调节后的频率: 24.000MHz
  . 频率调节误差: 0.000%
  
更新时间：2022-06-08
***************************************************************************/

#include <intrins.h>
#include "system.h"
#include "iic.h"
#include "lcd12864.h"
#include "24C02.h"
#include "key.h"

//要写入到24c01的字符串数组
const uint8_t TEXT_Buffer[]={" Hello world!"};//字符串可任意输入，最大不可超过127字节数据
#define SIZE sizeof(TEXT_Buffer)

void main(void)
{
	uint8_t key = 0;
	uint8_t datatemp[SIZE];
	System_Init();						//系统初始化
	Key_Configure();					//按键初始化
	IIC_Hardware_Init();	        	//初始化与IC卡连接的硬件接口	 	 	
    LCD12864_Software_Init();       	//初始化12864液晶
	while(1)
	{
		while(IC_24Cxx_Check())//检测不到24c01
        {
            ClearScreen(0);//清屏
            Show_Num(2,1,"ICcard ERROR! ");
            Show_Num(2,2,"ICcard ERROR! ");
            Delay_ms(500);
            Show_Num(0,1,"                ");
            Show_Num(0,2,"                ");
            Delay_ms(500);
        }        
        Show_Num(0,0,"K1:Write K2:Read");   //初始界面
		//获取扫描键值
		key = Key_Scan();
		switch(key)
		{
			case KEY0_NUM:	
				Show_Num(0,1,"Start WriteCard ");
				IC_24Cxx_Write(0,(uint8_t*)TEXT_Buffer,SIZE);
				Show_Num(0,2,"Write Finished!");//提示传送完成
				Show_Num(0,3,"                ");//显示读到的字符串
				Delay_ms(500);
				Delay_ms(500);
				break;
			case KEY1_NUM:	 
				Show_Num(0,1,"Start Read Card ");
				IC_24Cxx_Read(0,datatemp,SIZE);
				Delay_ms(1);
				Show_Num(0,2,"The Data Is:    ");//提示传送完成
				Show_Num(0,3,(char*)datatemp);//显示读到的字符串
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
