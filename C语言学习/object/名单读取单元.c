#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

#define MAX_NAME_LENGTH 50  
#define MAX_STUDENTS 300

int main() 
{	
    FILE *file;
    file = fopen("../ǰ������/destination_folder/students.txt", "r");
    if (file == NULL) {  
        printf("�޷����ļ�\n");  
        return 1;  
    }
	

	char names[MAX_STUDENTS][MAX_NAME_LENGTH];  // ����һ���ַ����������ڴ洢����  
    int num_names = 0;  

	fseek(file,0,SEEK_SET);
    while (!feof(file) && num_names < MAX_STUDENTS) {  // ѭ����ȡÿһ�У�ֱ���ļ���������������  
        fscanf(file, "%s", names[num_names]);  // ��ȡһ��  
        num_names++;
    }  
  
    fclose(file);  // �ر��ļ�  
  	printf("�ɹ���ȡ�ˣ�%d ��\n",num_names);
	
	// ʹ�õ�ǰʱ����Ϊ��������ʼ�������������
	srand(time(NULL));
	// ����һ������������������ȡģ���㣬�Ի�ȡ����Чѧ����Χ�ڵ��������
	int selected_student = rand() % num_names;
	printf("\n %d",strlen(names[selected_student]));

	// ���
	printf("��ȡ��ѧ���ǣ�%s ѧ��Ϊ %d\n", names[selected_student], selected_student);
	system("pause"); 
    return 0;
}eturn 0;
}