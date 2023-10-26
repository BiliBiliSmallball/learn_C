#include <stdio.h>
#include <stdlib.h>

#define M 100

// ����һ�������е����ֵ����Сֵ
void findMinMax(int arr[], int n, int *min, int *max) {
    int i;
    // ��ʼ�����ֵ����СֵΪ����ĵ�һ��Ԫ��
    *min = *max = arr[0];
    // �������飬�������ֵ����Сֵ
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
    // ѯ���û�Ҫ������ٸ�Ԫ��
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // ѯ���û�������ЩԪ��
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // ������������ֵ����Сֵ
    int min, max;
    findMinMax(arr, n, &min, &max);
    // ��ӡ�����ֵ����Сֵ
    printf("Minimum value is: %d\n", min);
    printf("Maximum value is: %d\n", max);
    return 0;
}

/*�����ʾ���У��������ȶ�����һ����ΪfindMinMax�ĺ�����������һ����������arr������Ĵ�Сn����������ָ��min��max��Ϊ������
�ں����ڲ����������ȳ�ʼ��min��maxΪ����ĵ�һ��Ԫ�أ�Ȼ��������飬����min��max��ֵ��
������ǽ�min��max��ֵ�ֱ�洢��*min��*max�С�

��main�����У����Ƕ�����һ����������arr��������������min��max��
Ȼ�����ǵ���findMinMax������������arr������Ĵ�Сn��min��maxָ����Ϊ�������ݸ�������
������Ǵ�ӡ��min��max��ֵ��*/