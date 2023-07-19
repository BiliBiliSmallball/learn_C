#ifndef __IIC_H
#define __IIC_H

#include "system.h"

#define IIC_GPIO		P2
#define IIC_SCL_PIN 	PIN_6
#define IIC_SDA_PIN 	PIN_7
//IO操作函数
#define IIC_SCL(x)      x?(SetBits(IIC_GPIO,IIC_SCL_PIN)):(ClrBits(IIC_GPIO,IIC_SCL_PIN))      //SCL
#define IIC_SDA(x)      x?(SetBits(IIC_GPIO,IIC_SDA_PIN)):(ClrBits(IIC_GPIO,IIC_SDA_PIN))      //SDA	 
#define READ_SDA   		P27


//IIC所有操作函数
void IIC_Hardware_Init(void);                //初始化IIC的IO口
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
uint8_t IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(uint8_t daddr, uint8_t addr, uint8_t wdata);
uint8_t IIC_Read_One_Byte(uint8_t daddr, uint8_t addr);



#endif


