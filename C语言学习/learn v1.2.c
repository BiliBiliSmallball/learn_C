/*
第三节课:
1.标识符：sizeof
*/

//sizeof(名称)   用来查看数据体大小（所占尺寸）
//一定要跟printf一起用

#include<stdio.h>

void _Sizeof(){
    char a = "我是一串字符";
    printf("a的类型是%d",sizeof(a));
    return 0;
}

//乘方函数pwo()
void cf(){
    int result = pow(2,5) + 3;
    printf("变量 result 的结果为%d,\n大小为%d" , result,sizeof result)
    return 0;
}

//看结果
int main(){
    _Sizeof();
    cf();
    return 0;
}