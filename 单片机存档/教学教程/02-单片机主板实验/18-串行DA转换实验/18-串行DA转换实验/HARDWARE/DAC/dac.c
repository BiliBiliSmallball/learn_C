#include "dac.h"

/***********************************************
�������ƣ�DAC_Init
��    �ܣ�IO��ʼ��
��ڲ�������
�� �� ֵ����
************************************************/
void DAC_Init(void)
{
    P2M1 = 0x00;			 //��P2^0~P2^3 ����Ϊ�������ģʽ
    P2M0 = 0xff;
}

/***********************************************
�������ƣ�DAC_Start
��    �ܣ�DAת������
��ڲ�������
�� �� ֵ����
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
�������ƣ�Output_channel
��    �ܣ����ͨ��ѡ��
��ڲ�����channel 0~3
�� �� ֵ����
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
�������ƣ�Write_RNG
��    �ܣ����������ѹ��Χ�����TLC5620�����ֲᣩ
��ڲ����� RNG_value
�� �� ֵ����
************************************************/
void Write_RNG(uint8_t RNG_value)  
{
    SCLK = 1;
    Data_in = RNG_value;
    SCLK = 0;
}