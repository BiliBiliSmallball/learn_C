#include <stdio.h>
#include <math.h>
void one(){
	//通过格式化输入浮点数 a,b,c
	float a,b,c,y;
	printf("请输入a,b,c\n");
	scanf("%f %f %f",&a,&b,&c);
	
	a += 1;
	printf("%f\n",a);
	y = 2*a + b*b + c/5;
	
	printf("%f\n",y);
	if (y == 0)
	{
		printf("yes");
	}
	else
	{
		printf("NO");
	}

}


int main(){
	one();
	return 0;
}
