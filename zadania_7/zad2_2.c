#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void findDiceMinimum(const char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Nie można otworzyć pliku");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int gameId = 0;
    unsigned long sum = 0;

    while (fgets(line, sizeof(line), file)) {
        gameId++;

        int minRed = INT_MAX, minGreen = INT_MAX, minBlue = INT_MAX;
        char *token = strtok(line, ";");

        while (token != NULL) {
            int red = 0, green = 0, blue = 0;
            sscanf(token, " %*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &green, &blue, &red);
            if (red > 0 && red < minRed) minRed = red;
            if (green > 0 && green < minGreen) minGreen = green;
            if (blue > 0 && blue < minBlue) minBlue = blue;
            token = strtok(NULL, ";");
        }

        unsigned long moc = minRed * minGreen * minBlue;
        sum += moc;
        printf("Gra %d: minRed=%d, minGreen=%d, minBlue=%d, moc=%lu\n", gameId, minRed, minGreen, minBlue, moc);
    }

    fclose(file);
    printf("Suma mocy: %lu\n", sum);
}

int main() {
    const char* fileName = "input2.txt";
    findDiceMinimum(fileName);
    return 0;
}