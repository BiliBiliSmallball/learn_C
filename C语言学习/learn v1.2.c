/*
�����ڿ�:
1.��ʶ����sizeof
*/

//sizeof(����)   �����鿴�������С����ռ�ߴ磩
//һ��Ҫ��printfһ����

#include<stdio.h>
#include<math.h>
void _Sizeof(){
    char a = 'A';//����һ��char���͵ı���a
    printf("a��������%d",sizeof(a));
}

//�˷�����pwo()
void cf(){
    int result = pow(2,5) + 3;
    printf("���� result �Ľ��Ϊ%d,\n��СΪ%d" , result,sizeof result); 
    //return 0;  															�㺯��дvoid(�޷���ֵ��returnɶ��) 
}

//�ַ�
//�����Ͼ�������ASCII����н����Ķ���
void str(){
	char a = 'C';
	printf("%c = %d\n",a,a);
} 

//�����
int main(){
    _Sizeof();
    cf();
    str();
    system("pause"); 
    return 0;
}
