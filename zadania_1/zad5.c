#include <stdio.h>

int main()
{   int n=0, sum=0;
    printf("Podaj liczbe: \n");
    scanf("%d", &n);
    if (n<=0)
    {
        printf("\nSuma wynosi:%d, liczba była ujemna lub równa zeru=.", sum,"\n");
        return 0;
    }


    for (int i=1; i < n; i++)
    {
        if(i%3==0 || i%5==0)
        {
            sum += i;
        }
    }
    printf("Suma wynosi:\t %d", sum);
    return 0;
}