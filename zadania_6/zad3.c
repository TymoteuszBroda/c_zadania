#include<stdio.h>

int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

int multiply(int a, int b)
{
    int sum = a * b;
    return sum;
}

int sub (int a, int b)
{
    int sum = a - b;
    return sum;
}

int main()
{
    int(*p)(int, int);
    int choice, x, y, result;

    printf("Co chcesz zrobić:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    scanf("%d", &choice);

     switch (choice) {
        case 1:
            p = &add;
            break;
        case 2:
            p = &multiply;
            break;
        case 3:
            p = &sub;
            break;
        default:
            printf("Brak takiej możliwości\n");
            return 1;
    }

    printf("Podaj swoje liczby: ");
    scanf("%d %d", &x, &y);

    result = p(x,y);
    printf("wynik: %d\n\n", result);
    return 0;
}