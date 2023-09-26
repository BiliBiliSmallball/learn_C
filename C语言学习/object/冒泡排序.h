#include<stdio.h>

//冒泡排序算法
void bubbleSort(int arr[],int n){

    int i, j, temp;  
    for (i = 0; i < n-1; i++) {  
        for (j = 0; j < n-i-1; j++) {  
            if (arr[j] > arr[j+1]) {  
                temp = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = temp;  
            }  
        }  
    }  
}  
  
int one() {  
    int arr[20] = {5, 2, 8, 4, 9, 1, 3, 7, 6, 10, 12, 14, 16, 18, 20, 11, 13, 15, 17, 19};  
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int i;  
    printf("原始数组内容为: ");  
    for (i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
    bubbleSort(arr, n);  
    printf("排列后数组为: ");  
    for (i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    return 0;  
}