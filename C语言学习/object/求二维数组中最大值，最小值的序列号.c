#include <stdio.h>  
  
void find_max_min_and_index(int a[][3], int m, int n) {  
    int i, j;  
    int maxVal = a[0][0];   // ��ʼ�����ֵΪa[0][0]  
    int minVal = a[0][0];   // ��ʼ����СֵΪa[0][0]  
    int maxRow = 0;         // ���ֵ���к�Ϊ0  
    int maxCol = 0;         // ���ֵ���к�Ϊ0  
    int minRow = 0;         // ��Сֵ���к�Ϊ0  
    int minCol = 0;         // ��Сֵ���к�Ϊ0  
  
    // ���������е�ÿһ��Ԫ�� a[i][j]  
    for (i = 0; i < m; i++) {  
        for (j = 0; j < n; j++) {  
            // ��� a[i][j] ���ڵ�ǰ�����ֵ maxVal  
            if (a[i][j] > maxVal) {  
                maxVal = a[i][j];  
                maxRow = i;  
                maxCol = j;  
            }  
            // ��� a[i][j] С�ڵ�ǰ����Сֵ minVal  
            if (a[i][j] < minVal) {  
                minVal = a[i][j];  
                minRow = i;  
                minCol = j;  
            }  
        }  
    }  
  
    // ������ֵ����Сֵ�������к�  
    printf("Maximum value: %d\n", maxVal);  
    printf("Minimum value: %d\n", minVal);  
    printf("Maximum value row: %d\n", maxRow);  
    printf("Maximum value column: %d\n", maxCol);  
    printf("Minimum value row: %d\n", minRow);  
    printf("Minimum value column: %d\n", minCol);  
}  
  
int main() {  
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};   // ��ά����ʾ��  
    int m = sizeof(a) / sizeof(a[0]);   // ���������  
    int n = sizeof(a[0]) / sizeof(a[0][0]);   // ���������  
  
    find_max_min_and_index(a, m, n);   // ���ú���������ֵ����Сֵ�������к�  
  
    return 0;  
}

/*������ĳ����У����Ƕ�����һ�� find_max_min_and_index ������������һ����ά���� a���Լ���������� m ������ n ��Ϊ������
�ں����У�����ʹ������Ƕ�׵�ѭ�����������е�����Ԫ�أ���ʹ�ñ��� maxVal �� minVal ����¼���ֵ����Сֵ��
ʹ�ñ��� maxRow��maxCol��minRow �� minCol ����¼���ֵ����Сֵ�����кš��������������ֵ����Сֵ�������кš�

�� main �����У����Ƕ�����һ����ά����ʾ���������� find_max_min_and_index ������������ֵ����Сֵ�������кš�*/