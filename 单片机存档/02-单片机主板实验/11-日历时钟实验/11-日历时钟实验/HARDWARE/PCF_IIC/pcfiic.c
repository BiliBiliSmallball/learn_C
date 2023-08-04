#include <system.h>
#include "pcfiic.h"

/************************************************************
函数名称：PCF_IIC_Hardware_Init
功    能：IIC初始化
入口参数：无
返 回 值：无	
*************************************************************/
void PCF_IIC_Hardware_Init(void)
{					     
	P2_Mode_PullUp(IIC_SCL_PIN|IIC_SDA_PIN);
 
	PCF_IIC_SCL(1);
	PCF_IIC_SDA(1);

}

/************************************************************
函数名称：PCF_SDA_In
功    能：设置SDA为输入模式
入口参数：无
返 回 值：无	
*************************************************************/
void PCF_SDA_In(void)
{
    P2_Mode_HighZ(IIC_SDA_PIN);
}

//设置SDA为输出模式
void PCF_SDA_Out(void)
{
    P2_Mode_PullUp(IIC_SDA_PIN);
}

/************************************************************
函数名称：PCF_IIC_Start
功    能：产生IIC起始信号
入口参数：无
返 回 值：无	
*************************************************************/
void PCF_IIC_Start(void)
{
	PCF_SDA_Out();     //sda线输出
	PCF_IIC_SDA(1);	  	  
	PCF_IIC_SCL(1);
	Delay_us(4);
 	PCF_IIC_SDA(0);//START:when CLK is high,DATA change form high to low 
	Delay_us(4);
	PCF_IIC_SCL(0);//钳住I2C总线，准备发送或接收数据 
}	 

/************************************************************
函数名称：PCF_IIC_Stop
功    能：产生IIC停止信号
入口参数：无
返 回 值：无	
*************************************************************/
void PCF_IIC_Stop(void)
{
	PCF_SDA_Out();//sda线输出
	PCF_IIC_SCL(0);
	PCF_IIC_SDA(0);//STOP:when CLK is high DATA change form low to high
 	Delay_us(4);
	PCF_IIC_SCL(1); 
	PCF_IIC_SDA(1);//发送I2C总线结束信号
	Delay_us(4);							   	
}

/************************************************************
函数名称：PCF_IIC_Wait_Ack
功    能：等待应答信号
入口参数：无
返 回 值：1，接收应答失败
          0，接收应答成功
*************************************************************/
uint8_t PCF_IIC_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	PCF_IIC_SDA(1);
	PCF_SDA_In();      //SDA设置为输入  
	
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
	PCF_IIC_SCL(0);//时钟输出0 	   
	return 0;  
} 

/************************************************************
函数名称：PCF_IIC_Ack
功    能：产生ACK应答
入口参数：无
返 回 值：无
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
函数名称：PCF_IIC_NAck
功    能：不产生ACK应答	
入口参数：无
返 回 值：无
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
函数名称：PCF_IIC_Send_Byte
功    能：IIC发送一个字节 返回从机有无应答
入口参数：1，有应答 0，无应答		
返 回 值：无
*************************************************************/  
void PCF_IIC_Send_Byte(uint8_t txd)
{                        
    uint8_t t;   
	PCF_SDA_Out(); 	    
    PCF_IIC_SCL(0);//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
        PCF_IIC_SDA(((txd&0x80)>>7));
        txd<<=1; 	  
		Delay_us(2);   //对TEA5767这三个延时都是必须的
		PCF_IIC_SCL(1);
		Delay_us(2); 
		PCF_IIC_SCL(0);	
		Delay_us(2);
    }	 
}

/************************************************************
函数名称：PCF_IIC_Read_Byte
功    能：读1个字节
入口参数：ack=1时，发送ACK，ack=0，发送nACK   
返 回 值：无
*************************************************************/  
uint8_t PCF_IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	PCF_SDA_In();//SDA设置为输入
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
        PCF_IIC_NAck();//发送nACK
    else
        PCF_IIC_Ack(); //发送ACK   
    return receive;
}

