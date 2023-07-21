/*
第六节课（算法课）:
1.if(三种)
2.while(开始判断，结束判断)
3.switch
*/ 

//第一种（开始判断）
// 先判断后执行
//while (表达式)
// {
//     代码
// }
#include<stdio.h>
void first(){
	int i;
	printf("请输入一个数字:");
	scanf("%d",&i);
	
	//循环体 
    while ( i <= 100)
    {
       i++;
       printf("现在的i为: %d\n",i);
    }
}

//  第二种（开始判断）
// 先判断后执行
// do
// {
//    代码
// } while (表达式);
void secend(){
    int i = 0;                              //解释下这两有什么区别：
    while (i != 0)                          //do....while（）的格式是结束式，也就是先执行完一遍代码再判断    
    {                                       //所以后面的就可以正常执行（int i在判断之前先加了个1）
        i++;                                //但是第一个就不行，因为在判断之前就错了
        printf("现在的i的值为:%d\n",i);
    }
	printf("第一个已经结束。");//看来while后面带不了else 

    do
    {
        i++;
        printf("现在的i的值为:%d\n",i);
    } while (i != 0 && i <= 10);
    
}



int main(){
    first();
    secend();
    system("pause");
    return 0;
}
