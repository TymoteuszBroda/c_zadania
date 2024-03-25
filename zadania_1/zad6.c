#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define possible moves
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define GAMES_LIMIT 100 

// array to strore moves and games
int playerMoves[GAMES_LIMIT];
int computerMoves[GAMES_LIMIT];
int results[GAMES_LIMIT];
int gameCount = 0;

void printMove(int move) {
    if (move == ROCK) {
        printf("Kamień\n");
    } else if (move == PAPER) {
        printf("Papier\n");
    } else if (move == SCISSORS) {
        printf("Nożyce\n");
    } else {
        printf("Nieznany ruch\n");
    }
}

void playGame() {
    if (gameCount == GAMES_LIMIT) {
        printf("Osiągnięto limit gier.\n");
        return;
    }
    
    printf("Wybierz: 0 - kamień, 1 - papier, 2 - nożyce: ");
    int player;
    scanf("%d", &player);
    if (player < 0 || player > 2) {
        printf("Nieprawidłowy wybór.\n");
        return;
    }

    int bot = rand() % 3;
    printf("Twój wybór: ");
    printMove(player);
    printf("\nWybór komputera: ");
    printMove(bot);
    printf("\n");

    playerMoves[gameCount] = player;
    computerMoves[gameCount] = bot;

    // game logic here
    if (player == bot) {
        printf("Remis!\n");
        results[gameCount] = 0;
    } else if ((player == ROCK && bot == SCISSORS) || 
               (player == PAPER && bot == ROCK) || 
               (player == SCISSORS && bot == PAPER)) {
        printf("Wygrałeś!\n");
        results[gameCount] = 1;
    } else {
        printf("Przegrałeś!\n");
        results[gameCount] = -1;
    }

    gameCount++;
}

void showScores() {
    printf("Wyniki (%d gier):\n", gameCount);
    for (int i = 0; i < gameCount; i++) {
        printf("Gra %d: Twój ruch: ", i+1);
        printMove(playerMoves[i]);
        printf(", Ruch komputera: ");
        printMove(computerMoves[i]);
        printf(", Wynik: ");
        if (results[i] == 1) {
            printf("Wygrana\n");
        } else if (results[i] == 0) {
            printf("Remis\n");
        } else {
            printf("Przegrana\n");
        }
    }
}

int main() {
    srand(time(NULL));
    while (1) {
        printf("1. Graj\n2. Pokaż wyniki\n3. Wyjście\nWybór: ");
        int choice;
        scanf("%d", &choice);   
        if (choice == 1) {
            playGame();
        } else if (choice == 2) {
            showScores();
        } else if (choice == 3) {
            return 0;
        } else {
            printf("Nieznany wybór. Spróbuj ponownie.\n");
        }
    }
    return 0;
}