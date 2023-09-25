/*
第六节课（杂技）:
1.if(三种)
2.while(开始判断，结束判断)
3.for
4.switch
*/ 
#include<stdio.h>
//for语句
//如果你写的非常多的你就会发现就会发现：有的时候循环只是为了能够计时
//所以就有一些快捷的写法：
// for (类型 i = 0; i < 总次数; i++)
// {
//     代码
//}
void first(){
	int i;
    for (i = 0; i < 50; i++)
    {
        printf("现在是%d\n",i);
    }
    //for的三个参数都可以省略。
}

//switch
//这个比较特殊，应该放在if那份文件里面，但是这个奇葩他没有什么表达式之类的东西！
// 就是一个量，然后当到达对应值时就结束

// switch 语句中的 expression 是一个常量表达式，必须是一个整型或枚举类型。
// 在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
// case 的 constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量。

//格式
// switch (判断量)
// {
// case /* 常量表达式*/:
//     代码
//     break;
//     （或者）
//     continue;
// default:
//     break;
// }
void secend(){
    int i = 1;
    while (i <=10 )
    {
    i++;
    switch (i){
        case 5:
            printf("现在是5\n");
            break;
        case 10:
            printf("现在是10\n");
            break;
        default:
            printf("还没到5或者10哦\n");
            break;
        } 
    } 
}
//goto [lable]
//名称
void test_goto(){
    int i=1,sum;
    loop:if (i<=100)
    {
        i++;
        goto loop;
    }
    
}

int main(){
	first();
	secend();
    int a,b;
    a=3,b=4;
    a<b?printf("这是真的"):printf("这是假的");//三元运算符： 判断条件？真:假
	system("pause");
	return 0;
}
