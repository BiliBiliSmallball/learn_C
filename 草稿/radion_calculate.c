#include <stdio.h>  

void one(){
	//����һ���������жϸ�������������ż��
	int i;
	printf("������һ������\n");
	scanf("%d",&i);
	if(i%2==0){
		printf("����һ��ż����\n");
	}
	else{
		printf("����һ��������\n");
	}
}
//
//void two(){
//	//�������100������
//	for(int i=3;i<=300;i++){
//		if (i%i == 0)
//		{		
//		printf("%d��һ������",i);
//		}
//	}
//}

void three(){
	int i =1,sum=0; 
	while(i <= 100){
		sum = i+sum ;
	}
	printf("I��ֵΪ: %d",i);
}

int main(){
	three();
	printf("\n���������ڶ��⡪������\n"); 
//	two();
	system("pause");
	return 0;
}
