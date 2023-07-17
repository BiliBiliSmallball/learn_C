#include "system.h"
#include "led.h"
#include "exti.h"

/**************************************************
函数名称：Exti_Configure
函数说明：外部中断配置函数		
输入参数：	无			
返 回 值：	无			
**************************************************/
void Exti_Configure(void)
{
	EX0 = 1;   	//开启外部中断0  即P3.2
	IT0 = 1;	//下降沿触发   IT0=0时 上升和下降都会触发 
	EX1 = 1;   	//开启外部中断1  即P3.3
	IT1 = 1;	//下降沿触发   IT1=0时 上升和下降都会触发 
	EA = 1;		//开启总中断
}

/**************************************************
函数名称：Exti0_IRQHandler() interrupt INT0_VECTOR
函数说明：中断服务函数
			INT0_VECTOR 	外部中断0中断
输入参数：	无			
返 回 值：	无			
**************************************************/
void Exti0_IRQHandler() interrupt INT0_VECTOR
{
	LED0_TOGGLE();
	LED1_TOGGLE();
}

/**************************************************
函数名称：Exti1_IRQHandler() interrupt INT1_VECTOR
函数说明：中断服务函数
			INT1_VECTOR 	外部中断1中断
输入参数：	无			
返 回 值：	无			
**************************************************/
void Exti1_IRQHandler() interrupt INT1_VECTOR
{
	LED2_TOGGLE();
	LED3_TOGGLE();
}

//                                      endfile
