#include <stdio.h>

long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    
    printf("Podaj liczbe calkowita: ");
    scanf("%d", &n);
    
    printf("Silnia z %d = %ld\n", n, factorial(n));
    return 0;
}