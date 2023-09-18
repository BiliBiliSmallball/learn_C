#include <stdio.h>

int is_prime(int number) {
    if (number < 2) {
        return 0;
    }
    
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void print_primes(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d是一个素数\n", i);
        }
    }
}

void two() {
    print_primes(3, 300);
}

int main(){
    tow();
}