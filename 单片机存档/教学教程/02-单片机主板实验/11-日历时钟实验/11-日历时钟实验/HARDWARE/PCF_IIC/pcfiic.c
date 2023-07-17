#include <system.h>
#include "pcfiic.h"

/************************************************************
�������ƣ�PCF_IIC_Hardware_Init
��    �ܣ�IIC��ʼ��
��ڲ�������
�� �� ֵ����	
*************************************************************/
void PCF_IIC_Hardware_Init(void)
{					     
	P2_Mode_PullUp(IIC_SCL_PIN|IIC_SDA_PIN);
 
	PCF_IIC_SCL(1);
	PCF_IIC_SDA(1);

}

/************************************************************
�������ƣ�PCF_SDA_In
��    �ܣ�����SDAΪ����ģʽ
��ڲ�������
�� �� ֵ����	
*************************************************************/
void PCF_SDA_In(void)
{
    P2_Mode_HighZ(IIC_SDA_PIN);
}

//����SDAΪ���ģʽ
void PCF_SDA_Out(void)
{
    P2_Mode_PullUp(IIC_SDA_PIN);
}

/************************************************************
�������ƣ�PCF_IIC_Start
��    �ܣ�����IIC��ʼ�ź�
��ڲ�������
�� �� ֵ����	
*************************************************************/
void PCF_IIC_Start(void)
{
	PCF_SDA_Out();     //sda�����
	PCF_IIC_SDA(1);	  	  
	PCF_IIC_SCL(1);
	Delay_us(4);
 	PCF_IIC_SDA(0);//START:when CLK is high,DATA change form high to low 
	Delay_us(4);
	PCF_IIC_SCL(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	 

/************************************************************
�������ƣ�PCF_IIC_Stop
��    �ܣ�����IICֹͣ�ź�
��ڲ�������
�� �� ֵ����	
*************************************************************/
void PCF_IIC_Stop(void)
{
	PCF_SDA_Out();//sda�����
	PCF_IIC_SCL(0);
	PCF_IIC_SDA(0);//STOP:when CLK is high DATA change form low to high
 	Delay_us(4);
	PCF_IIC_SCL(1); 
	PCF_IIC_SDA(1);//����I2C���߽����ź�
	Delay_us(4);							   	
}

/************************************************************
�������ƣ�PCF_IIC_Wait_Ack
��    �ܣ��ȴ�Ӧ���ź�
��ڲ�������
�� �� ֵ��1������Ӧ��ʧ��
          0������Ӧ��ɹ�
*************************************************************/
uint8_t PCF_IIC_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	PCF_IIC_SDA(1);
	PCF_SDA_In();      //SDA����Ϊ����  
	
	Delay_us(1);	   
	PCF_IIC_SCL(1);
	Delay_us(1);	 
	while(PCF_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			PCF_IIC_Stop();
			return 1;
		}
	}
	PCF_IIC_SCL(0);//ʱ�����0 	   
	return 0;  
} 

/************************************************************
�������ƣ�PCF_IIC_Ack
��    �ܣ�����ACKӦ��
��ڲ�������
�� �� ֵ����
*************************************************************/
void PCF_IIC_Ack(void)
{
	PCF_IIC_SCL(0);
	PCF_SDA_Out();
	PCF_IIC_SDA(0);
	Delay_us(2);
	PCF_IIC_SCL(1);
	Delay_us(2);
	PCF_IIC_SCL(0);
}

/************************************************************
�������ƣ�PCF_IIC_NAck
��    �ܣ�������ACKӦ��	
��ڲ�������
�� �� ֵ����
*************************************************************/   
void PCF_IIC_NAck(void)
{
	PCF_IIC_SCL(0);
	PCF_SDA_Out();
	PCF_IIC_SDA(1);
	Delay_us(2);
	PCF_IIC_SCL(1);
	Delay_us(2);
	PCF_IIC_SCL(0);
}		

/************************************************************
�������ƣ�PCF_IIC_Send_Byte
��    �ܣ�IIC����һ���ֽ� ���شӻ�����Ӧ��
��ڲ�����1����Ӧ�� 0����Ӧ��		
�� �� ֵ����
*************************************************************/  
void PCF_IIC_Send_Byte(uint8_t txd)
{                        
    uint8_t t;   
	PCF_SDA_Out(); 	    
    PCF_IIC_SCL(0);//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        PCF_IIC_SDA(((txd&0x80)>>7));
        txd<<=1; 	  
		Delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		PCF_IIC_SCL(1);
		Delay_us(2); 
		PCF_IIC_SCL(0);	
		Delay_us(2);
    }	 
}

/************************************************************
�������ƣ�PCF_IIC_Read_Byte
��    �ܣ���1���ֽ�
��ڲ�����ack=1ʱ������ACK��ack=0������nACK   
�� �� ֵ����
*************************************************************/  
uint8_t PCF_IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	PCF_SDA_In();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        PCF_IIC_SCL(0); 
        Delay_us(2);
		PCF_IIC_SCL(1);
        receive<<=1;
        if(PCF_READ_SDA)receive++;   
		Delay_us(1); 
    }					 
    if (!ack)
        PCF_IIC_NAck();//����nACK
    else
        PCF_IIC_Ack(); //����ACK   
    return receive;
}

