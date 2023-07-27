#include<stdio.h>
#include<math.h>//数学专属库

//编写一个函数，让他从1+2+3+4+......+(n-1)+他自己（Sn = 1+2+3+4+......+(n-1)+n）
//这不就是等差前N相和嘛
int sun(int n){
    int result =0;//设定初始值，让他从0开始
    do{
        result +=n;//改下就可弄等差数列，但是我为啥不直接套公式呢？
    }while(n-- >0);
    return  result;
}

int main(void){
    int n;
    printf("本程序作用是从1加到某个数N，");
    printf("所以请输入N吧:\n");
    scanf("%d",&n);
    printf("结果为:%d", sun(n));
    return 0;
}