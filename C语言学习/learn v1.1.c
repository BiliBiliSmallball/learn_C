/*
第二节课:
1.常量
2.基本类型
3.通配对应
*/
//常量:用#define [标识符（变量名)] [变量内容]来进行定义，
//没有指定类型
//当你在这里定义一个字符串时，下面的同名变量如果没有再次声明，都是这个量
#include<stdio.h> 

#define URL "我是一串字符。"
#define NB 111
#define longger "你好"//这种是不对的写法-->   #define longger int 10

void _define(){
    printf("我要打的是：‘%s’",longger);//这里我没有在函数里面定义longger，但是因为前面全局已经写了
}

// 基本数据类型
// 包括整型（int）、字符型（char）、浮点型（float）和双精度浮点型（double），_Bool类型。
// 3.指针指向 void
// 长短
// 长型（long），短型(short)
// 特殊的关键词： unsigned
// 不管什么类型，前面加unsigned就没有负数形式。
// 以及，在没有insigned的情况下，一个变量的第一比特位是符号位


// enum:枚举类型
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
 
void Get_Day()
{
    enum DAY day;
    day = WED;
    printf("%d",day);
    return 0;
}


//void 类型指定没有可用的值。它通常用于以下三种情况下：
// 1.函数返回为空
// 中有各种函数都不返回值，或者您可以说它们返回空。不返回值的函数的返回类型为空。例如 void exit (int status);
// 2.函数参数为空
// 中有各种函数不接受任何参数。不带参数的函数可以接受一个 void。例如 int rand(void);

void Date_signed(){
    int a = 1111;
    double time = 213123221312313.23123213123123;
    unsigned int as = 1123213.3424;
    long double _init = 123123123.43952890387;
    printf("第一个%s,第二个%s,第三个%d",a,time,as); 
}


// 看结果
int main(){
    _define();//常量
    Date_signed();//数据类型
    Get_Day();//枚举类型说明
    system("pause");
    return 0;
}

//[Warning] incompatible implicit declaration of built-in function ‘scanf’ [enabled by default]
//错误原因，未声明 #include<stdio.h> 头文件 ，就使用头文件中的 printf 函数
