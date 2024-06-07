#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int red;
    int green;
    int blue;
} DiceSet;

bool gamePossible(DiceSet game[], int gameLength, int maxRed, int maxGreen, int maxBlue) {
    for (int i = 0; i < gameLength; i++) {
        if (game[i].red > maxRed || game[i].green > maxGreen || game[i].blue > maxBlue) {
            return false;
        }
    }
    return true;
}
int main() {
    int maxRed = 12, maxGreen = 13, maxBlue = 14;

    DiceSet gry[][10] = {
            {{3, 0, 4}, {1, 2, 6}, {0, 2, 0}},
            {{1, 2, 0}, {1, 3, 4}, {1, 1, 1}},
            {{20, 13, 6}, {4, 13, 5}, {1, 5, 0}},
            {{14, 3, 6}, {6, 3, 6}, {15, 3, 3}},
            {{1, 6, 1}, {1, 2, 2}}
    };

    int gameLength[] = {3, 3, 3, 3, 2};
    int numberOfGames = sizeof(gameLength) / sizeof(gameLength[0]);
    int gameId = 0;

    for (int i = 0; i < numberOfGames; i++) {
        if (gamePossible(gry[i], gameLength[i], maxRed, maxGreen, maxBlue)) {
            gameId += i + 1;
        }
    }
    printf("Suma ID gier: %d\n", gameId);

    return 0;
}
