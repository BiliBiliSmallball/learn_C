/*
���Ľڿ�:
1.�ַ���
*/

//�����ַ������﷨
#include<stdio.h> //һ����д������
void Char(){    
    char name[5];
    name[1]= 'I';
    name[2]= 'a';//�Ƿ񵥸�Ԫ�ؽ��и�ֵ����char[n] = ��a����ֻ����һ��Ԫ�ء�
    name[3]= 'm';
    name[4]= 'C';
    //���� char name[5] = {"i","love",'fish','C'}
    char IN_get[] = "�������ֱ��д\0";//��ֹ��"\0"
	printf("%s,\n%s\n",IN_get,name);
}

//����ת��
//��ʵ����py����Ĺ�������
//�÷���(ת��������)shuji
void Change(){
    int a = 10;
    char b[] = "�и������ǣ�";
    printf("�������:%S",a)+b;//������ 
}

//�����
int main(){
    Char();
    Change();
    system("pause");
    return 0;//�����0������֡� 
}
