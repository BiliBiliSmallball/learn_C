#include <stdio.h>

// 编写程序，从键盘上输入一个八进制的数，把它转成二进制，并把结果显示出来

int main()
{
	int oct_num, bin_num;

	printf("请输入一个八进制的数：");
	scanf("%o", &oct_num);

	bin_num = oct_num;

	printf("二进制表示为：");
	while (bin_num > 0)
	{
		int remainder = bin_num % 2;
		printf("%d", remainder);
		bin_num /= 2;
	}
	printf("\n");

	return 0;
}
// {
// 	int n;
// 	printf("请输入一个八进制数：");
// 	scanf("%o", &n);

// }
