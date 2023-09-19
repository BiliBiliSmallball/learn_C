#include <stdio.h>

int is_prime(int number) {
    //所有的返回值都有个大的思想，0代表错误，1代表正确


    if (number < 2) {//小于2的数字不是素数
        return 0;
    }
    
    for (int i = 2; i < number; i++) {
    /*这里我们采用欧拉筛法。先取余，余数为0的就是素数，否则返回0（不是）*/
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void print_primes(int start, int end) {
    //主程序
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d是一个素数\n", i);
        }
    }
}


int main(){
    print_primes(3, 100);
}