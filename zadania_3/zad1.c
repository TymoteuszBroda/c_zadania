#include<stdio.h>

int pascal(int r, int c)
{
    if(c == 0 || c == r)
    {
    return 1;
    }
    else
    {
    return pascal(r - 1, c - 1) + pascal(r - 1, c);
    }
}

void display(int n)
{
    for(int i = 0; i < n; i++)
    {
            

        for(int j = 0; j <= i; j++)
        {
        printf("%d ", pascal(i, j));
        }
        printf("\n");
    }
}

int main()
{
int h;
    printf("Enter height: ");
    scanf("%d", &h);
    display(h);
    return 0;
}