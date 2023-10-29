#include <stdio.h>
#include <stdlib.h>

#define M 100

// 返回一个数组中的最大值和最小值
void findMinMax(int arr[], int n, int *min, int *max) {
    int i;
    // 初始化最大值和最小值为数组的第一个元素
    *min = *max = arr[0];
    // 遍历数组，更新最大值和最小值
    for (i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        } else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int arr[M];
    int n, i;
    // 询问用户要输入多少个元素
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // 询问用户输入这些元素
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // 计算数组的最大值和最小值
    int min, max;
    findMinMax(arr, n, &min, &max);
    // 打印出最大值和最小值
    printf("Minimum value is: %d\n", min);
    printf("Maximum value is: %d\n", max);
    return 0;
}

/*在这个示例中，我们首先定义了一个名为findMinMax的函数，它接受一个整数数组arr、数组的大小n和两个整数指针min和max作为参数。
在函数内部，我们首先初始化min和max为数组的第一个元素，然后遍历数组，更新min和max的值。
最后，我们将min和max的值分别存储在*min和*max中。

在main函数中，我们定义了一个整数数组arr和两个整数变量min和max。
然后，我们调用findMinMax函数，将数组arr、数组的大小n和min和max指针作为参数传递给函数。
最后，我们打印出min和max的值。*/