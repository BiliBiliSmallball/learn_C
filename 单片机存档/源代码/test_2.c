/*
使用两个口进行通信，让一个口控制另外一个口
2023-07-16
*/
#include <stdio.h>
#include <system.h>	  //要将他从外部文件夹放到工作去

void change(){
//设定一个口，有输入就换为0 
 	int i =0;
    do      
    {
       	P1 = 0x55;                //主程序
        Delay_ms(500);            //Get_Point(int);
		P1 = 0xaa;
		Delay_ms(500);
		i++;
    } while(i <= 9);
	P1 = 0x0f;
	Delay_ms(1000);
}


int main()
{
	System_Init();              //系统初始化
	P1_Mode_OUT_PP(0xff);		//设置P1口的初始化状态————
	P2_Mode_PullUp(0xff); 		//设置p0口

	//主程序
	change();

}