#include "system.h"
#include "encode.h"
#include "lcd12864.h"

unsigned char Now_Num[] = "Now the num:    "; //���ڵ�ֵ
unsigned char temp, num = 0x40;

/**************************************************
��  ����	�˿ڳ�ʼ��
��  ����	��
����ֵ��	��
**************************************************/
void Encode_Hardware_Init(void)
{
    P2_Mode_HighZ(A_PIN | B_PIN | C_PIN);
}

/**************************************************
��  �������뺯��
��  ����	��
����ֵ��	��
**************************************************/
void Encode_Test(void)
{
    if(!D_IN())
    {
        Show_Num(0, 1, (char*)Now_Num);
    }

    if(!B_IN())
    {
        if(!A_IN())
        {
            if(num == 0xFF)
            {
                num = 0xFF;
            }
            else
            {
                num = num + 1;
            }

            temp = num / 16;

            if(temp > 9)             //ת��ΪASCII��
                temp = temp + 0x37;
            else
                temp = temp + 0x30;

            Now_Num[12] = temp;
            temp = num % 16;

            if(temp > 9)             //ת��ΪASCII��
                temp = temp + 0x37;
            else
                temp = temp + 0x30;

            Now_Num[13] = temp;
            Show_Num(0, 1, (char*)Now_Num);
            Delay_ms(10);
        }
        else
        {
            if(num == 0x00)
            {
                num = 0x00;
            }
            else
            {
                num = num - 1;
            }

            temp = num / 16;

            if(temp > 9)             //ת��ΪASCII��
                temp = temp + 0x37;
            else
                temp = temp + 0x30;

            Now_Num[12] = temp;
            temp = num % 16;

            if(temp > 9)             //ת��ΪASCII��
                temp = temp + 0x37;
            else
                temp = temp + 0x30;

            Now_Num[13] = temp;
            Show_Num(0, 1, (char*)Now_Num);
            Delay_ms(10);
        }

        while(!B_IN());
    }
}
