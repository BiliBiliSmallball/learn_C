#include "24c02.h"
#include "iic.h"
#include "system.h"

#define address_base 0x00												//Ӳ�����������ӵ�ַΪ0����Χ��0~7��

void IC_24Cxx_Init()
{
    IIC_Hardware_Init();
}
/**********************************************************
*��    �ܣ���AT24CXXָ����ַ����һ������
*��    ����ReadAddr/��ʼ�����ĵ�ַ
*�� �� ֵ������������
**********************************************************/
uint8_t IC_24Cxx_Read_Byte(uint16_t ReadAddr)
{
    uint8_t temp = 0;
    IIC_Start();
    IIC_Send_Byte(0XA0 + (address_base << 1));
    IIC_Wait_Ack();																//�ȴ�Ӧ���ź�
    IIC_Send_Byte(ReadAddr);
    IIC_Wait_Ack();
    IIC_Start();
    IIC_Send_Byte(0xA1 + (address_base << 1)); 				//�������ģʽ
    IIC_Wait_Ack();			 													//�ȴ�Ӧ��
    temp = IIC_Read_Byte(0);
    IIC_Stop();
    return temp;
}

/**********************************************************
*��    �ܣ���AT24CXXָ����ַд��һ������
*��    ����WriteAddr/д�����ݵ�Ŀ�ĵ�ַ  ��data:Ҫд�������
*�� �� ֵ����
**********************************************************/
void IC_24Cxx_Write_Byte(uint16_t WriteAddr, uint8_t wdata)
{
    IIC_Start();
    IIC_Send_Byte(0XA0 + (address_base << 1));  			//����������ַ
    IIC_Wait_Ack();																//�ȴ�Ӧ��
    IIC_Send_Byte(WriteAddr);
    IIC_Wait_Ack();
    IIC_Send_Byte(wdata);													//��������
    IIC_Wait_Ack();
    IIC_Stop();
    Delay_ms(10);
}

/**********************************************************
*��    �ܣ���AT24CXX�����ָ����ַ��ʼд�볤��Ϊlength������
*��    ����WriteAddr/��ʼд��ĵ�ַ��data/���������׵�ַ��length/Ҫд�����ݵĳ���2,4
*�� �� ֵ����
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
*��    �ܣ���AT24CXX�����ָ����ַ��ʼ��������Ϊlength������
*��    ����ReadAddr/��ʼ�����ĵ�ַ��length/Ҫ�������ݵĳ���2,4
*�� �� ֵ������
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
*��    �ܣ���AT24CXX�����ָ����ַ��ʼ����ָ������������
*��    ����ReadAddr/��ʼ�����ĵ�ַ ��24c01Ϊ0~127��Buffer/���������׵�ַ��Buf_len/Ҫ�������ݵĸ���
*�� �� ֵ����
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
*��    �ܣ���AT24CXX�����ָ����ַ��ʼд��ָ������������
*��    ����WriteAddr/��ʼд��ĵ�ַ ��24c01Ϊ0~127��Buffer/���������׵�ַ��Buf_len/Ҫд�����ݵĸ���
*�� �� ֵ����
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
*��    �ܣ����AT24CXX�Ƿ���������������24XX�����һ����ַ(255)���洢��־�֣����������24Cϵ��,�����ַҪ�޸�
*��    ����WriteAddr/��ʼд��ĵ�ַ ��24c01Ϊ0~127��Buffer/���������׵�ַ��Buf_len/Ҫд�����ݵĸ���
*�� �� ֵ��1/���ʧ�ܣ�0/���ɹ�
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


