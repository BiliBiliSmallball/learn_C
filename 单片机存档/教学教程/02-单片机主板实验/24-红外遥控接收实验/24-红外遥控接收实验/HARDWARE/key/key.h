#ifndef __KEY_H_
#define __KEY_H_

#include "system.h"

//按键端口
#define KEY_PORT		P3					

//按键引脚	
#define KEY0_PIN		PIN_2
#define KEY1_PIN		PIN_3

//按键按下返回的按键值
#define KEY0_NUM		(uint8_t)1		
#define KEY1_NUM		(uint8_t)2

sbit  KEY0=P3^2;
sbit  KEY1=P3^3;

void Key_Configure(void);			//按键初始化配置函数
uint8_t Key_Scan(void);				//按键扫描函数

#endif

