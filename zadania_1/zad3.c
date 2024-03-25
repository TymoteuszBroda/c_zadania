#include<stdlib.h>
int silnia(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * silnia(n - 1);
}

int obliczSilnie(int array[], int size)
{
    for (int i = 0; i<size; i++)
    {
        int result = silnia(array[i]);
        printf("%d! = %d \n", array[i], result);
    }
}

int main(int argc, char const *argv[])
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(array)/sizeof(array[0]);
    obliczSilnie(array, size);
    return 0;
}
