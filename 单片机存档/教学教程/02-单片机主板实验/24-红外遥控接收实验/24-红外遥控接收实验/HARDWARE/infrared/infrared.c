#include "system.h"
#include "infrared.h"
#include "key.h"
#include "pwm.h"
#include "lcd12864.h"
#include "stdio.h"
/**********************************************************
*�����ܣ�����Ӳ����ʼ��
*�Ρ�������
*����ֵ����
**********************************************************/
void Infrared_Hardware_Init(void)
{
    Key_Configure();			//��������
    Pwm1_Configure();			//TX
    P2_Mode_HighZ(PIN_7);
}

/**********************************************************
*�����ܣ����������ź�
*�Ρ�������
*����ֵ���ߵ�ƽ�ź�����
**********************************************************/
uint8_t IR_RC_Time(void)
{
    int l_time = 0, h_time = 0;
    char num[8] = {"0"};

    while(!READ_RX())		//�ȶ��͵�ƽʱ��
    {
        l_time++;
        Delay_us(50);

        //��ʱ���
        if(l_time > 400)//�͵�ƽ��ʱ20ms�˳�
            break;
    }

    while(READ_RX())		//�ȶ��͵�ƽʱ��
    {
        h_time++;
        Delay_us(50);

        //��ʱ���
        if(h_time > 200)//�ߵ�ƽ��ʱ10ms�˳�
            break;
    }

    if((l_time > 100) && (l_time < 200) && (h_time > 50) && (h_time < 100)) //150,75
    {
        return 1;//��Ϣͷ
    }
    else if((l_time > 5) && (l_time < 15) && (h_time > 5) && (h_time < 15)) //10,10
    {
        return 2;//����
    }
    else if((l_time > 5) && (l_time < 15) && (h_time > 15) && (h_time < 45)) //10,30
    {
        return 3;//һ��
    }
    else
    {
        return 0;//������
    }
}

/**********************************************************
*�����ܣ����ⷢ��һ���ֽ�
*�Ρ��������͵��ֽ�
*����ֵ����
**********************************************************/
void Infrared_SendByte( uint8_t ir )
{
    uint8_t i = 0;

    for( i = 0; i < 8; i++ )
    {
        WRITE_IR(1);
        Delay_us(500);
        WRITE_IR(0);

        if( ir & (0x80 >> i ) )//�ȷ��ֽڸ�λ
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
*�����ܣ�����һ���ֽ�
*�Ρ�������
*����ֵ�����յ��ֽ�
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
*�����ܣ����ⷢ������
*�Ρ�����irdate�����͵����ݵĵ�ַ lenght�����ݳ���
*����ֵ����
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
*�����ܣ����ƿ���/�ر��ز�
*�Ρ�����num=0 ��
		num=1 ��
*����ֵ����
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


