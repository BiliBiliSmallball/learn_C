#include "beep.h"

/**************************************************
函数名称：Beep_Configure
函数说明：蜂鸣器初始化配置函数	
输入参数：	无			
返 回 值：	无			
**************************************************/
void Beep_Configure(void)
{
	P1_Mode_OUT_PP(0x04);	//设置P1^2端口为推挽输出模式
	BEEP(0);				//初始化蜂鸣器不鸣叫
}

//                                      endfile
