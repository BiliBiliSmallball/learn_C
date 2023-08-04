//头函数
#include<stdio.h>
#include<system.h>

//设定变量
SetBits LED1=P1^0;//端口
SetBits LED2=P1^1;
SetBits KEY1=P2^0;
SetBits KEY2=P2^1;


int main(){
	System_Init();//系统初始化
	P1_Mode_OUT_PP(0x7f);//控制灯的口初始化
	P2_Mode_PullUp(0x00);//开关都设成00
	if (KEY1 == 0)
	{
		LED1=0;
	}
	else if (KEY2 == 0)
	{
		LED2=1;
	}
	return 0;
}