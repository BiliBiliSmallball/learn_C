/*********************
3.1�Ĳ����
������õ��α��Ժ󣬶�����������Ĳ��䡣
����֣����㷨�Ȳ����˼ң��Ⱦ�������һ������⣬����ǰ�����ڸ��ﰡ��  -----2023��9��9��
*********************/ 
#include<stdio.h>

void string_test(void);{
    char str[100]="hello world";
    
    //putchar����:ֻ�ܴ�ӡһ���ַ�
    putchar("v");
    //getchar����:ȡ��һ�е����һ���ַ�
    getchar();
}

void long_string_test(void){
    char str[100]="hello world";

    //gets()������������ʵ���ַ��������루��ȡ��
    gets(str);
    //puts()���������ַ�һһ�е�չʾ
    puts(str);
}

int main(void){
    string_test();
    long_string_test(); 
    return 0;
}