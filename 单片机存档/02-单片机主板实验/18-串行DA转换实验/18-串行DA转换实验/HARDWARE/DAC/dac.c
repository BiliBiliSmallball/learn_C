#include "dac.h"

/***********************************************
函数名称：DAC_Init
功    能：IO初始化
入口参数：无
返 回 值：无
************************************************/
void DAC_Init(void)
{
    P2M1 = 0x00;			 //将P2^0~P2^3 设置为推挽输出模式
    P2M0 = 0xff;
}

/***********************************************
函数名称：DAC_Start
功    能：DA转换函数
入口参数：无
返 回 值：无
************************************************/
void DAC_Start(uint8_t DA_DATA)
{

    uint8_t i;
    uint8_t a, temp;

    LOAD = 1;

    for(i = 0; i < 8; i++)
    {
        SCLK = 1;

        a = DA_DATA & 0x80;

        if(a == 0x80)
        {
            Data_in = 1;
        }
        else
            Data_in = 0;

        SCLK = 0;

        temp = DA_DATA << 1;
        DA_DATA = temp;
    }

    LOAD = 0;
    LOAD = 1;
}

/***********************************************
函数名称：Output_channel
功    能：输出通道选择
入口参数：channel 0~3
返 回 值：无
************************************************/
void Output_channel(uint8_t channel)
{
    uint8_t i;

    switch(channel)
    {
        case 0:
            for(i = 0; i < 2; i++)
            {
                SCLK = 1;
                Data_in = 0;
                SCLK = 0;
            };

            break;

        case 1:
            SCLK = 1;
            Data_in = 0;
            SCLK = 0;
            SCLK = 1;
            Data_in = 1;
            SCLK = 0;
            break;

        case 2:
            SCLK = 1;
            Data_in = 1;
            SCLK = 0;
            SCLK = 1;
            Data_in = 0;
            SCLK = 0;
            break;

        case 3:
            SCLK = 1;
            Data_in = 1;
            SCLK = 0;
            SCLK = 1;
            Data_in = 1;
            SCLK = 0;
            break;

        default:
            break;
    }
}

/***********************************************
函数名称：Write_RNG
功    能：设置输出电压范围（详见TLC5620数据手册）
入口参数： RNG_value
返 回 值：无
************************************************/
void Write_RNG(uint8_t RNG_value)  
{
    SCLK = 1;
    Data_in = RNG_value;
    SCLK = 0;
}