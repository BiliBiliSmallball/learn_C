#include <stdio.h>  
  
void one() {  
    float x=3.5;
	int z=8;  
    char finish;  
    finish = x + z %3/4;  //��C�����У����㳢�Խ�һ����������float����һ��������int����������ʱ���������ᱻת��Ϊ������������ΪC���Բ�֧���������͸�����֮����Զ�����ת����
    printf("%.2f\n", finish);  
}

void two(){
	int a;
	a=1,a+=1,a+1,a++;
	printf("���Ϊ:%d",a); 
}

int main(){
	two();
	return 0;
}
