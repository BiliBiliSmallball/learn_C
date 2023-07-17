/***************************************************************************
实验名称：脉冲驱动型蜂鸣器实验

实验模块：	STC8A核心板-V2.1、主板区 BUZZER-pulse蜂鸣器

实验接线：		STC8A核心板   -----------   BUZZER-pulse蜂鸣器
				       P1.2       -----------        PUL				
						   					           
						
现象描述：	蜂鸣器间断性鸣响

更新时间：2022.06.07
***************************************************************************/
#include "intrins.h"
#include "system.h"
#include "beep.h"


void main(void)
{
	uint16_t i = 0;
	System_Init();			 //系统初始化
	Beep_Configure();				//蜂鸣器初始化
	while(1)
	{
		for(i=0;i<250;i++)
		{
		BEEP(1);					//鸣叫蜂鸣器
		Delay_ms(1);				//延时
		BEEP(0);					//停止鸣叫蜂鸣器
	  Delay_ms(1);				//延时
		}				
    Delay_ms(500);				//延时		
	}
}

//                                      endfile
