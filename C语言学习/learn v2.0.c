/*
第五节课（逻辑课）:
1.关系运算符
2.逻辑表达式
顺序：
! > 算数运算符 > 关系运算符 > && > || >赋值  
*/ 

#include<stdio.h>
// 关系运算符
// 这个反而是整个过程最简单的东西.
// 注意:输出的结果只有两种:0;或者1
// >大于  <小于 >=大于等于 <=小于等于 ==恒等于 !=不等于

void Compare(){
    char a = '5';
    int b = 10;
    float c = 1.5;
    int d = 1.5;
    //告诉下abcd分别是啥 
	printf("    char a = '5';\
    int b = 10;\
    float c = 1.5;\
    int d = 1.5\n"); 
    
    //看结果 
    printf("a和b比较的结果是 %d\n",a > b);//39 > 10,输出1
    printf("b小于等于c是: %d\n",b <= c);
    printf("d != c的比较结果是: %d\n",d != c); 
}

// 逻辑表达式(还会背真值表吗?)
// 逻辑与 &&(7上面那个)    逻辑或 ||        逻辑非!
// 需要注意：在判断一个逻辑值时，以0表示假，以任何非0表示真。 
void panduan(){
    char a = (3+1 || 2 ==0);
    char b = (!(a+b));
    char c = (!0 + 1 <  1||!(3+4));
    char d = 'a'-'b' && 'c';
    printf("结果1为:%d,\n结果2为:%d,\n结果3为:%d\n结果4为：%d;\n",a,b,c,d);
}

//


//看结果
int main(){
    Compare();
    panduan();
    system("pause");
    return 0;
}
