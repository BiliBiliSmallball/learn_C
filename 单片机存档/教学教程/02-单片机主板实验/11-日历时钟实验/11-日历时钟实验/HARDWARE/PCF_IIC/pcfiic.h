#ifndef __MYIIC_H
#define __MYIIC_H

#include <system.h>
#define GPIO_PCF P2
#define IIC_SCL_PIN PIN_6
#define IIC_SDA_PIN PIN_7

//IO��������	 
#define PCF_IIC_SCL(x)    x?(SetBits(GPIO_PCF,IIC_SCL_PIN)):(ClrBits(GPIO_PCF,IIC_SCL_PIN))      //SCL
#define PCF_IIC_SDA(x)    x?(SetBits(GPIO_PCF,IIC_SDA_PIN)):(ClrBits(GPIO_PCF,IIC_SDA_PIN))      //SDA	 
#define PCF_READ_SDA      P27

//IIC���в�������
void PCF_IIC_Hardware_Init(void);       //��ʼ��IIC��IO��				 
void PCF_IIC_Start(void);				//����IIC��ʼ�ź�
void PCF_IIC_Stop(void);	  			//����IICֹͣ�ź�
void PCF_IIC_Send_Byte(uint8_t txd);	//IIC����һ���ֽ�
uint8_t PCF_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
uint8_t PCF_IIC_Wait_Ack(void); 		//IIC�ȴ�ACK�ź�
void PCF_IIC_Ack(void);					//IIC����ACK�ź�
void PCF_IIC_NAck(void);				//IIC������ACK�ź�

void PCF_IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t wdata);
uint8_t PCF_IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
#endif
















