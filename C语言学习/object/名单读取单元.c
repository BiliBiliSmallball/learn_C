#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main() {  
    FILE *file;  
    char filename[] = "./前置条件/destination_folder/students.txt";  
    char *content;  
    int length;  
  
    // 打开文件  
    file = fopen(filename, "r");  
    if (file == NULL) {  
        printf("无法打开文件 %s\n", filename);  
        return 1;  
    }  
  
    // 获取文件内容长度  
    fseek(file, 0, SEEK_END);  
    length = ftell(file);  
    fseek(file, 0, SEEK_SET);  
  
    // 分配内存以存储文件内容  
    content = (char *)malloc(length + 1);  
    if (content == NULL) {  
        printf("内存分配失败\n");  
        fclose(file);  
        return 1;  
    }  
  
    // 读取文件内容到数组  
    fread(content, 1, length, file);  
    content[length] = '\0';  // 添加字符串结束符  
  
    // 关闭文件  
    fclose(file);  
  
    // 现在，content 数组包含了TXT文件的内容  
    // 你可以根据需要对数组进行操作或输出数组内容  
  
    printf("文件内容：\n%s\n", content);  
  
    // 释放内存  
    free(content);  
  
    return 0;  
}