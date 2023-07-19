#include "system.h"
#include "infrared.h"
#include "key.h"
#include "pwm.h"
#include "lcd12864.h"
#include "stdio.h"
/**********************************************************
*功　能：红外硬件初始化
*参　数：无
*返回值：无
**********************************************************/
void Infrared_Hardware_Init(void)
{
    Key_Configure();			//按键发射
    Pwm1_Configure();			//TX
    P2_Mode_HighZ(PIN_7);
}

/**********************************************************
*功　能：分析红外信号
*参　数：无
*返回值：高电平信号数据
**********************************************************/
uint8_t IR_RC_Time(void)
{
    int l_time = 0, h_time = 0;
    char num[8] = {"0"};

    while(!READ_RX())		//先读低电平时长
    {
        l_time++;
        Delay_us(50);

        //超时溢出
        if(l_time > 400)//低电平超时20ms退出
            break;
    }

    while(READ_RX())		//先读低电平时长
    {
        h_time++;
        Delay_us(50);

        //超时溢出
        if(h_time > 200)//高电平超时10ms退出
            break;
    }

    if((l_time > 100) && (l_time < 200) && (h_time > 50) && (h_time < 100)) //150,75
    {
        return 1;//信息头
    }
    else if((l_time > 5) && (l_time < 15) && (h_time > 5) && (h_time < 15)) //10,10
    {
        return 2;//零码
    }
    else if((l_time > 5) && (l_time < 15) && (h_time > 15) && (h_time < 45)) //10,30
    {
        return 3;//一码
    }
    else
    {
        return 0;//错误码
    }
}

/**********************************************************
*功　能：红外发送一个字节
*参　数：发送的字节
*返回值：无
**********************************************************/
void Infrared_SendByte( uint8_t ir )
{
    uint8_t i = 0;

    for( i = 0; i < 8; i++ )
    {
        WRITE_IR(1);
        Delay_us(500);
        WRITE_IR(0);

        if( ir & (0x80 >> i ) )//先发字节高位
        {
            Delay_ms(1);
            Delay_us(500);
        }
        else
        {
            Delay_us(500);
        }
    }
}

/**********************************************************
*功　能：接收一个字节
*参　数：无
*返回值：接收的字节
**********************************************************/
uint8_t Infrared_RecvByte(void)
{
    uint8_t i = 0, dat = 0;

    for( i = 0; i < 8; i++ )
    {
        dat <<= 1;

        if(IR_RC_Time() == 3)
        {
            dat++;
        }
    }

    return dat;
}

/**********************************************************
*功　能：红外发送数据
*参　数：irdate：发送的数据的地址 lenght：数据长度
*返回值：无
**********************************************************/
void Infrared_SendDate( uint8_t *  irdate, uint8_t lenght )
{
    uint8_t i;
    WRITE_IR(1);
    Delay_ms(9);
    WRITE_IR(0);
    Delay_ms(4);
    Delay_us(500);

    for( i = 0; i < lenght; i++ )
    {
        Infrared_SendByte( irdate[i] );
    }

    WRITE_IR(1);
    Delay_us(560);
    WRITE_IR(0);
}


/**********************************************************
*功　能：控制开启/关闭载波
*参　数：num=0 关
		num=1 开
*返回值：无
**********************************************************/
void WRITE_IR(uint8_t num)
{
    if(num)
    {
        PWMCR = 0x80;
    }
    else
    {
        PWMCR = 0x00;
        P11 = 0;
    }

}


