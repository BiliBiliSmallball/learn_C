//ͷ����
#include<stdio.h>
#include<system.h>

//�趨����
SetBits LED1=P1^0;//�˿�
SetBits LED2=P1^1;
SetBits KEY1=P2^0;
SetBits KEY2=P2^1;


int main(){
	System_Init();//ϵͳ��ʼ��
	P1_Mode_OUT_PP(0x7f);//���ƵƵĿڳ�ʼ��
	P2_Mode_PullUp(0x00);//���ض����00
	if (KEY1 == 0)
	{
		LED1=0;
	}
	else if (KEY2 == 0)
	{
		LED2=1;
	}
	return 0;
}