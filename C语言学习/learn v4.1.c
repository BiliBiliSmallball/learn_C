/*********************
第十一课：
1.函数的嵌套调用：
在C语言中的函数在层级上
*********************/
#include <stdio.h>

//计算 s = 2^2!+3^2!        （2的平方的阶乘加三的平方的阶乘
long f1(int p){
    
    //本函数用来计算平方值
    int k;long r;           //k存储结果，r接受f2返回的结果
    long f2(int);
    k = p*p;
    r = f2(k);
    return r;
}

long f2(int q){

    //本函数用来计算其阶乘值
    long c=1;
    int i;
    for (i = 1; i <= q; i++)
    {
        c=c*i;
    }
    return c;
}

int main(){
    int i;
    long s=0;
    for (i = 2; i <= 3; i++)
    {
        s=s+f1(i);
    }
    printf("\n s=%ld\n",s);
    return 0;
}
/*上述的程序用了两个函数来分别实现两个功能，即乘方和加和
这种分步的思想也贯穿整个编程的生涯*/

//递归：我用我自己：

int inside(int n){
    if (n != 1){
        inside(n-1);//这里在函数本身调用了自己。
    }
    else{
        printf("现在是1\n");
    }
    return n;
}


//数组作为函数的参数
//与 python的列表不同，这里