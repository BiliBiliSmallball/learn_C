#ifndef __NIXIE_H__
#define __NIXIE_H__
#include "system.h"//包含系统头文件

#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P1 				//宏定义，将P2定义为数码管选择口

void Nixie_Init(void);

#endif
