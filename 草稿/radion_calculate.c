#include <stdio.h>  
  
void one() {  
    float x=3.5;
	int z=8;  
    char finish;  
    finish = x + z %3/4;  //在C语言中，当你尝试将一个浮点数（float）和一个整数（int）进行运算时，浮点数会被转换为整数。这是因为C语言不支持在整数和浮点数之间的自动类型转换。
    printf("%.2f\n", finish);  
}

void two(){
	int a;
	a=1,a+=1,a+1,a++;
	printf("结果为:%d",a); 
}

int main(){
	two();
	return 0;
}
