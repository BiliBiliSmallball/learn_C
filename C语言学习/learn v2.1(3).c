/*
�����ڿΣ��㷨�Σ�:
1.if(����)
2.while
3.switch
*/ 

//while (���ʽ)
// {
//     ����
// }

#include<stdio.h>
int i;
printf("������һ������:");
scanf("%d",&i);

int main(){
    while ( i <= 100)
    {
       i++;
       printf("���ڵ�iΪ: %d",i);
    }
    system("pause");
	return 0;
}

