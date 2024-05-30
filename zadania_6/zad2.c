#include <stdio.h>

int main()
{
    int array[10];

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    int *p = array;

    for (int i = 0; i < 10; i++) {
        printf("array[%d]: %d\n", i, *(p + i));
    }
    return 0;
}