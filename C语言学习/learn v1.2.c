/*
�����ڿ�:
1.��ʶ����sizeof
*/

//sizeof(����)   �����鿴�������С����ռ�ߴ磩
//һ��Ҫ��printfһ����

#include<stdio.h>

void _Sizeof(){
    char a = "����һ���ַ�";
    printf("a��������%d",sizeof(a));
}

//�˷�����pwo()
void cf(){
    int result = pow(2,5) + 3;
    printf("���� result �Ľ��Ϊ%d,\n��СΪ%d" , result,sizeof result); 
    //return 0;  															�㺯��дvoid(�޷���ֵ��returnɶ��) 
}

//�ַ���
char a [] ={"��","shi","��"};

//�����
int main(){
    _Sizeof();
    cf();
    printf("%s\n",a);
    return 0;
}
