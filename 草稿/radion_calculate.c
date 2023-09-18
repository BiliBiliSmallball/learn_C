#include <stdio.h>  

void one(){
	//输入一个数，并判断该数是奇数还是偶数
	int i;
	printf("请输入一个数。\n");
	scanf("%d",&i);
	if(i%2==0){
		printf("这是一个偶数。\n");
	}
	else{
		printf("这是一个奇数。\n");
	}
}
//
//void two(){
//	//输出三到100的素数
//	for(int i=3;i<=300;i++){
//		if (i%i == 0)
//		{		
//		printf("%d是一个素数",i);
//		}
//	}
//}

void three(){
	int i =1,sum=0; 
	while(i <= 100){
		sum = i+sum ;
	}
	printf("I的值为: %d",i);
}

int main(){
	three();
	printf("\n————第二题————\n"); 
//	two();
	system("pause");
	return 0;
}
