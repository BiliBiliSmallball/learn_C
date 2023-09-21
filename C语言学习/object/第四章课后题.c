#include <stdio.h>
#include <math.h>

void one(){
    int number;
    printf("请输入一个整数: ");
    scanf("%d", &number);
    // 判断这个数除以 2 的余数
    if(number % 2 == 0)
        printf("%d 是偶数。", number);
    else
        printf("%d 是奇数。", number);
	printf("\n————第一题————\n");
}

void two(){
	//输出3到100的素数
	int i;
	for (i = 3; i < 100; i++)
	{
		if (i%2 == 0)
		{
			continue;
		}
		else{
			printf("%d\t",i);
		}	
	}
	printf("\n----第二题----\n");
}

void three(){
	//这题的思想是利用两个函数来解决这个问题
	//第一个是用函数实现阶乘 
	int row(int i){  
 		int secend, sum = 0;   
 		for(secend=1; secend <= i; secend++){  
 			sum *= secend; //阶乘就是从1*2*3**。。。。n  
 		}  
 	return sum;
	}  
 	
 	int total;  
 	total = row(5) + row(4) + row(3) + row(2) + row(1);  
 	printf("最后的结果是：%d \n", total);  
 	printf("----第三题----\n");  
}

void four(){
	int count = 0;
	char ch;
	scanf("%c",ch);
	while((ch=getchar()) != '\n'){
		count++;
	}
	printf("您一共写了 %d 个字符。",count);
} 

int main(){
	one();
	two();
	three();
	four();
	return 0;
}
