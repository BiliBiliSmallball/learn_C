/*
第四节课:
1.字符串
*/

//定义字符串的语法
#include<stdio.h> //一定得写最上面
void Char(){    
    char name[5];
    name[1]= 'I';
    name[2]= 'a';//是否单个元素进行赋值，如char[n] = ‘a’，只能是一个元素。
    name[3]= 'm';
    name[4]= 'C';
    //或者 char name[5] = {"i","love",'fish','C'}
    char IN_get[] = "好像可以直接写\0";//截止符"\0"
	printf("%s,\n%s\n",IN_get,name);
}

//类型转换
//其实就是py里面的工厂函数
//用法：(转换后类型)shuji
void Change(){
    int a = 10;
    char b[] = "有个数字是：";
    printf("整型输出:%S",a + (int)b);//有问题 
}

//看结果
int main(){
    Char();
    Change();
    system("pause");
    return 0;
}
