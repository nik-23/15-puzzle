#include"game.h"
void moveNumber(int board[][SIZE], int number) {
    int emptyRow, emptyCol;
    getEmptyCell(board, &emptyRow, &emptyCol);


    if ((emptyRow > 0 && board[emptyRow - 1][emptyCol] == number) ||
        (emptyRow < SIZE - 1 && board[emptyRow + 1][emptyCol] == number) ||
        (emptyCol > 0 && board[emptyRow][emptyCol - 1] == number) ||
        (emptyCol < SIZE - 1 && board[emptyRow][emptyCol + 1] == number)) {

        board[emptyRow][emptyCol] = number;
        if (emptyRow > 0 && board[emptyRow - 1][emptyCol] == number) {
            board[emptyRow - 1][emptyCol] = 0;
        } else if (emptyRow < SIZE - 1 && board[emptyRow + 1][emptyCol] == number) {
            board[emptyRow + 1][emptyCol] = 0;
        } else if (emptyCol > 0 && board[emptyRow][emptyCol - 1] == number) {
            board[emptyRow][emptyCol - 1] = 0;
        } else if (emptyCol < SIZE - 1 && board[emptyRow][emptyCol + 1] == number) {
            board[emptyRow][emptyCol + 1] = 0;
        }
    } else {
        printf("Wrong move, try again!\n");
    }
}
void solveGame(int board[][SIZE]) {
    int number = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = number;
            number++;
        }
    }
    board[SIZE - 1][SIZE - 1] = 0;
}


int isGameOver(int board[][SIZE]) {
    int count = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != count % 16) {
                return 0;
            }
            count++;
        }
    }
    printf("You win!!!\n");
    return 1;
}


void getEmptyCell(int board[][SIZE], int* row, int* col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
