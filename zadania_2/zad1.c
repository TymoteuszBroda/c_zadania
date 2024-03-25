#include<stdlib.h>

int main()
{
    int val = 0;
    int*pointer = &val;
    *pointer = 1;
    printf("%d, %d",val, *pointer);
    return 0;
}