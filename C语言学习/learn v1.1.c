/*
第二节课:
1.常量
*/
//常量:用#define [标识符（变量名)] [变量内容]来进行定义，
//没有指定类型
//当你在这里定义一个字符串时，下面的同名变量如果没有再次声明，都是这个量

#define URL "我是一串字符。"
#define NB 111
#define longger int 10

int main(){
    printf("%s",longger)//这里我没有在函数里面定义longger，但是因为前面全局已经写了
}
cascas