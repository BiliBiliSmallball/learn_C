/***************************
第一个程序 

***************************/

//转义字符：
//\n 换行  \a响铃 \t制表符  \v制表符  \r回车  \b删除一个字符 单独一个“/”表示换行


#define URL "wwww.github.com";//以 #defin 为前置标识来表示常量
int be = 100;



#include <iostream>//库，以#include声明

int main()//主函数
{
	int a;//变量定义
	a = 100;//变量表述
	printf("我有 %f 元\n",be);//格式化输出
	printf("你干嘛！~ 哎呦~\n");//调用printf函数输出
	return 0;
}
/*
转换符：在printf()中用于格式化各类字符的
*/