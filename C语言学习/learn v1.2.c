/*
�����ڿ�:
1.��ʶ����sizeof
2.�ַ�/�ַ���/ASCII�롣
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
//�����Ͼ�������ASCII����н����Ķ���,ASCII����16����
//00�գ�\0��;01����;02-03:�ı�;����07���س�0D��7F��ɾ����
//30-39��0-9��41-5A����дA_Z ��62-7A��Сдa-z��
void str(){
	char a = 75;
	printf("%c = %d\n",a,a);
} 

//�����
int main(){
    _Sizeof();
    printf("\n"); 
    cf();
    printf("\n");
    str();
    system("pause"); 
    return 0;
}
