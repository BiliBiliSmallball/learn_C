/*
第二节课:
1.常量
2.基本类型
3.通配对应
*/
//常量:用#define [标识符（变量名)] [变量内容]来进行定义，
//没有指定类型
//当你在这里定义一个字符串时，下面的同名变量如果没有再次声明，都是这个量

#define URL "我是一串字符。"
#define NB 111
#define longger "你好"//这种是不对的写法-->   #define longger int 10

void _define(){
    printf("%s",longger);//这里我没有在函数里面定义longger，但是因为前面全局已经写了
}

// 基本数据类型
// 包括整型（int）、字符型（char）、浮点型（float）和双精度浮点型（double），bool类型。
// 长型（long），短型(short)
// 特殊的关键词： unsigned（平常没区别，到转换的时候就要注意了）

//void 类型指定没有可用的值。它通常用于以下三种情况下：
// 1.函数返回为空
// 中有各种函数都不返回值，或者您可以说它们返回空。不返回值的函数的返回类型为空。例如 void exit (int status);
// 2.函数参数为空
// 中有各种函数不接受任何参数。不带参数的函数可以接受一个 void。例如 int rand(void);
// 3.指针指向 void


//通配

void Date_signed(){
    int a = 1111
    unsigned int as = 1123213.3424

}


// 看结果
int main(){
    _define();//常量
    return 0;
}
