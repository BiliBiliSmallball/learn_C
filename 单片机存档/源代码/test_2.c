/*
ʹ�������ڽ���ͨ�ţ���һ���ڿ�������һ����
2023-07-16
*/
#include <stdio.h>
#include <system.h>	  //Ҫ�������ⲿ�ļ��зŵ�����ȥ

void change(){
//�趨һ���ڣ�������ͻ�Ϊ0 
 	int i =0;
    do      
    {
       	P1 = 0x55;                //������
        Delay_ms(500);            //Get_Point(int);
		P1 = 0xaa;
		Delay_ms(500);
		i++;
    } while(i <= 9);
	P1 = 0x0f;
	Delay_ms(1000);
}


int main()
{
	System_Init();              //ϵͳ��ʼ��
	P1_Mode_OUT_PP(0xff);		//����P1�ڵĳ�ʼ��״̬��������
	P2_Mode_PullUp(0xff); 		//����p0��

	//������
	change();

}