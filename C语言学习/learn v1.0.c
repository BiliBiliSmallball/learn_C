/***************************
第一个程序 
1.结构
头文件
主函数{
	return 0
}

2.转义字符
\n 换行  \a响铃 \t制表符  \v制表符  \r回车  \b删除一个字符 单独一个“/”表示换行
***************************/
#include <iostream>//库，以#include声明
#include <studio.h>

//转义字符：
//\n 换行  \a响铃 \t制表符  \v制表符  \r回车  \b删除一个字符 单独一个“/”表示换行
void less1(){
	printf("第一个\t，第二个\n,第三个\v,第四个\r，第五个,,\b\n");
}



int main()//主函数
{
	int a;float be;//变量定义
	be = 100;//变量表述
	printf("我有 %f 元\n",be);//格式化输出
	printf("你干嘛！~ 哎呦~\n");//调用printf函数输出
	less1();//调用函数（跟py一样）
	system("pause");//冻结窗口 
	return 0;
}
/*
转换符：在printf()中用于格式化各类字符的
*/
