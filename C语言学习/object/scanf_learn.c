//创造标准文件
#include <stdio.h>

int main(){
    int a;
    printf("程序已开始运行\n");
    
	//将从键盘输入的字符转化为输入控制符所规定格式的数据，然后存入以输入参数的值为地址的变量中 
    scanf("%d",&a);	//这里还暗含了转换的功能		
    
	printf("输入的结果为：%d \n",a);
    system("pause");
    return 0;
}
//getchar与scanf最主要的区别在于，在运行某些特殊的程序时有的要求输入空格，scanf不能识别空格而getchar可以识别空格
