#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main() {  
    FILE *file;  
    char filename[] = "./ǰ������/destination_folder/students.txt";  
    char *content;  
    int length;  
  
    // ���ļ�  
    file = fopen(filename, "r");  
    if (file == NULL) {  
        printf("�޷����ļ� %s\n", filename);  
        return 1;  
    }  
  
    // ��ȡ�ļ����ݳ���  
    fseek(file, 0, SEEK_END);  
    length = ftell(file);  
    fseek(file, 0, SEEK_SET);  
  
    // �����ڴ��Դ洢�ļ�����  
    content = (char *)malloc(length + 1);  
    if (content == NULL) {  
        printf("�ڴ����ʧ��\n");  
        fclose(file);  
        return 1;  
    }  
  
    // ��ȡ�ļ����ݵ�����  
    fread(content, 1, length, file);  
    content[length] = '\0';  // ����ַ���������  
  
    // �ر��ļ�  
    fclose(file);  
  
    // ���ڣ�content ���������TXT�ļ�������  
    // ����Ը�����Ҫ��������в����������������  
  
    printf("�ļ����ݣ�\n%s\n", content);  
  
    // �ͷ��ڴ�  
    free(content);  
  
    return 0;  
}