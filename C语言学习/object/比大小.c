#include<stdio.h>
#include<math.h>

//��д�����������������ͣ��ϴ�ķ���
//��Ϊ4.0�Ĳ���

//��һ�ֶ��巨�����㲻����coid Max(int,int)
//�����Ȳ���д����������

int Max(int x,int y){
    if (x > y)
    {
        return x;//return ����ˣ�����Ĵ���Ͳ���ִ���ˡ�
    }
    else{
        return y;
    }
}

int main(){
    int x,y,z;
    printf("�����������������Զ��ŷָ���");
    scanf("%d,%d",&x,&y);       //��ʽռλ���Զ��ŷָ�������ʱ��Ҫ�Զ��ŷָ���������
    z =Max(x,y);                //����ֵ�ĵ�����
    printf("�����нϴ����%d",z);
    return 0;
} 
