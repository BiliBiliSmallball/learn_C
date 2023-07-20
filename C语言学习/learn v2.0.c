/*
第五节课（逻辑课）:
1.关系运算符
*/

#include<stdio.h>
// 关系运算符
// 这个反而是整个过程最简单的东西.
// 注意:输出的结果只有两种:0;或者1

void Compare(){
    char a = '5';
    int b = 10;
    float c = 1.5;
    int d = 2;
    printf("a和b比较的结果是 %d",a > b);//39 > 10,输出1 
}

int main(){
    Compare();
    return 0;
}
