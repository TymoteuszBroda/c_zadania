#include <stdio.h>

union Data
{
    int i;
    float f;
    char ch;
};

int main()
{
    union Data data;

    data.i = 2;
    printf("int: %d\n", data.i);
    data.f = 2.2;
    printf("float: %d\n", data.f);
    data.ch = "C";
    printf("char: %d\n", data.ch);
    
    printf("\n\n\n");
    printf("int: %d\n", data.i);
    printf("float: %d\n", data.f);
    printf("char: %d\n", data.ch);
}