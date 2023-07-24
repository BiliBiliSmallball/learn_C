//对应learn3.0.c里面的内容
#include <stdio.h>
#define NUM 10//一共10位，先定好

int main(){
    int s[NUM];
    int i, sum = 0;
    for (i = 0; i < NUM; i++)
    {
        printf("请输入第%d位同学的成绩： \n", i + 1);
        scanf("%d",&s[i]);
        while(s[i] > 100 || s[i] < 0)
		{
        	printf("你输入正确的成绩了吗?\n");//条件判断
            scanf("%d",&s[i]);
		}
	    sum += s[i];
    }
    printf("成绩录入完毕！本次考试的平均分是： %.3f\n",(double)sum / NUM);
    return 0;
}
