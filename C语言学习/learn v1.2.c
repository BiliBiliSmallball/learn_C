/*
第三节课:
1.标识符：sizeof
*/

//sizeof(名称)   用来查看数据体大小（所占尺寸）
//一定要跟printf一起用

#include<stdio.h>
#include<math.h>
void _Sizeof(){
    char a = 'A';//定义一个char类型的变量a
    printf("a的类型是%d",sizeof(a));
}

//乘方函数pwo()
void cf(){
    int result = pow(2,5) + 3;
    printf("变量 result 的结果为%d,\n大小为%d" , result,sizeof result); 
    //return 0;  															你函数写void(无返回值你return啥？) 
}

//字符
//本质上就是利用ASCII码进行交代的东西
void str(){
	char a = 'C';
	printf("%c = %d\n",a,a);
} 

//看结果
int main(){
    _Sizeof();
    cf();
    str();
    system("pause"); 
    return 0;
}
