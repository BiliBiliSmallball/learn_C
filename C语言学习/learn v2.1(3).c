/*
第六节课（算法课）:
1.if(三种)
2.while
3.switch
*/ 

//while (表达式)
// {
//     代码
// }

#include<stdio.h>
int i;
printf("请输入一个数字:");
scanf("%d",&i);

int main(){
    while ( i <= 100)
    {
       i++;
       printf("现在的i为: %d",i);
    }
    system("pause");
	return 0;
}

