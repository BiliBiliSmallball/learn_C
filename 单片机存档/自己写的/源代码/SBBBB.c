C51 COMPILER V9.01   SBBBB                                                                 07/15/2023 19:25:56 PAGE 1   


C51 COMPILER V9.01, COMPILATION OF MODULE SBBBB
OBJECT MODULE PLACED IN .\SBBBB.obj
COMPILER INVOKED BY: C:\Keil\C51\BIN\C51.EXE D:\������ƴ���\��Ƭ��\big dick\SBBBB.c BROWSE DEBUG OBJECTEXTEND PRINT(.\S
                    -BBBB.lst) OBJECT(.\SBBBB.obj)

line level    source

   1          #include <intrins.h>
   2          #include <stdio.h>
   3          #include "system.h"
   4          
   5          //������ˮЧ��
   6          void LED_Set(void){
   7   1              static int i;                           //���徲̬������i��
   8   1              i++;                                            //��i�������Լ�1��������������
   9   1              Delay_ms(1);                            //�ȴ�һ���루��Ӧһ�£�
  10   1              switch(i){
  11   2                      case 1:
  12   2                              P1 =0xf7;                       //������һ����
  13   2                              break;
  14   2                      case 100:
  15   2                              P1 =0xfb;                       //�����ڶ�����
  16   2                              break;
  17   2                      case 200:
  18   2                              P1 =0xfd;                       //������������
  19   2                              break;
  20   2                      case 300:
  21   2                              P1 = 0xfe;                      //�������ĸ���
  22   2                              break;
  23   2                      case 400:
  24   2                              P1 = 0xef;                      //�����������
  25   2                              break;
  26   2                      case 500:
  27   2                              P1 = 0x7f;                      //������������
  28   2                              break;
  29   2                      case 600:
  30   2                              P1 = 0xbf;                      //�������߸���
  31   2                              break;
  32   2                      case 700:
  33   2                              P1 = 0xfd;                      //�����ڰ˸���
  34   2                              break;   
  35   2                      case 800:
  36   2                              i=0;                            //ȫ��ѡ������
  37   2                              break;
  38   2              }
  39   1      }
  40          void main(void){ 
  41   1      
  42   1              System_Init();                                  //ϵͳ��ʼ��
  43   1              P1_Mode_OUT_PP(0xff);
  44   1           while(1)
  45   1               {      
  46   2                      LED_Set();
  47   2                      Delay_ms(100);//ÿ��ѡ����߹�һ��              
  48   2              }       
  49   1      }


MODULE INFORMATION:   STATIC OVERLAYABLE
   CODE SIZE        =    120    ----
   CONSTANT SIZE    =   ----    ----
C51 COMPILER V9.01   SBBBB                                                                 07/15/2023 19:25:56 PAGE 2   

   XDATA SIZE       =   ----    ----
   PDATA SIZE       =   ----    ----
   DATA SIZE        =      2    ----
   IDATA SIZE       =   ----    ----
   BIT SIZE         =   ----    ----
END OF MODULE INFORMATION.


C51 COMPILATION COMPLETE.  0 WARNING(S),  0 ERROR(S)
