#include <stdio.h>  

void one(){
	//����һ���ַ���������һ�ַ���ASCII�룬�������ASCII�����ڵ���λ�Ұ�˳�����
	char a;
	printf("������һ����\n");
	scanf("%c",&a);
	printf("������ǣ�%d\n",a);
	printf("ǰһλ��%c,��λ��%c ��һλ��%c\n",a-1,a,a+1);
}

void two(){
	//����������ĸ���������ƽ��ֵ
	float a,b,c,d;double avg,sum;
	
	scanf("%f %f %f %f",&a,&b,&c,&d);
	
	avg = (a + b + c + d)/4;
	sum = a + b + c + d;

	printf("�����ܷ�Ϊ %f,����ƽ����Ϊ %f \n",sum,avg);
}

int main(){
	one();
	printf("���������ڶ��⡪������\n"); 
	two();
	system("pause");
	return 0;
}
