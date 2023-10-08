#include <stdio.h>  
  
void find_max_min_and_index(int a[][3], int m, int n) {  
    int i, j;  
    int maxVal = a[0][0];   // 初始化最大值为a[0][0]  
    int minVal = a[0][0];   // 初始化最小值为a[0][0]  
    int maxRow = 0;         // 最大值的行号为0  
    int maxCol = 0;         // 最大值的列号为0  
    int minRow = 0;         // 最小值的行号为0  
    int minCol = 0;         // 最小值的列号为0  
  
    // 对于数组中的每一个元素 a[i][j]  
    for (i = 0; i < m; i++) {  
        for (j = 0; j < n; j++) {  
            // 如果 a[i][j] 大于当前的最大值 maxVal  
            if (a[i][j] > maxVal) {  
                maxVal = a[i][j];  
                maxRow = i;  
                maxCol = j;  
            }  
            // 如果 a[i][j] 小于当前的最小值 minVal  
            if (a[i][j] < minVal) {  
                minVal = a[i][j];  
                minRow = i;  
                minCol = j;  
            }  
        }  
    }  
  
    // 输出最大值、最小值及其行列号  
    printf("Maximum value: %d\n", maxVal);  
    printf("Minimum value: %d\n", minVal);  
    printf("Maximum value row: %d\n", maxRow);  
    printf("Maximum value column: %d\n", maxCol);  
    printf("Minimum value row: %d\n", minRow);  
    printf("Minimum value column: %d\n", minCol);  
}  
  
int main() {  
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};   // 二维数组示例  
    int m = sizeof(a) / sizeof(a[0]);   // 数组的行数  
    int n = sizeof(a[0]) / sizeof(a[0][0]);   // 数组的列数  
  
    find_max_min_and_index(a, m, n);   // 调用函数求解最大值、最小值及其行列号  
  
    return 0;  
}

/*在上面的程序中，我们定义了一个 find_max_min_and_index 函数，它接受一个二维数组 a，以及数组的行数 m 和列数 n 作为参数。
在函数中，我们使用两个嵌套的循环遍历数组中的所有元素，并使用变量 maxVal 和 minVal 来记录最大值和最小值。
使用变量 maxRow、maxCol、minRow 和 minCol 来记录最大值和最小值的行列号。最后，我们输出最大值、最小值及其行列号。

在 main 函数中，我们定义了一个二维数组示例，并调用 find_max_min_and_index 函数来求解最大值、最小值及其行列号。*/