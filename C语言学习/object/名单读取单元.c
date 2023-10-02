#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef struct
{ // 学生的信息可能包括姓名、学号等。可以使用结构体（struct）来存储这些信息。
    char name[50];
    int id;
}Student;

int main() 
{	
    FILE *file;
    file = fopen("./前置条件/destination_folder/students.txt", "r");
    if (file == NULL) {  
        printf("无法打开文件\n");  
        return 1;  
    }

    
    int num_students;  // 学生数量，需要根据实际情况确定  
    Student *students;  
  
    // 动态分配内存以存储学生数据  
    students = (Student *)malloc(num_students * sizeof(Student));//动态分配内存，以存储num_students个学生的信息。
    if (students == NULL) {  
        printf("内存分配失败\n");  
        fclose(file);  
        return 1;  
    }
	
    while (fscanf(file, "%s %d", students[num_students].name, &students[num_students].id) != EOF) {//从文件中逐行读取学生的姓名和学号，并将其存储在结构体数组中。同时，递增num_students以记录学生的数量。
    num_students++;  
    }
    fclose(file);

    printf("读取到 %d 个学生信息：\n", num_students);
    int i;
    for (i=0; i < num_students; i++)
    {
        printf("学号：%d，姓名：%s\n", students[i].id, students[i].name);
    }
	system("pause"); 
    return 0;
}