#include "./hand.h"
// ������������Ǵ�txt�ļ��ж�ȡ����������������һ���ά�������洢��Ϣ

// �����ṹ�崢���ȡ����Ϣ  
struct student  
{  
    char student_name[30];  
} stu[100];  
  
// ��������ļ������ݵ��룬���õ�������  
struct student* FileRead(const char *filename)    
{  
    FILE *fp = fopen(filename, "r");  
    if (fp == NULL) // ��û���ļ��ɶ����򷵻ش�����Ϣ  
    {  
        printf("�޷����ļ�����ȷ���Ƿ����");  
        return NULL;   
    }  
    int i;  
    for (i = 0; !feof(fp); i++) // ����������Ϣ¼��ṹ����  
    {  
        fgets(stu[i].student_name, 30, fp);  
        printf("%s\n",stu[i].student_name);  
        if(feof(fp)) break; // ����Ѿ������ļ�ĩβ������ѭ��  
    }  
    stu[i].student_name[strlen(stu[i].student_name)-1]='\0'; // ɾ�����з�    
    fclose(fp);  // �ͷ�ָ�룬ע������Ӧ�÷���forѭ��֮�󣬷�������δ�������Ϊ  
    return stu; // ������Ա����ָ��   
}  

/*������Ĵ����У�����ʹ�� malloc ������̬�����˶�ά���� names ��ÿһ�У��Լ�ÿһ���е����֡�
��������ʱ��names �����е�ÿһ�ж�ָ��һ����̬������ַ�������Щ�ַ����洢���ļ��е����֡�
ע�⣬��ʹ���� names ���������Ҫ���� free �����ͷŶ�̬������ڴ档
*/
