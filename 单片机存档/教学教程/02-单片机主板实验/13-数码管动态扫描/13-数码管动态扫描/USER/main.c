/***************************************************************************
实验名称：数码管动态扫描

实验模块：	STC8A核心板-V2.1、主板区：动态扫描数码管

实验接线：	STC8A核心板   -----------   动态扫描数码管 	           
					 P0.0~P0.7    -----------      A~H(J6)
					 P1.0~P1.7    -----------      A7~A0(J5)
					 
现象描述： 8位数码管从左向右依次显示“0~7”

更新时间：2022.06.07
***************************************************************************/
#include "intrins.h"
#include "system.h"
#include "nixie.h"

uint8_t digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};    	//显示的数字数组，依次为0，1，..，7
uint8_t select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 			//选择数码管数组，依次选择1，2，..，8

void main(void)
{
	uint8_t i = 0;;
	System_Init();			 //系统初始化
	Nixie_Init();
	
	while(1)
	{
	 for(i=0;i<8;i++) 		//8个数码管轮流显示
		{
			SELECT=select[i]; 	//选择第i个数码管
			DIGI=0x90;
			DIGI=digivalue[i]; 	//显示i
			Delay_ms(1);
		} 
	}
}

//                                      endfile
