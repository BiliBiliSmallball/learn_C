#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef struct
{ // ѧ������Ϣ���ܰ���������ѧ�ŵȡ�����ʹ�ýṹ�壨struct�����洢��Щ��Ϣ��
    char name[50];
    int id;
}Student;

int main() 
{	
    FILE *file;
    file = fopen("./ǰ������/destination_folder/students.txt", "r");
    if (file == NULL) {  
        printf("�޷����ļ�\n");  
        return 1;  
    }

    
    int num_students;  // ѧ����������Ҫ����ʵ�����ȷ��  
    Student *students;  
  
    // ��̬�����ڴ��Դ洢ѧ������  
    students = (Student *)malloc(num_students * sizeof(Student));//��̬�����ڴ棬�Դ洢num_students��ѧ������Ϣ��
    if (students == NULL) {  
        printf("�ڴ����ʧ��\n");  
        fclose(file);  
        return 1;  
    }
	
    while (fscanf(file, "%s %d", students[num_students].name, &students[num_students].id) != EOF) {//���ļ������ж�ȡѧ����������ѧ�ţ�������洢�ڽṹ�������С�ͬʱ������num_students�Լ�¼ѧ����������
    num_students++;  
    }
    fclose(file);

    printf("��ȡ�� %d ��ѧ����Ϣ��\n", num_students);
    int i;
    for (i=0; i < num_students; i++)
    {
        printf("ѧ�ţ�%d��������%s\n", students[i].id, students[i].name);
    }
	system("pause"); 
    return 0;
}