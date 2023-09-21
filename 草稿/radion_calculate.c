#include <stdio.h>
#include <math.h>

int main() {
    int m,n,sum;                        //sum是为了算最后的合计
    printf("请输入两个数字: m,n\n");
    scanf("%d %d",&m,&n);
    
    //加个前置的条件判断
    if(	m<=0 && m>n){
    	printf("m是不合法的数字！");
	}
	else{
    	for (; m <= n; m++)
    	{
        	sum = pow(m,2) + 1/m;
        	printf("%d \n",sum);
    	}
    printf("sum = %.6f\n",sum);
	}
    return 0;
}

