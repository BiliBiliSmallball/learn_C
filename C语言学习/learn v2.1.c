/*
第六节课（算法课）:
1.if(三种)
*/ 

#include<stdio.h>
// if的表达方式有三种,悬挂式,条件判断,正反通用.
// if (表达式[条件])
// {
//     执行代码
// }

// if (表达式[条件])
// {
//     执行代码
// }
// else
// {
//     执行代码
// }

// if (表达式1[条件])
// {
//     执行代码
// }
// else if (表达式2[条件])
// {
//     执行代码
// }
// else
// {
//     执行代码
// }

int main(){
    unsigned int i;
    printf("请输入您的年龄");
    scanf("%d",&i);
    if ( i >= 18)
    {
        printf("已经成年,欢迎来到动物世界."); 
    }

    else if (i < 18)
    {
        printf("太小啦"); 
    }
    else
    {
      printf("你到底几岁?"); 
    }      

    system("pause");
    return 0;
}
