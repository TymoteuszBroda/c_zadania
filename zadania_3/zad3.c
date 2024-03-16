#include<stdlib.h>
#include<stdio.h>
int main()
{
    char line[5] = {"o","o","o","o","o"};
    int cols = 5;
    int** row = &line;
    int array[cols][sizeof(line)];
    for(int i = 0; i<= cols; i++)
    {
        printf(row);
    }
    return 0;
}