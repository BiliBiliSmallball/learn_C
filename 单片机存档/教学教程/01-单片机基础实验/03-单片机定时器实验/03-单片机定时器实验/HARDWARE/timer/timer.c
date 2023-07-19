#include "system.h"
#include "led.h"
#include "timer.h"

uint16_t time0_cnt = 0;
/**************************************************
函数名称：Timer0_Configure
函数说明：定时器0初始化配置函数
输入参数：	无			
返 回 值：	无			
**************************************************/
void Timer0_Configure(void)
{
	ClrBits(AUXR,T0x12);//定时器0时钟12T模式
	//设置定时器0模式 十六位自动重载方式
	ClrBits(TMOD,T0_GATE|T0_CT|T0_M1|T0_M0);
	//定时 1ms 触发一次中断 
	TL0 = 0x30;			//设置定时初值
	TH0 = 0xF8;			//设置定时初值
	TF0 = 0;			//清除TF0标志
	TR0 = 1;			//定时器0开始计时 
	ET0 = 1;			//使能T0中断
	EA	= 1;			//使能总中断    
}

/**************************************************
函数名称：Timer0_IRQHandler(void) interrupt TIMER0_VECTOR
函数说明：定时器0中断服务函数  TIMER0_VECTOR 定时器0中断	
输入参数：	无			
返 回 值：	无			
**************************************************/
void Timer0_IRQHandler(void) interrupt TIMER0_VECTOR
{
	time0_cnt++;				//计数器加1
	if(time0_cnt%1000==0)		//判断值计数值
	{
		LED0_TOGGLE();			//将LED0端口状态取反,频率为2Hz
	}
	if(time0_cnt%500==0)		//判断值计数值
	{
		LED1_TOGGLE();			//将LED1端口状态取反,频率为5Hz
	}
	if(time0_cnt%250==0)		//判断值计数值
	{
		LED2_TOGGLE();			//将LED2端口状态取反,频率为10Hz
	}
	if(time0_cnt%125==0)		//判断值计数值
	{
		LED3_TOGGLE();			//将LED3端口状态取反,频率为25Hz
	}
	if(time0_cnt==1000)			//判断值计数值
	{
		time0_cnt=0;			//计数器清零
	}
}

//                                      endfile
