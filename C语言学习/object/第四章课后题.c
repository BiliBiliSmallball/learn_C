#include <stdio.h>
#include <math.h>

void one(){
    int number;
    printf("������һ������: ");
    scanf("%d", &number);
    // �ж���������� 2 ������
    if(number % 2 == 0)
        printf("%d ��ż����", number);
    else
        printf("%d ��������", number);
	printf("\n����������һ�⡪������\n");
}

void two(){
	//���3��100������
	int i;
	for (i = 3; i < 100; i++)
	{
		if (i%2 == 0)
		{
			continue;
		}
		else{
			printf("%d\t",i);
		}	
	}
	printf("\n----�ڶ���----\n");
}

void three(){
	//�����˼����������������������������
	//��һ�����ú���ʵ�ֽ׳� 
	int row(int i){  
 		int secend, sum = 0;   
 		for(secend=1; secend <= i; secend++){  
 			sum *= secend; //�׳˾��Ǵ�1*2*3**��������n  
 		}  
 	return sum;
	}  
 	
 	int total;  
 	total = row(5) + row(4) + row(3) + row(2) + row(1);  
 	printf("���Ľ���ǣ�%d \n", total);  
 	printf("----������----\n");  
}

void four(){
	int count = 0;
	char ch;
	scanf("%c",ch);
	while((ch=getchar()) != '\n'){
		count++;
	}
	printf("��һ��д�� %d ���ַ���",count);
} 

int main(){
	one();
	two();
	three();
	four();
	return 0;
}
