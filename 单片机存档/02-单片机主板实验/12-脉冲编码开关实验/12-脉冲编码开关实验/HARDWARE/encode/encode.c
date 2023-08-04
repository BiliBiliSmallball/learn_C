#include "system.h"
#include "encode.h"
#include "lcd12864.h"

unsigned char Now_Num[] = "Now the num:    "; //现在的值
unsigned char temp, num = 0x40;

/**************************************************
函  数：	端口初始化
参  数：	无
返回值：	无
**************************************************/
void Encode_Hardware_Init(void)
{
    P2_Mode_HighZ(A_PIN | B_PIN | C_PIN);
}

/**************************************************
函  数：编码函数
参  数：	无
返回值：	无
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

            if(temp > 9)             //转换为ASCII码
                temp = temp + 0x37;
            else
                temp = temp + 0x30;

            Now_Num[12] = temp;
            temp = num % 16;

            if(temp > 9)             //转换为ASCII码
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

            if(temp > 9)             //转换为ASCII码
                temp = temp + 0x37;
            else
                temp = temp + 0x30;

            Now_Num[12] = temp;
            temp = num % 16;

            if(temp > 9)             //转换为ASCII码
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
