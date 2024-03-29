/***************************************************************************
实验名称：  矩阵键盘实验

实验模块:   STC8A核心板、主板区：矩阵键盘、12864图形液晶

实验接线：  STC8A核心板   ----------   12864图形液晶
				    P0.0~P.07    ----------      BD0~BD7
							P2.0       ----------      CS1
							P2.1       ----------      CS2
							P2.2       ----------      RS
							P2.3       ----------      RW
							P2.4       ----------      EN
			
			     STC8A核心板   ----------	  矩阵键盘
			      P6.0~P6.7    ----------    ROW1~4 
						                           LI_NE1~4
						注：用8P排线连接核心板P6与矩阵按键MK1口												 
		
现象描述：  LCD12864显示矩阵按键值。

更新时间:  2022-06-07
***************************************************************************/

#include <intrins.h>
#include <system.h>
#include "lcd12864.h"
#include "key_4x4.h" 

void main(void)
{
	char num[2]  = {0};
	System_Init();
	LCD12864_Software_Init();			    //液晶初始化 
	Show_Num(1,1,"Key_Num:");
	while(1)
	{
		num[0] = Get_KeyValue();
		Show_Num(12,1,num);
	}
}
