// �����׼��������⣬���������������������  
#include<stdio.h>  
//P203ҳϰ��
//����10����������������С�������һ���Ի��������������һ���һ�
  
int input(void);  
int max_mix_value(int *p, int size);  
void output(int *p, int size);  


int input(void) {  
    int tic;  
    int arr[11];  
    for (tic = 0; tic < 10; tic++) {  
        scanf("%d", &arr[tic]);  
    }  
    return arr;  
}  
  
int max_mix_value(int arr[], int size) {  
    for (int i = 0; i < size - 1; i++) {  
        if (arr[i] > arr[i + 1]) {  
            int temp = arr[i];  
            arr[i] = arr[i + 1];  
            arr[i + 1] = temp;  
        }  
    }  
}  
  
void output(int p[], int size) {  
    for (int i = 0; i < size; i++) {  
        printf("%d ", p[i]);  
    }  
    printf("\n");  
}

int main() {  
    int arr[11];  
    max_mix_value(arr, sizeof(arr) / sizeof(int));  
    output(arr, sizeof(arr) / sizeof(int));  
    return 0;    
}  