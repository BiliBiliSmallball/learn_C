/*********************
3.1的补充课
这个是拿到课本以后，对于输入输出的补充。
很奇怪，比算法比不过人家，比经验又有一大堆问题，你以前到底在干嘛啊。  -----2023年9月9日
*********************/ 
#include<stdio.h>

void string_test(void);{
    char str[100]="hello world";
    
    //putchar函数:只能打印一个字符
    putchar("v");
    //getchar函数:取这一行的最后一个字符
    getchar();
}

void long_string_test(void){
    char str[100]="hello world";

    //gets()函数，作用是实现字符串的输入（获取）
    gets(str);
    //puts()函数，以字符一一行的展示
    puts(str);
}

int main(void){
    string_test();
    long_string_test(); 
    return 0;
}