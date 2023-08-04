#include "system.h"
#include "usart3.h"

uint8_t usart3_rx_buf[MAX_NUM] = 0;
uint8_t usart3_rx_start = 0;

/**************************************************
函数名称：Usart3_Configure
函数说明：串口3初始化配置函数		
输入参数：baud 波特率			
返 回 值：	无			
**************************************************/
void Usart3_Configure(uint32_t baud)
{
 	S3CON = 0x10;
	T2L  = (65536 - FOSC / baud / 4);
    T2H  = (65536 - FOSC / baud / 4) >> 8;
    AUXR = 0x14;                		//启动定时器
    IE2 = ES3;                 			//使能串口3中断
    EA = 1;								//开启总中断
	SetBits(P_SW2,S3_S);				//串口3设置																
	P5_Mode_PullUp(PIN_0|PIN_1);		//设置为准双向口
}
/**************************************************
函数名称：Usart3_IRQHandler(void) interrupt UART_VECTOR
函数说明：串口3中断服务函数 UART3_VECTOR	串口3中断
输入参数：	无			
返 回 值：	无			
**************************************************/
void Usart3_IRQHandler(void) interrupt UART3_VECTOR using 1
{
    if (S3CON & S3RI)
    {	
		if(usart3_rx_start>=MAX_NUM)
			usart3_rx_start = 0;
        usart3_rx_buf[usart3_rx_start++] = S3BUF;                  		
        S3CON &= ~S3RI;         		
    }
	
}

/**************************************************
函数名称：Usart3_SendChar 
函数说明：串口3发送函数			
输入参数：Udat	1位16进制的数据		
返 回 值：	无			
**************************************************/
void Usart3_SendChar(uint8_t dat) 
{
	
    S3BUF = dat;					//写数据到数据寄存器
	while(!(S3CON&S3TI));
	S3CON&=~S3TI;
}

/**************************************************
函数名称：Usart3_SendString
函数说明：串口3发送字符串或数组			
输入参数：*PBuf 指向数组或者字符串
注意：若发送数组时，遇到0x00时，程序认为是数据的结尾
返 回 值：	无			
**************************************************/
void Usart3_SendString(uint8_t *PBuf)
{
	while (*PBuf)						//检测字符串结束标志
	{	
		Usart3_SendChar(*PBuf++);		//发送当前字符
	}
}

//                                      endfile
