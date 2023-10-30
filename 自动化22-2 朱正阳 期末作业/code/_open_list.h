#include "./hand.h"
// 本程序的作用是从txt文件中读取本班人数，并生成一组二维数组来存储信息

// 创建结构体储存读取的信息  
struct student  
{  
    char student_name[30];  
} stu[100];  
  
// 将输入的文件的内容导入，并得到总人数  
struct student* FileRead(const char *filename)    
{  
    FILE *fp = fopen(filename, "r");  
    if (fp == NULL) // 若没有文件可读，则返回错误信息  
    {  
        printf("无法打开文件！请确认是否出错");  
        return NULL;   
    }  
    int i;  
    for (i = 0; !feof(fp); i++) // 将读到的信息录入结构体中  
    {  
        fgets(stu[i].student_name, 30, fp);  
        printf("%s\n",stu[i].student_name);  
        if(feof(fp)) break; // 如果已经到达文件末尾，跳出循环  
    }  
    stu[i].student_name[strlen(stu[i].student_name)-1]='\0'; // 删除换行符    
    fclose(fp);  // 释放指针，注意这里应该放在for循环之后，否则会出现未定义的行为  
    return stu; // 返回人员名单指针   
}  

/*在上面的代码中，我们使用 malloc 函数动态分配了二维数组 names 的每一行，以及每一行中的名字。
函数返回时，names 数组中的每一行都指向一个动态分配的字符串，这些字符串存储了文件中的名字。
注意，在使用完 names 数组后，你需要调用 free 函数释放动态分配的内存。
*/
