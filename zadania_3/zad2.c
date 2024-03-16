#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** przydzielMacierz(int wiersze, int kolumny) 
{
    int **macierz = (int **)malloc(wiersze * sizeof(int *));
    if (macierz == NULL) 
    {
        fprintf(stderr, "Błąd alokacji pamięci dla wierszy macierzy.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < wiersze; i++) 
    {
        macierz[i] = (int *)malloc(kolumny * sizeof(int));
        if (macierz[i] == NULL) 
        {
            fprintf(stderr, "Błąd alokacji pamięci dla kolumn macierzy.\n");
            exit(EXIT_FAILURE);
        }
    }
    return macierz;
}
void zwolnijMacierz(int **macierz, int wiersze) 
{
    for (int i = 0; i < wiersze; i++) 
    {
        free(macierz[i]);
    }
    free(macierz);
}
void wypelnijMacierz(int **macierz, int wiersze, int kolumny) 
{
    srand(time(NULL));
    for (int i = 0; i < wiersze; i++) 
    {
        for (int j = 0; j < kolumny; j++) 
        {
            macierz[i][j] = rand() % 100;
        }
    }
}

void wyswietlMacierz(int **macierz, int wiersze, int kolumny)
{
    printf("Zawartość macierzy:\n");
    for (int i = 0; i < wiersze; i++) 
    {
        for (int j = 0; j < kolumny; j++) 
        {
            printf("%4d ", macierz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int wiersze, kolumny;
    printf("Podaj liczbę wierszy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbę kolumn: ");
    scanf("%d", &kolumny);
    int **macierz = przydzielMacierz(wiersze, kolumny);
    wypelnijMacierz(macierz, wiersze, kolumny);
    wyswietlMacierz(macierz, wiersze, kolumny);
    zwolnijMacierz(macierz, wiersze);

    return 0;
}
