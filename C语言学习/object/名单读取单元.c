#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

#define MAX_NAME_LENGTH 50  
#define MAX_STUDENTS 300

int main() 
{	
    FILE *file;
    file = fopen("../前置条件/destination_folder/students.txt", "r");
    if (file == NULL) {  
        printf("无法打开文件\n");  
        return 1;  
    }
	

	char names[MAX_STUDENTS][MAX_NAME_LENGTH];  // 定义一个字符串数组用于存储名单  
    int num_names = 0;  

	fseek(file,0,SEEK_SET);
    while (!feof(file) && num_names < MAX_STUDENTS) {  // 循环读取每一行，直到文件结束或名单已满  
        fscanf(file, "%s", names[num_names]);  // 读取一行  
        num_names++;
    }  
  
    fclose(file);  // 关闭文件  
  	printf("成功读取了：%d 行\n",num_names);
	
	// 使用当前时间作为种子来初始化随机数生成器
	srand(time(NULL));
	// 生成一个随机数，并对其进行取模运算，以获取在有效学生范围内的随机索引
	int selected_student = rand() % num_names;
	printf("\n %d",strlen(names[selected_student]));

	// 输出
	printf("抽取的学生是：%s 学号为 %d\n", names[selected_student], selected_student);
	system("pause"); 
    return 0;
}eturn 0;
}