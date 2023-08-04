/******************************************************************************
实验名称：字符液晶显示实验

实验模块：	STC8A核心板-V2.1、主板区 1602 字符液晶

实验接线：	STC8A核心板   --------------   1602 字符液晶
							P1.0      --------------      RS
							P1.1      --------------      RW
							P1.2      --------------      E
							P0.0      --------------      DB0
							P0.1      --------------      DB1
							P0.2      --------------      DB2
							P0.3      --------------      DB3
							P0.4      --------------      DB4
							P0.5      --------------      DB5
							P0.6      --------------      DB6
							P0.7      --------------      DB7	
      注： 程序下载后如果字符液晶上无内容显示，请将核心板P4区跳线帽全部拔掉								

现象描述： LCD1602液晶显示屏显示“1602 LCD TEST OK”、“HELLO EVERYONE！！”字样 

更新时间：2022.06.07
********************************************************************************/
#include "intrins.h"
#include "system.h"
#include "lcd1602.h"


void main(void)
{
    unsigned char Code1[] = "1602 LCD TEST OK";//Code1是要显示在字符液晶的第一行
    unsigned char Code2[] = "HELLO EVERYONE!!"; //Code2是要显示在字符液晶的第二行
    unsigned char m;

    System_Init();			 //系统初始化
    LCD1602_Init();

    while(1)
    {
        LCD1602Write_com(0x80 + 0x00);	//在第一行第一个显示Code1

        for(m = 0; m < 40; m++)
        {
            LCD1602Write_data(Code1[m]);

            Delay_ms(5);			//延时
        }

        LCD1602Write_com(0x80 + 0x40);		//在第二行第一个显示Code2

        for(m = 0; m < 40; m++)
        {

            LCD1602Write_data(Code2[m]);
            Delay_ms(5);			//延时
        }
    }
}

//                                      endfile
