#include <stdio.h>

int is_prime(int number) {
    //���еķ���ֵ���и����˼�룬0�������1������ȷ


    if (number < 2) {//С��2�����ֲ�������
        return 0;
    }
    
    for (int i = 2; i < number; i++) {
    /*�������ǲ���ŷ��ɸ������ȡ�࣬����Ϊ0�ľ������������򷵻�0�����ǣ�*/
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void print_primes(int start, int end) {
    //������
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d��һ������\n", i);
        }
    }
}


int main(){
    print_primes(3, 100);
}