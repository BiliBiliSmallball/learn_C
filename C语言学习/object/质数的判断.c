//��Ӧlearn3.0.c���������
#include <stdio.h>
#define NUM 10//һ��10λ���ȶ���

int main(){
    int s[NUM];
    int i, sum = 0;
    for (i = 0; i < NUM; i++)
    {
        printf("�������%dλͬѧ�ĳɼ��� \n", i + 1);
        scanf("%d",&s[i]);
        while(s[i] > 100 || s[i] < 0)
		{
        	printf("��������ȷ�ĳɼ�����?\n");//�����ж�
            scanf("%d",&s[i]);
		}
	    sum += s[i];
    }
    printf("�ɼ�¼����ϣ����ο��Ե�ƽ�����ǣ� %.3f\n",(double)sum / NUM);
    return 0;
}
