#include "system.h"
#include "ds18b20.h"
#include "stdio.h"

#define DS18B20_GPIO_NUM				PIN_7
#define DS18B20_GPIO_X					P2

#define DS18B20_DQ_OUT_Low			ClrBits(DS18B20_GPIO_X,DS18B20_GPIO_NUM)
#define DS18B20_DQ_OUT_High			SetBits(DS18B20_GPIO_X,DS18B20_GPIO_NUM)
#define DS18B20_DQ_IN				P27

#define MaxSensorNum 8

#define ROMID DS18B20_ID

unsigned char DS18B20_ID[MaxSensorNum][8];
unsigned char DS18B20_SensorNum = 0;

void DS18B20_GPIO_Config(void)
{
    DS18B20_Mode_Out();
    DS18B20_DQ_OUT_High;
}

void DS18B20_Mode_IPU(void)
{
    P2_Mode_HighZ(DS18B20_GPIO_NUM);
}

void DS18B20_Mode_Out(void)
{
    P2_Mode_PullUp(DS18B20_GPIO_NUM);
}

void DS18B20_Rst(void)
{
    DS18B20_Mode_Out();
    DS18B20_DQ_OUT_Low;
    Delay_us(480);
    DS18B20_DQ_OUT_High;
    Delay_us(15);
}

uint8_t DS18B20_Answer_Check(void)
{
    uint8_t delay = 0;
    DS18B20_Mode_IPU();

    while (DS18B20_DQ_IN && delay < 100)
    {
        delay++;
        Delay_us(1);
    }

    if (delay >= 100)
        return 1;
    else
        delay = 0;

    while (!DS18B20_DQ_IN && delay < 240)
    {
        delay++;
        Delay_us(1);
    }

    if (delay >= 240)
        return 1;

    return 0;
}


uint8_t DS18B20_Read_Bit(void)
{
    uint8_t wdata;
    DS18B20_Mode_Out();
    DS18B20_DQ_OUT_Low;
    Delay_us(2);
    DS18B20_DQ_OUT_High;
    Delay_us(12);
    DS18B20_Mode_IPU();

    if (DS18B20_DQ_IN)
        wdata = 1;
    else
        wdata = 0;

    Delay_us(50);
    return wdata;
}


uint8_t DS18B20_Read_2Bit(void)
{
    uint8_t i;
    uint8_t dat = 0;

    for (i = 2; i > 0; i--)
    {
        dat = dat << 1;
        DS18B20_Mode_Out();
        DS18B20_DQ_OUT_Low;
        Delay_us(2);
        DS18B20_DQ_OUT_High;
        DS18B20_Mode_IPU();
        Delay_us(12);

        if (DS18B20_DQ_IN)	dat |= 0x01;

        Delay_us(50);
    }

    return dat;
}


uint8_t DS18B20_Read_Byte(void)	// read one byte
{
    uint8_t i, j, dat;
    dat = 0;

    for (i = 0; i < 8; i++)
    {
        j = DS18B20_Read_Bit();
        dat = (dat) | (j << i);
    }

    return dat;
}


void DS18B20_Write_Bit(uint8_t dat)
{
    DS18B20_Mode_Out();

    if (dat)
    {
        DS18B20_DQ_OUT_Low;// Write 1
        Delay_us(2);
        DS18B20_DQ_OUT_High;
        Delay_us(60);
    }
    else
    {
        DS18B20_DQ_OUT_Low;// Write 0
        Delay_us(60);
        DS18B20_DQ_OUT_High;
        Delay_us(2);
    }
}


void DS18B20_Write_Byte(uint8_t dat)
{
    uint8_t j;
    uint8_t testb;
    DS18B20_Mode_Out();

    for (j = 1; j <= 8; j++)
    {
        testb = dat & 0x01;
        dat = dat >> 1;

        if (testb)
        {
            DS18B20_DQ_OUT_Low;
            Delay_us(10);
            DS18B20_DQ_OUT_High;
            Delay_us(50);
        }
        else
        {
            DS18B20_DQ_OUT_Low;
            Delay_us(60);
            DS18B20_DQ_OUT_High;
            Delay_us(2);
        }
    }
}


uint8_t DS18B20_Init(void)
{
    DS18B20_GPIO_Config();
    DS18B20_Rst();
    return DS18B20_Answer_Check();
}


float DS18B20_Get_Temp(uint8_t i)
{

    uint8_t j;
    uint8_t TL, TH;
    short Temperature;
    float Temperature1;
    DS18B20_Rst();
    DS18B20_Answer_Check();
    DS18B20_Write_Byte(0xcc);// skip rom
    DS18B20_Write_Byte(0x44);// convert
    DS18B20_Rst();
    DS18B20_Answer_Check();

    // DS18B20_Write_Byte(0xcc);// skip rom
    DS18B20_Write_Byte(0x55);

    for (j = 0; j < 8; j++)
    {
        DS18B20_Write_Byte(DS18B20_ID[i][j]);
    }

    DS18B20_Write_Byte(0xbe);// convert
    TL = DS18B20_Read_Byte(); // LSB
    TH = DS18B20_Read_Byte(); // MSB

    if (TH & 0xfc)
    {
        //flag=1;
        Temperature = (TH << 8) | TL;
        Temperature1 = (~Temperature) + 1;
        Temperature1 *= 0.0625f;
    }
    else
    {
        //flag=0;
        Temperature1 = ((TH << 8) | TL) * 0.0625;
    }

    return Temperature1;
}


void DS18B20_Search_Rom()
{
    unsigned char tree_num[64] = {0}, Rom[64];				//bit_error[]=0ʱ��λdebugģʽ�ж�
    unsigned char i, j, k, l, r1, d, rom_sbit = 0, rom_out = 0;

    for(i = 0; i < 16; i++) 							//ȡID��Сֵ��ʼ���𽥱��
    {
        DS18B20_Rst();
        Delay_us(480);
        DS18B20_Write_Byte(0xf0);

        for(j = 0; j < 64; j++)
        {
            r1 = DS18B20_Read_2Bit();
            r1 = r1 & 0x03;

            if(r1 == 0x01) 				//0,1=0
            {
                Rom[j] = 0;
                DS18B20_Write_Bit(0);
            }
            else if(r1 == 0x02) 			//1,0=1
            {
                Rom[j] = 1;
                DS18B20_Write_Bit(1);
            }
            else 							//0,0=2			����¼���,ִ���ж�
            {
                if(tree_num[j] == 0) 						//j��ȵĽڵ�Ϊ0�� �ڵ���1����
                {
                    tree_num[j] = 1;
                    Rom[j] = 0;
                    DS18B20_Write_Bit(0);
                }
                else if(tree_num[j] == 1) 				//��j��ȵĽڵ�Ϊ1��ִ���ж�  ����1������1����
                {
                    rom_sbit = 0;

                    for(k = j + 1; k < 64; k++) 				//�������ڵ��Ƿ���1
                    {
                        rom_sbit |= tree_num[k];
                    }

                    if((rom_sbit & 0x01) == 1) 							//������1��������
                    {
                        Rom[j] = 0;
                        DS18B20_Write_Bit(0);
                    }
                    else 											//�����2����
                    {
                        Rom[j] = 1;
                        DS18B20_Write_Bit(1);
                        tree_num[j] = 2;

                        for(l = j + 1; l < 64; l++) 						//���µ�·ȥ�ˣ��������Ƚڵ�ֵ��0
                        {
                            tree_num[l] = 0;
                        }
                    }
                }
                else 									//����j��ȵĽڵ�Ϊ2
                {
                    Rom[j] = 1;
                    DS18B20_Write_Bit(1);
                }
            }

            if(j == 63) 									//�Խڵ��жϣ����ڵ㶼���������ˣ�������˳�Ѱ��ID��
            {
                rom_out = 0;

                for(k = 0; k < 64; k++)
                {
                    rom_out |= tree_num[k];				//��1
                }

                if((rom_out & 0x01) == 0x00)
                {
                    rom_out &= 0x01;						//��1Ϊ0
                }
            }
        }

        for(j = 0; j < 64; j += 8)
        {
            for(d = 0; d < 8; d++)
            {
                if(Rom[j + d] & 0x01)
                {
                    ROMID[i][j / 8] >>= 1;
                    ROMID[i][j / 8] |= 0x80;
                }
                else
                {
                    ROMID[i][j / 8] >>= 1;
                }
            }
        }

        if(rom_out == 0x00) 								//����IDROM
        {
            DS18B20_SensorNum = i + 1;
            break;
        }
    }
}
