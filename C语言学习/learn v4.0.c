/*********************
第十课：
1.函数入门
（本来是指针的，但是先跳了一点，电赛的时间可能不够了）————————————2023/7/27
*********************/ 
#include<stdio.h>
// 函数声明的关键字：void
// dataType functionName (传入参数1，类型 参数2){

    // 封装代码
    // (return 返回参数)
// }
// 其中
// dataType 是返回值类型，它可以是C语言中的任意数据类型，例如 int、float、char 等。
// functionName 是函数名，它是标识符的一种，命名规则和标识符相同。函数名后面的括号( )不能少。
// 如果有返回值，在函数体中使用 return 语句返回。return 出来的数据的类型要和 dataType 一样。

void hannshu(void){//void是空值

    printf("你好，我是函数里面的内容\n");

}

//带参函数：请见./object/等差数列计算；

//形参和实参

//函数调用(一般就是直接在mian()里面了)
int main(){
    hannshu();
    hannshu();//可以多次调用哦
    system("pause");
    return 0;
}