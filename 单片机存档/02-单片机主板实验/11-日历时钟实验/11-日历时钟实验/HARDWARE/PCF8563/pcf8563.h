#ifndef __24CXX_H
#define __24CXX_H

#include <system.h>

#define PCF8563_ADDRESS 0XA2 //PCF8563器件地址
#define READ 0X01	//读数据

//控制和状态寄存器
#define CONTROL_STATUS_1 (unsigned char)0X00    
#define CONTROL_STATUS_2 (unsigned char)0X01

//时间和日期寄存器
#define PCF8563_SECOND_ADDRESS (unsigned char)0X02				//秒地址
#define PCF8563_MINUTE_ADDRESS (unsigned char)0X03				//分地址
#define PCF8563_HOUR_ADDRESS (unsigned char)0X04				//时地址
#define PCF8563_DAY_ADDRESS (unsigned char)0X05				//日地址
#define PCF8563_WEEK_ADDRESS (unsigned char)0X06					//星期地址
#define PCF8563_MONTH_ADDRESS (unsigned char)0X07				//月地址
#define PCF8563_YEAR_ADDRESS (unsigned char)0X08				//年地址

#define PCF8563_MINUTE_ALARM_ADDRESS 0X09				//闹钟分地址
#define PCF8563_HOUR_ALARM_ADDRESS 0X0A				//闹钟时地址
#define PCF8563_DAY_ALARM_ADDRESS 0X0B				//闹钟日地址
#define PCF8563_WEEK_ALARM_ADDRESS 0X0C					//闹钟星期地址

#define PCF8563_CLKOUT_CONTROL 0X0D				//时钟输出控制地址


uint8_t PCF8563_ReadOneByte(uint16_t ReadAddr);							//指定地址读取一个字节
void PCF8563_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite);		//指定地址写入一个字节

void PCF8563_Init(void); //初始化IIC
void PCF8563_Write_Time(void);//写时钟
void PCF8563_Read_Time(void);//读时钟
void PCF8563_LCD_Show_Time(void);
#endif
















