#include  "create_and_shake.h"
void printBoard(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("+---------------+\n");
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("   |");
            } else {

                printf("%3d|", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("+---------------+\n");
}
void fillBoard(int board[][SIZE]) {
    int number = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = number;
            number++;
        }
    }
    board[SIZE - 1][SIZE - 1] = 0;
}
void shakeBoard(int board[][SIZE]) {
    srand(time(NULL));
    int numbers[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        numbers[i] = i + 1;
    }

    int emptyRow = SIZE - 1;
    int emptyCol = SIZE - 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == emptyRow && j == emptyCol) {
                board[i][j] = 0;
            } else {
                int t =SIZE * SIZE - 1- i * SIZE - j;
                int randomIndex = rand() % (t);
                int number = numbers[randomIndex];
                board[i][j] = number;
                numbers[randomIndex] = numbers[SIZE * SIZE - 2 - i * SIZE - j];
            }
        }
    }
}