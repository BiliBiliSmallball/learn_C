/*
ʹ�������ڽ���ͨ�ţ���һ���ڿ�������һ����
2023-07-16
*/
#include <stdio.h>
#include <system.h>	  //Ҫ�������ⲿ�ļ��зŵ�����ȥ

void Get_Point(){
    static char key;
    switch (key){
    case key == 1:
        P1 = 0x7f;
        break;
    case key == 2:
        P1 = 0xbf;
        break;
    case key == 3:
        P1 = 0xcf;
        break;
    case key == 4:
        P1 = 0xdf;
        break;
    case key == 5:
        P1 = 0xf7;
        break;
    case key == 6:
        P1 = 0xfb;
        break;
    case key == 7:
        P1 = 0xfc;
        break;
    case key == 8:
        P1 = 0xfd;
        break;    
    default:
        break;
    }
}

int main()
{
	System_Init();              //ϵͳ��ʼ��
	P1_Mode_OUT_PP(0xff);		//����P1�ڵĳ�ʼ��״̬
	P2_Mode_PullUp(0xff); 		//����p0��

	//������
    Get_Point(int);
	while(1);
}