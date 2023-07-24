#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include"time.h"
#include"create_and_shake.h"
#ifndef GAME_H
#define GAME_H
#define SIZE 4
void moveNumber(int board[][SIZE], int number) ;// Пример объявления функции
void solveGame(int board[][SIZE]);
void getEmptyCell(int board[][SIZE], int* row, int* col);
int isGameOver(int board[][SIZE]);
#endif