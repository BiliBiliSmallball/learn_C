/*
�ڶ��ڿ�:
1.����
2.��������
3.ͨ���Ӧ
*/
//����:��#define [��ʶ����������)] [��������]�����ж��壬
//û��ָ������
//���������ﶨ��һ���ַ���ʱ�������ͬ���������û���ٴ����������������
#include<stdio.h> 

#define URL "����һ���ַ���"
#define NB 111
#define longger "���"//�����ǲ��Ե�д��-->   #define longger int 10

void _define(){
    printf("��Ҫ����ǣ���%s��",longger);//������û���ں������涨��longger��������Ϊǰ��ȫ���Ѿ�д��
}

// ������������
// �������ͣ�int�����ַ��ͣ�char���������ͣ�float����˫���ȸ����ͣ�double����_Bool���͡�
// 3.ָ��ָ�� void
// ����
// ���ͣ�long��������(short)
// ����Ĺؼ��ʣ� unsigned
// ����ʲô���ͣ�ǰ���unsigned��û�и�����ʽ��
// �Լ�����û��insigned������£�һ�������ĵ�һ����λ�Ƿ���λ


// enum:ö������
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
 
void Get_Day()
{
    enum DAY day;
    day = WED;
    printf("%d",day);
    return 0;
}


//void ����ָ��û�п��õ�ֵ����ͨ������������������£�
// 1.��������Ϊ��
// ���и��ֺ�����������ֵ������������˵���Ƿ��ؿա�������ֵ�ĺ����ķ�������Ϊ�ա����� void exit (int status);
// 2.��������Ϊ��
// ���и��ֺ����������κβ��������������ĺ������Խ���һ�� void������ int rand(void);

void Date_signed(){
    int a = 1111;
    double time = 213123221312313.23123213123123;
    unsigned int as = 1123213.3424;
    long double _init = 123123123.43952890387;
    printf("��һ��%s,�ڶ���%s,������%d",a,time,as); 
}


// �����
int main(){
<<<<<<< HEAD
<<<<<<< HEAD
    printf("%s",longger)//这里我没有在函数里面定义longger，但是因为前面全局已经写了
}
cascas
=======
=======
>>>>>>> 8163acd7612e9c55b1b6ffc52dbf2b687b61cbca
    _define();//����
    Date_signed();//��������
    Get_Day();//ö������˵��
    system("pause");
    return 0;
}

//[Warning] incompatible implicit declaration of built-in function ��scanf�� [enabled by default]
//����ԭ��δ���� #include<stdio.h> ͷ�ļ� ����ʹ��ͷ�ļ��е� printf ����
<<<<<<< HEAD
>>>>>>> 8163acd7612e9c55b1b6ffc52dbf2b687b61cbca
=======
>>>>>>> 8163acd7612e9c55b1b6ffc52dbf2b687b61cbca
