#include <stdio.h>

// ��д���򣬴Ӽ���������һ���˽��Ƶ���������ת�ɶ����ƣ����ѽ����ʾ����

int main()
{
	int oct_num, bin_num;

	printf("������һ���˽��Ƶ�����");
	scanf("%o", &oct_num);

	bin_num = oct_num;

	printf("�����Ʊ�ʾΪ��");
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
// 	printf("������һ���˽�������");
// 	scanf("%o", &n);

// }
