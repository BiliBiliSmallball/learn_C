#include <stdio.h>
#include <math.h>

int main() {
    int m,n,sum;                        //sum��Ϊ�������ĺϼ�
    printf("��������������: m,n\n");
    scanf("%d %d",&m,&n);
    
    //�Ӹ�ǰ�õ������ж�
    if(	m<=0 && m>n){
    	printf("m�ǲ��Ϸ������֣�");
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

