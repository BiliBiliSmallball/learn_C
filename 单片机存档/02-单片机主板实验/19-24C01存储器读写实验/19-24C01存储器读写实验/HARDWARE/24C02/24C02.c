#include "24c02.h"
#include "iic.h"
#include "system.h"

#define address_base 0x00												//硬件决定器件从地址为0，范围（0~7）

void IC_24Cxx_Init()
{
    IIC_Hardware_Init();
}
/**********************************************************
*功    能：在AT24CXX指定地址读出一个数据
*参    数：ReadAddr/开始读数的地址
*返 回 值：读到的数据
**********************************************************/
uint8_t IC_24Cxx_Read_Byte(uint16_t ReadAddr)
{
    uint8_t temp = 0;
    IIC_Start();
    IIC_Send_Byte(0XA0 + (address_base << 1));
    IIC_Wait_Ack();																//等待应答信号
    IIC_Send_Byte(ReadAddr);
    IIC_Wait_Ack();
    IIC_Start();
    IIC_Send_Byte(0xA1 + (address_base << 1)); 				//进入接收模式
    IIC_Wait_Ack();			 													//等待应答
    temp = IIC_Read_Byte(0);
    IIC_Stop();
    return temp;
}

/**********************************************************
*功    能：在AT24CXX指定地址写入一个数据
*参    数：WriteAddr/写入数据的目的地址  ；data:要写入的数据
*返 回 值：无
**********************************************************/
void IC_24Cxx_Write_Byte(uint16_t WriteAddr, uint8_t wdata)
{
    IIC_Start();
    IIC_Send_Byte(0XA0 + (address_base << 1));  			//发送器件地址
    IIC_Wait_Ack();																//等待应答
    IIC_Send_Byte(WriteAddr);
    IIC_Wait_Ack();
    IIC_Send_Byte(wdata);													//发送数据
    IIC_Wait_Ack();
    IIC_Stop();
    Delay_ms(10);
}

/**********************************************************
*功    能：在AT24CXX里面的指定地址开始写入长度为length的数据
*参    数：WriteAddr/开始写入的地址；data/数据数组首地址；length/要写入数据的长度2,4
*返 回 值：无
**********************************************************/
void IC_24Cxx_WaitLenByte(uint16_t WriteAddr, uint32_t wdata, uint8_t length)
{
    uint8_t i = 0;

    for(i = 0; i < length; i++)
    {
        IC_24Cxx_Write_Byte(WriteAddr + i, (wdata >> (8 * i)) & 0xff);
    }
}
/**********************************************************
*功    能：在AT24CXX里面的指定地址开始读出长度为length的数据
*参    数：ReadAddr/开始读出的地址；length/要读出数据的长度2,4
*返 回 值：数据
**********************************************************/
uint32_t IC_24Cxx_ReadLenByte(uint16_t ReadAddr, uint8_t length)
{
    uint8_t i = 0;
    uint32_t temp = 0;

    for(i = 0; i < length; i++)
    {
        temp <<= 8;
        temp = IC_24Cxx_Read_Byte(ReadAddr + i);
    }

    return temp;
}

/**********************************************************
*功    能：在AT24CXX里面的指定地址开始读出指定个数的数据
*参    数：ReadAddr/开始读出的地址 对24c01为0~127；Buffer/数据数组首地址；Buf_len/要读出数据的个数
*返 回 值：无
**********************************************************/
void IC_24Cxx_Read(uint16_t ReadAddr, uint8_t *Buffer, uint16_t Buf_len)
{
    while(Buf_len)
    {
        *Buffer++ = IC_24Cxx_Read_Byte(ReadAddr++);
        Buf_len--;
    }
}

/**********************************************************
*功    能：在AT24CXX里面的指定地址开始写入指定个数的数据
*参    数：WriteAddr/开始写入的地址 对24c01为0~127；Buffer/数据数组首地址；Buf_len/要写入数据的个数
*返 回 值：无
********************************************* *************/
void IC_24Cxx_Write(uint16_t WriteAddr, uint8_t *Buffer, uint16_t Buf_len)
{
    while(Buf_len--)
    {
        IC_24Cxx_Write_Byte(WriteAddr, *Buffer);
        WriteAddr++;
        Buffer++;
    }
}
/**********************************************************
*功    能：检查AT24CXX是否正常，这里用了24XX的最后一个地址(255)来存储标志字，如果用其他24C系列,这个地址要修改
*参    数：WriteAddr/开始写入的地址 对24c01为0~127；Buffer/数据数组首地址；Buf_len/要写入数据的个数
*返 回 值：1/检测失败；0/检测成功
**********************************************************/
uint8_t IC_24Cxx_Check(void)
{
    uint8_t temp = 0;
    temp = IC_24Cxx_Read_Byte(127);

    if(temp == 0x55)
        return 0;
    else
    {
        IC_24Cxx_Write_Byte(127, 0x55);
        temp = IC_24Cxx_Read_Byte(127);

        if(temp == 0x55)
            return 0;
    }

    return 1;
}


