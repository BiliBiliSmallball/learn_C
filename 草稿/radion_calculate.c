#include <stdio.h>  

void one(){
	//a,b,c���������ҳ�������
	int a,b,c;
	printf("������������\n");
	scanf("%d %d %d",&a,&b,&c);
	
	if(a=b=c){
		printf("���Ƕ�һ��");
	}
	else if (a > b)
	{
		printf("���������ǣ�a,ֵΪ%d",a);
	}
	else if (c > b)
	{
		printf("���������ǣ�c,ֵΪ%d",c);
	}
	else{
		printf("���������ǣ�b,ֵΪ%d",b);
	}
}

void two(){
	//�մ���
}

int main(){
	one();
	printf("\n���������ڶ��⡪������\n"); 
	two();
	system("pause");
	return 0;
}
