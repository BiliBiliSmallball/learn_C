#include "system.h"//系统文件 不建议修改
#include <intrins.h>

/***********************************************
函数名称：Delay_ms
功    能：STC8系列单片机1ms延时程序
入口参数：ms:延时的毫秒数
返 回 值：无	
备    注：示波器实测：1.01ms，内部时钟：24MHz           
************************************************/
void Delay_ms(unsigned int ms)
{
  unsigned int i;
  while( (ms--) != 0)
  {
    for(i = 0; i < 1850; i++); 
  }             
}

/***********************************************
函数名称：Delay_us
功    能：STC8系列单片机1us延时程序
入口参数：us:延时的微秒数
返 回 值：无  
备    注：内部时钟：24MHz
微秒级延时有误差，在24MHz的系统频率下，执行一
条指令需要166ns左右，没有办法取得精准的1us
若需要精准的us延时，请使用定时器。
Delay_us(1);  约为1.7us
Delay_us(10);  约为12.5us
Delay_us(10);  约为117.4us
Delay_us(1000);  约为1165us
************************************************/
void Delay_us(uint16_t us)  
{
  uint8_t i;
  while (us--)
  {
    _nop_();
    _nop_();
    i = 3;
    while (--i);
  }
}

/***********************************************
函数名称：System_Init
功    能：单片机系统初始化
入口参数：无
返 回 值：无	
备    注：STC-ISP下载软件中选择IRC频率：24MHz	
          以下的函数和宏定义，请参考
		      STC8A.H文件中的注释
************************************************/
void System_Init(void)
{		
	Delay_ms(300);							        //延时等待上电稳定
	SetBits(P_SW2,EAXFR);					      //允许访问特殊功能寄存器
	SetBits(IRC24MCR,ENIRC24M);		      //使能内部24M IRC	
	while (!(IRC24MCR & IRC24MST));			//等待时钟稳定
	ClrBits(CKSEL,Bits_ALL);      			//选择内部24M IRC，时钟不输出
	ClrBits(CLKDIV,Bits_ALL);     			//主时钟不分频
	ClrBits(P_SW2,EAXFR);					      //关闭访问特殊功能寄存器 
	
	//复位脚用作IO口P54
	ClrBits(RSTCFG,P54RST);
	
	//全部端口设置为高阻	
	//P0端口设置为高阻
	P0_Mode_HighZ(PIN_ALL);
	//P1端口设置为高阻
	P1_Mode_HighZ(PIN_ALL);
	//P2端口设置为高阻
	P2_Mode_HighZ(PIN_ALL);
	//P4端口设置为高阻
	P4_Mode_HighZ(PIN_ALL);
	//P5端口设置为高阻
	P5_Mode_HighZ(PIN_ALL);
	//P6端口设置为高阻
	P6_Mode_HighZ(PIN_ALL);
	//P7端口设置为高阻
	P7_Mode_HighZ(PIN_ALL);	
	
	
	//将P30 P31 设置为准双向口，用于下载
	P3_Mode_PullUp(PIN_0|PIN_1);	
	//P3其他端口设置为高阻
	P3_Mode_HighZ(PIN_2|PIN_3|PIN_4|PIN_5|PIN_6|PIN_7);
}


