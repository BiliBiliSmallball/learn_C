#ifndef __IIC_H
#define __IIC_H

#include "system.h"

#define IIC_GPIO		P2
#define IIC_SCL_PIN 	PIN_6
#define IIC_SDA_PIN 	PIN_7
//IO��������
#define IIC_SCL(x)      x?(SetBits(IIC_GPIO,IIC_SCL_PIN)):(ClrBits(IIC_GPIO,IIC_SCL_PIN))      //SCL
#define IIC_SDA(x)      x?(SetBits(IIC_GPIO,IIC_SDA_PIN)):(ClrBits(IIC_GPIO,IIC_SDA_PIN))      //SDA	 
#define READ_SDA   		P27


//IIC���в�������
void IIC_Hardware_Init(void);                //��ʼ��IIC��IO��
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(uint8_t txd);			//IIC����һ���ֽ�
uint8_t IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
uint8_t IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(uint8_t daddr, uint8_t addr, uint8_t wdata);
uint8_t IIC_Read_One_Byte(uint8_t daddr, uint8_t addr);



#endif


