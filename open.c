#include"open.h"

void open(int board[SIZE][SIZE]){
FILE *file = fopen("saveOfGame.txt", "r");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (fscanf(file, "%d", &board[i][j]) != 1) {
                printf("Error reading from the file.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}