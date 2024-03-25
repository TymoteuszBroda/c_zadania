#include <stdio.h> 

//zrobione w funckcji avg
// int gradesSum(int array[], int size)
// {
//     int sum = 0;
//     for(int i = 0; i < size; i++)
//     {
//         sum += array[i];
//     }
//     return sum;
// }

float gradesAvg(int array[][2], int x, int y)
{
    int sum = 0;
    int total_grades = x * y;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            sum += array[i][j];
        }
    }
    return (float)sum / total_grades;
}

int main()
{
    int grades[5][2];
    for (int i = 0; i < 5; i++)
    {
        printf("Podaj ocenę ucznia %d z matematyki: ", i+1); 
        scanf("%d", &grades[i][0]);  
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Podaj ocenę ucznia %d z fizyki: ", i+1); 
        scanf("%d", &grades[i][1]);  
    }

    printf("Oceny uczniów z matematyki\n");
    for (int i = 0; i < 5; i++) {
        printf("Uczeń %d: Ocena %d\n", i+1, grades[i][0]);
    }
    printf("Oceny uczniów z fizyki\n");
    for (int i = 0; i < 5; i++) {
        printf("Uczeń %d: Ocena %d\n", i+1, grades[i][1]);
    }

    printf("Średnia ocen: %.2f\n", gradesAvg(grades, 5, 2)); 

    return 0;
}