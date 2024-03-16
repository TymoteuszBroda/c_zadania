#include <stdio.h>

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    unsigned int n;
    
    printf("Podaj liczbe calkowita: ");
    scanf("%u", &n);
    
    printf("Silnia z %u = %llu\n", n, factorial(n));
    return 1;
}
