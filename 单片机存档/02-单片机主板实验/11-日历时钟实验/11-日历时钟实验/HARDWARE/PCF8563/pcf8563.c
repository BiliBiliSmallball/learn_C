#include <system.h>
#include "pcf8563.h" 
#include "pcfiic.h"
#include "lcd12864.h"

unsigned char  time_buf1[8]={20,22,6,7,16,57,0,2};
unsigned char time_buf[8];
unsigned char time_buf2[8];
unsigned char *time_buf1_sp;


void PCF8563_Init(void)
{
	PCF_IIC_Hardware_Init();
}

/************************************************************
�������ƣ�PCF8563_ReadOneByte
��    �ܣ���PCF8563ָ����ַ����һ������
��ڲ�����ReadAddr:��ʼ�����ĵ�ַ  
�� �� ֵ������������
*************************************************************/
uint8_t PCF8563_ReadOneByte(uint16_t ReadAddr)
{				  
	uint8_t temp=0;
	PCF_IIC_Start();  //��ʼ
	PCF_IIC_Send_Byte(PCF8563_ADDRESS);//����������ַ
	PCF_IIC_Wait_Ack();	//�ȴ�Ӧ��
	PCF_IIC_Send_Byte(ReadAddr);//���ͼĴ�����ַ
	PCF_IIC_Wait_Ack();//�ȴ�Ӧ��
	PCF_IIC_Start();  //��ʼ
	PCF_IIC_Send_Byte(PCF8563_ADDRESS|READ);//����������ַ
	PCF_IIC_Wait_Ack();//�ȴ�Ӧ��
	temp=PCF_IIC_Read_Byte(0);		   
    PCF_IIC_Stop();//����һ��ֹͣ����	    
	return temp;
}

/*****************************************************************
�������ƣ�PCF8563_WriteOneByte
��    �ܣ���PCF8563ָ����ַд��һ������
��ڲ�����WriteAddr  :д�����ݵ�Ŀ�ĵ�ַ  DataToWrite:Ҫд�������
�� �� ֵ����
*******************************************************************/
void PCF8563_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite)
{				   	  	    																 
    PCF_IIC_Start();  //��ʼ
	PCF_IIC_Send_Byte(PCF8563_ADDRESS);//����������ַ
	PCF_IIC_Wait_Ack();	//�ȴ�Ӧ��
	PCF_IIC_Send_Byte(WriteAddr);//���ͼĴ�����ַ
	PCF_IIC_Wait_Ack();//�ȴ�Ӧ��
	PCF_IIC_Send_Byte(DataToWrite);     //�����ֽ�	
	PCF_IIC_Wait_Ack();//�ȴ�Ӧ��
	PCF_IIC_Stop();//����һ��ֹͣ���� 
	Delay_ms(10);	 
}

/************************************************************
�������ƣ�PCF8563_Write_Time
��    �ܣ���оƬ��дʱ��
��ڲ������� 
�� �� ֵ����
*************************************************************/
void PCF8563_Write_Time(void)
{
	uint8_t i,temp;
	for(i=0;i<8;i++)
	{
		temp=time_buf1[i]/10;
		time_buf[i]=time_buf1[i]%10;
		time_buf[i]=time_buf[i]+temp*16;
	}
	PCF8563_WriteOneByte(CONTROL_STATUS_1,0x20);//�ر�ʱ��
	PCF8563_WriteOneByte(PCF8563_YEAR_ADDRESS,time_buf[1]);//��
	PCF8563_WriteOneByte(PCF8563_MONTH_ADDRESS,time_buf[2]);//��
	PCF8563_WriteOneByte(PCF8563_DAY_ADDRESS,time_buf[3]);//��
	PCF8563_WriteOneByte(PCF8563_HOUR_ADDRESS,time_buf[4]);//ʱ
	PCF8563_WriteOneByte(PCF8563_MINUTE_ADDRESS,time_buf[5]);//��
	PCF8563_WriteOneByte(PCF8563_SECOND_ADDRESS,time_buf[6]);//��
	PCF8563_WriteOneByte(PCF8563_WEEK_ADDRESS,time_buf[7]);//��
	PCF8563_WriteOneByte(CONTROL_STATUS_1,0X00);//��ʼʱ��
	
}

/************************************************************
�������ƣ�PCF8563_Read_Time
��    �ܣ���ȡоƬ�ڲ���ʱ��
��ڲ������� 
�� �� ֵ����
*************************************************************/
void PCF8563_Read_Time(void)
{
	uint8_t i,temp;
	time_buf[0]=PCF8563_ReadOneByte(PCF8563_YEAR_ADDRESS)&0Xff;
	time_buf[2]=PCF8563_ReadOneByte(PCF8563_MONTH_ADDRESS)&0X1F;
	time_buf[3]=PCF8563_ReadOneByte(PCF8563_DAY_ADDRESS)&0X3F;
	time_buf[4]=PCF8563_ReadOneByte(PCF8563_HOUR_ADDRESS)&0X3F;
	time_buf[5]=PCF8563_ReadOneByte(PCF8563_MINUTE_ADDRESS)&0X7F;
	time_buf[6]=PCF8563_ReadOneByte(PCF8563_SECOND_ADDRESS)&0X7F;
	time_buf[7]=PCF8563_ReadOneByte(PCF8563_WEEK_ADDRESS)&0X07;
	for(i=0;i<8;i++)
	{
		temp=time_buf[i]/16;
		time_buf1[i]=time_buf[i]%16;
		time_buf1[i]=time_buf1[i]+temp*10;
	}
}

/************************************************************
�������ƣ�PCF8563_LCD_Show_Time
��    �ܣ�LCD��ʾʱ��
��ڲ������� 
�� �� ֵ����
*************************************************************/
void PCF8563_LCD_Show_Time(void)
{
    unsigned char buf[25];
    buf[0] = time_buf1[0]/10+48;
    buf[1] = time_buf1[0]%10+48;
    buf[2] = '/';
    buf[3] = time_buf1[2]/10+48;
    buf[4] = time_buf1[2]%10+48;
    buf[5] = '/';
    buf[6] = time_buf1[3]/10+48;
    buf[7] = time_buf1[3]%10+48;
    buf[8] = ' ';
    buf[9] = ' ';
    buf[10] = ' ';
    buf[11] = ' ';
    buf[12] = ' ';   
    buf[13] = ' ';
    buf[14] = ' ';
    buf[15] = ' ';
    buf[16] = time_buf1[4]/10+48;
    buf[17] = time_buf1[4]%10+48;
    buf[18] = ':';
    buf[19] = time_buf1[5]/10+48;
    buf[20] = time_buf1[5]%10+48;
    buf[21] = ':';
    buf[22] = time_buf1[6]/10+48;
    buf[23] = time_buf1[6]%10+48;
	  buf[24] = '\0';
    Show_Num(3,1,(char*)(buf));//��ʾʱ�� 

    
}












