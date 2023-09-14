#include <stdio.h>  

void one(){
	//a,b,c三个数，找出最大的数
	int a,b,c;
	printf("请输入三个数\n");
	scanf("%d %d %d",&a,&b,&c);
	
	if(a=b=c){
		printf("我们都一样");
	}
	else if (a > b)
	{
		printf("最大的数字是：a,值为%d",a);
	}
	else if (c > b)
	{
		printf("最大的数字是：c,值为%d",c);
	}
	else{
		printf("最大的数字是：b,值为%d",b);
	}
}

void two(){
	//空代码
}

int main(){
	one();
	printf("\n————第二题————\n"); 
	two();
	system("pause");
	return 0;
}
