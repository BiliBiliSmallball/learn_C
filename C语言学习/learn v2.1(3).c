/*
�����ڿΣ��Ӽ���:
1.if(����)
2.while(��ʼ�жϣ������ж�)
3.for
4.switch
*/ 
#include<stdio.h>
//for���
//�����д�ķǳ������ͻᷢ�־ͻᷢ�֣��е�ʱ��ѭ��ֻ��Ϊ���ܹ���ʱ
//���Ծ���һЩ��ݵ�д����
// for (���� i = 0; i < �ܴ���; i++)
// {
//     ����
//}
void first(){
	int i;
    for (i = 0; i < 50; i++)
    {
        printf("������%d\n",i);
    }
    //for����������������ʡ�ԡ�
}

//switch
//����Ƚ����⣬Ӧ�÷���if�Ƿ��ļ����棬�������������û��ʲô���ʽ֮��Ķ�����
// ����һ������Ȼ�󵱵����Ӧֵʱ�ͽ���

// switch ����е� expression ��һ���������ʽ��������һ�����ͻ�ö�����͡�
// ��һ�� switch �п��������������� case ��䡣ÿ�� case ���һ��Ҫ�Ƚϵ�ֵ��һ��ð�š�
// case �� constant-expression ������ switch �еı���������ͬ���������ͣ��ұ�����һ����������������

//��ʽ
// switch (�ж���)
// {
// case /* �������ʽ*/:
//     ����
//     break;
//     �����ߣ�
//     continue;
// default:
//     break;
// }
void secend(){
    int i = 1;
    while (i <=10 )
    {
    i++;
    switch (i){
        case 5:
            printf("������5\n");
            break;
        case 10:
            printf("������10\n");
            break;
        default:
            printf("��û��5����10Ŷ\n");
            break;
        } 
    } 
}
//goto [lable]
//����
void test_goto(){
    int i=1,sum;
    loop:if (i<=100)
    {
        i++;
        goto loop;
    }
    
}

int main(){
	first();
	secend();
    int a,b;
    a=3,b=4;
    a<b?printf("�������"):printf("���Ǽٵ�");//��Ԫ������� �ж���������:��
	system("pause");
	return 0;
}
