#include<stdio.h>
#include<math.h>//��ѧר����

//��дһ��������������1+2+3+4+......+(n-1)+���Լ���Sn = 1+2+3+4+......+(n-1)+n��
//�ⲻ���ǵȲ�ǰN�����
int sun(int n){
    int result =0;//�趨��ʼֵ��������0��ʼ
    do{
        result +=n;//���¾Ϳ�Ū�Ȳ����У�������Ϊɶ��ֱ���׹�ʽ�أ�
    }while(n-- >0);
    return  result;
}

int main(void){
    int n;
    printf("�����������Ǵ�1�ӵ�ĳ����N��");
    printf("����������N��:\n");
    scanf("%d",&n);
    printf("���Ϊ:%d", sun(n));
    return 0;
}