#include "system.h"
#include "iic.h"

/*************************************************
�������ƣ�IIC_Hardware_Init
����˵����IIC��ʼ��	
���������	��			
�� �� ֵ��	��			
**************************************************/
void IIC_Hardware_Init(void)
{

    P2_Mode_PullUp(IIC_SCL_PIN | IIC_SDA_PIN);

    IIC_SCL(1);
    IIC_SDA(1);
}

/*************************************************
�������ƣ�SDA_In
����˵����IIC��������	
���������	��			
�� �� ֵ��	��			
**************************************************/
void SDA_In(void)
{
    P2_Mode_HighZ(IIC_SDA_PIN);
}

/*************************************************
�������ƣ�SDA_Out
����˵����IIC�������	
���������	��			
�� �� ֵ��	��			
**************************************************/
void SDA_Out(void)
{
    P2_Mode_PullUp(IIC_SDA_PIN);
}

/*************************************************
�������ƣ�IIC_Start
����˵��������IIC��ʼ�ź�
���������	��			
�� �� ֵ��	��			
**************************************************/
void IIC_Start(void)
{
    SDA_Out();     //sda�����
    IIC_SDA(1);
    IIC_SCL(1);
    Delay_us(4);
    IIC_SDA(0);//START:when CLK is high,DATA change form high to low
    Delay_us(4);
    IIC_SCL(0);//ǯסI2C���ߣ�׼�����ͻ��������
}

/*************************************************
�������ƣ�IIC_Stop
����˵��������IICֹͣ�ź�
���������	��			
�� �� ֵ��	��			
**************************************************/
void IIC_Stop(void)
{
    SDA_Out();		//sda�����
    IIC_SCL(0);
    IIC_SDA(0);		//STOP:when CLK is high DATA change form low to high
    Delay_us(4);
    IIC_SCL(1);
    IIC_SDA(1);		//����I2C���߽����ź�
    Delay_us(4);
}

/**********************************************************
*��    �ܣ��ȴ�Ӧ���źŵ���
*��    ������
*�� �� ֵ��1/����Ӧ��ʧ�ܣ�0/����Ӧ��ɹ�
**********************************************************/
uint8_t IIC_Wait_Ack(void)
{
    uint8_t ucErrTime = 0;
    SDA_In();      //SDA����Ϊ����
    IIC_SDA(1);
    Delay_us(1);
    IIC_SCL(1);
    Delay_us(1);

    while(READ_SDA)
    {
        ucErrTime++;

        if(ucErrTime > 250)
        {
            IIC_Stop();
            return 1;
        }
    }

    IIC_SCL(0);//ʱ�����0
    return 0;
}

//����ACKӦ��
void IIC_Ack(void)
{
    IIC_SCL(0);
    SDA_Out();
    IIC_SDA(0);
    Delay_us(2);
    IIC_SCL(1);
    Delay_us(2);
    IIC_SCL(0);
}

//������ACKӦ��
void IIC_NAck(void)
{
    IIC_SCL(0);
    SDA_Out();
    IIC_SDA(1);
    Delay_us(2);
    IIC_SCL(1);
    Delay_us(2);
    IIC_SCL(0);
}

/**********************************************************
*��    �ܣ�IIC����һ���ֽ�
*��    ����txd
*�� �� ֵ����
**********************************************************/
void IIC_Send_Byte(uint8_t txd)
{
    uint8_t t;
    SDA_Out();
    IIC_SCL(0);//����ʱ�ӿ�ʼ���ݴ���

    for(t = 0; t < 8; t++)
    {
        IIC_SDA(((txd & 0x80) >> 7));
        txd <<= 1;
        Delay_us(2);   //��TEA5767��������ʱ���Ǳ����
        IIC_SCL(1);
        Delay_us(2);
        IIC_SCL(0);
        Delay_us(2);
    }
}

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
uint8_t IIC_Read_Byte(unsigned char ack)
{
    unsigned char i, receive = 0;
    SDA_In();//SDA����Ϊ����

    for(i = 0; i < 8; i++ )
    {
        IIC_SCL(0);
        Delay_us(2);
        IIC_SCL(1);
        receive <<= 1;

        if(READ_SDA)receive++;

        Delay_us(1);
    }

    if (!ack)
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK

    return receive;
}







