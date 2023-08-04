#ifndef __74HC245_H__
#define __74HC245_H__
#include "system.h"//包含系统头文件

sbit OE = P1^0;	//245输出允许
sbit TR = P1^1;	//发送、接收设置

void IO_Init(void);

#endif
