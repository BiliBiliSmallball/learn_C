#ifndef __USART3_H_
#define __USART3_H_

#include "system.h"
#include "intrins.h"

#define FOSC 24000000UL          //系统频率

#define MAX_NUM 100				//存储数据最大字节

#define NONE_PARITY     0       //无校验
#define ODD_PARITY      1       //奇校验
#define EVEN_PARITY     2       //偶校验
#define MARK_PARITY     3       //标记校验
#define SPACE_PARITY    4       //空白校验

#define PARITYBIT NONE_PARITY 

extern bit busy;

extern uint8_t usart3_rx_buf[100];
extern uint8_t usart3_rx_start;

void Usart3_Configure(uint32_t baud);		//串口3初始化配置函数
void Usart3_SendChar(uint8_t Udat);		//串口3发送函数	
void Usart3_SendString(uint8_t *PBuf);	//串口3发送字符串或数组

#endif
