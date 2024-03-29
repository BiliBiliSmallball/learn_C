/****************************************************************************************************
实验名称：	93C46存储器读写实验

实验模块：	STC8A核心板v2.1、主板区：EEPROM、12864图形液晶

实验接线：  STC8A核心板   -------------   12864图形液晶
								P2.0      -------------       CS1
								P2.1      -------------       CS2
								P2.2      -------------       RS
								P2.3      -------------       RW
								P2.4      -------------       RE
					 P0.0~P0.7      -------------       DB0~DB7
           注：STC8A核心板P4上需要加上连接P3.2--INT0和P3.3--INT1的跳帽

             STC8A核心板  -------------    EEPROM
								P6.4      -------------     CS
								P6.5      -------------     CLK
								P6.6      -------------     DI
								P6.7       -------------    O

现象描述：	程序在运行过程中首先检测是否有器件存在，
            如有器件存在则根据屏幕显示按下对应按键对93C46进行读或则写。
			      如无器件，屏幕会提示：93C46 ERROR!，这时候请检查接线。

使用STC-ISP下载时请注意在【硬件选项】的第一项【输入用户程序运行是的IRC频率】
软件默认是11.0592MHz	但我们程序用的都是24MHz，所以我们需要手动输入或者下拉选择
24MHz然后再点击下载即可。然后即可看到右下方窗口提示
  . 用户设定频率: 24.000MHz
  . 调节后的频率: 24.000MHz
  . 频率调节误差: 0.000%

更新时间：2022-06-08
**********************************************************************************************************/

#include <intrins.h>
#include "system.h"
#include "lcd12864.h"
#include "key.h"
#include "93C46.h"

//要写入到93C46的字符串数组
const uint8_t TEXT_Buffer[] = {" Hello world!"}; //字符串可任意输入，最大不可超过127字节数据
#define SIZE sizeof(TEXT_Buffer)

void main(void)
{
    uint8_t key = 0;
    uint8_t datatemp[SIZE];
    System_Init();						//系统初始化
    Key_Configure();					//按键初始化
    AT93C46_Hardwarw_Init();	        //初始化与93C46连接的硬件接口
    LCD12864_Software_Init();       	//初始化12864液晶

    while(1)
    {
        while(AT93C46_Check())//检测不到93C46
        {
            ClearScreen(0);//清屏
            Show_Num(2, 1, "93C46 ERROR!  ");
            Show_Num(2, 2, "93C46 ERROR!  ");
            Delay_ms(500);
            Show_Num(0, 1, "                ");
            Show_Num(0, 2, "                ");
            Delay_ms(500);
        }

        Show_Num(0, 0, "K1:Write K2:Read"); //初始界面
        //获取扫描键值
        key = Key_Scan();

        switch(key)
        {
            case KEY0_NUM:
                Show_Num(0, 1, "StartWrite93C46");
                AT93C46_Write(0, (uint8_t*)TEXT_Buffer, SIZE);
                Show_Num(0, 2, "Write Finished!"); //提示传送完成
                Show_Num(0, 3, "                "); //显示读到的字符串
                Delay_ms(500);
                Delay_ms(500);
                break;

            case KEY1_NUM:
                Show_Num(0, 1, "StartReadAT93C46");
                AT93C46_Read(0, datatemp, SIZE);
                Delay_ms(1);
                Show_Num(0, 2, "The Data Is:    "); //提示传送完成
                Show_Num(0, 3, (char*)datatemp); //显示读到的字符串
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
