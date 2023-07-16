/*
使用两个口进行通信，让一个口控制另外一个口
2023-07-16
*/
#include <stdio.h>
#include <system.h>	  //要将他从外部文件夹放到工作去

void Get_Point(){
    static char key;
    switch (key){
    case key == 1:
        P1 = 0x7f;
        break;
    case key == 2:
        P1 = 0xbf;
        break;
    case key == 3:
        P1 = 0xcf;
        break;
    case key == 4:
        P1 = 0xdf;
        break;
    case key == 5:
        P1 = 0xf7;
        break;
    case key == 6:
        P1 = 0xfb;
        break;
    case key == 7:
        P1 = 0xfc;
        break;
    case key == 8:
        P1 = 0xfd;
        break;    
    default:
        break;
    }
}

int main()
{
	System_Init();              //系统初始化
	P1_Mode_OUT_PP(0xff);		//设置P1口的初始化状态
	P2_Mode_PullUp(0xff); 		//设置p0口

	//主程序
    Get_Point(int);
	while(1);
}