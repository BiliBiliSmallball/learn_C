#ifndef __24CXX_H
#define __24CXX_H

#include <system.h>

#define PCF8563_ADDRESS 0XA2 //PCF8563������ַ
#define READ 0X01	//������

//���ƺ�״̬�Ĵ���
#define CONTROL_STATUS_1 (unsigned char)0X00    
#define CONTROL_STATUS_2 (unsigned char)0X01

//ʱ������ڼĴ���
#define PCF8563_SECOND_ADDRESS (unsigned char)0X02				//���ַ
#define PCF8563_MINUTE_ADDRESS (unsigned char)0X03				//�ֵ�ַ
#define PCF8563_HOUR_ADDRESS (unsigned char)0X04				//ʱ��ַ
#define PCF8563_DAY_ADDRESS (unsigned char)0X05				//�յ�ַ
#define PCF8563_WEEK_ADDRESS (unsigned char)0X06					//���ڵ�ַ
#define PCF8563_MONTH_ADDRESS (unsigned char)0X07				//�µ�ַ
#define PCF8563_YEAR_ADDRESS (unsigned char)0X08				//���ַ

#define PCF8563_MINUTE_ALARM_ADDRESS 0X09				//���ӷֵ�ַ
#define PCF8563_HOUR_ALARM_ADDRESS 0X0A				//����ʱ��ַ
#define PCF8563_DAY_ALARM_ADDRESS 0X0B				//�����յ�ַ
#define PCF8563_WEEK_ALARM_ADDRESS 0X0C					//�������ڵ�ַ

#define PCF8563_CLKOUT_CONTROL 0X0D				//ʱ��������Ƶ�ַ


uint8_t PCF8563_ReadOneByte(uint16_t ReadAddr);							//ָ����ַ��ȡһ���ֽ�
void PCF8563_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite);		//ָ����ַд��һ���ֽ�

void PCF8563_Init(void); //��ʼ��IIC
void PCF8563_Write_Time(void);//дʱ��
void PCF8563_Read_Time(void);//��ʱ��
void PCF8563_LCD_Show_Time(void);
#endif
















