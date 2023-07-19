//*******************************
//  PE8 ~ PE9�п�����
//  PE12~PE15�п�����

#include <system.h>
#include "key_4x4.h"

unsigned char const Key_Tab[4][4]=//���̱����
{
  {'1','4','7','*'},  
  {'2','5','8','0'},  
  {'3','6','9','#'},  
  {'A','B','C','D'}	
};
//û�еõ���ֵ����0�����򷵻���Ӧ�ļ�ֵ
uint8_t Get_KeyValue(void) //ʹ��PE8~PE15
{//ʹ���߷�ת��
  
	uint8_t i=5,j=5;
	uint16_t temp1,temp2;
  
	P6_Mode_HighZ(PIN_0|PIN_1|PIN_2|PIN_3);
	P6_Mode_PullUp(PIN_4|PIN_5|PIN_6|PIN_7);
	ClrBits(P6,PIN_4|PIN_5|PIN_6|PIN_7);
	if((P6&0xf)!=0xf)	//	�ж��Ƿ��а�������
 	{   
		Delay_ms(40);                   //��������
		if((P6&0xf)!=0xf)
		{			
			temp1=P6&0xf;          // ��ȡIDR 
			P6_Mode_PullUp(PIN_0|PIN_1|PIN_2|PIN_3);
			P6_Mode_HighZ(PIN_4|PIN_5|PIN_6|PIN_7);
			ClrBits(P6,PIN_0|PIN_1|PIN_2|PIN_3);
			if(((P6>>4)&0xf)!=0xf)	//	�ж��Ƿ��а�������
			{   
				Delay_ms(40);                   //��������
				if(((P6>>4)&0xf)!=0xf)        
					temp2=(P6>>4)&0xf;          // ��ȡIDR 
				while(((P6>>4)&0xf)==0xf);		//�ɿ�����
				switch(temp1)
				{
					case 0x0e:
						j=0;
						break;														
					case 0x0d:
						j=1;
						break; 
					case 0x0b:
						j=2;
						break;
					case 0x07:
						j=3;
						break;
					default:
						break;
				}
				switch(temp2)
				{
					case 0x0e:
						i=0;
						break;														
					case 0x0d:
						i=1;
						break; 
					case 0x0b:
						i=2;
						break;
					case 0x07:
						i=3;
						break;
					default:
						break;
				}
			}
			
		}
	}
	/****************��***********************/	
	if((i==5)||(j==5))
		return 0;
	else
		return (Key_Tab[i][j]);
}
