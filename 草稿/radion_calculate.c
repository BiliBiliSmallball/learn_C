#include <stdio.h>  

void one(){
	//输入一个字符，返回这一字符的ASCII码，并求出其ASCII码相邻的两位且按顺序输出
	char a;
	printf("请输入一个字\n");
	scanf("%c",&a);
	printf("这个字是：%d\n",a);
	printf("前一位是%c,该位是%c 后一位是%c\n",a-1,a,a+1);
}

void two(){
	//计算输入的四个浮点数的平均值
	float a,b,c,d;double avg,sum;
	
	scanf("%f %f %f %f",&a,&b,&c,&d);
	
	avg = (a + b + c + d)/4;
	sum = a + b + c + d;

	printf("该生总分为 %f,该生平均分为 %f \n",sum,avg);
}

int main(){
	one();
	printf("————第二题————\n"); 
	two();
	system("pause");
	return 0;
}
