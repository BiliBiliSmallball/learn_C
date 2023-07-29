#include<stdio.h>
#include<math.h>

//编写两个函数，接受整型，较大的返回
//此为4.0的补充

//第一种定义法（方便不出错）coid Max(int,int)
//可以先不用写出参数名字

int Max(int x,int y){
    if (x > y)
    {
        return x;//return 结果了，下面的代码就不再执行了。
    }
    else{
        return y;
    }
}

int main(){
    int x,y,z;
    printf("请输入两个整数（以逗号分隔）");
    scanf("%d,%d",&x,&y);       //格式占位符以逗号分隔，输入时就要以逗号分隔两个整数
    z =Max(x,y);                //函数值的导出；
    printf("他们中较大的是%d",z);
    return 0;
} 
