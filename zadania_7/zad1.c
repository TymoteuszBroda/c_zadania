#include <stdio.h>
#include <string.h>

int calculate(char *line) {
    int length = strlen(line);
    int firstVal, lastVal;
    for(int i = 0; i < length; i++) {
        if (line[i] >= '0' && line[i] <= '9'){
            firstVal = line[i] - '0';
            break;
        }
    }
    for(int i = length - 1; i >= 0; i--) {
        if(line[i] >= '0' && line[i] <= '9') {
            lastVal = line[i] - '0';
            break;
        }
    }
    int value = firstVal * 10 + lastVal;
    printf("Liczba: %d\n", value);
    return value;
}

int main() {
    int sum = 0;
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Nie można znaleźć pliku o podanej nazwie!\n");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        sum += calculate(line);
    }
    fclose(file);
    printf("Suma wszystkich wartości energetycznych: %d\n", sum);
    return 0;
}