#include "save.h"
void save(int board[][SIZE]){
    FILE *f = fopen("saveOfGame.txt", "w");

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
           fprintf(f,"% d ",board[i][j]);

        }
        fprintf(f,"\n");
    }
    fclose(f);
}