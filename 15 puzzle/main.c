#include <stdio.h>
#include <stdlib.h>
#include "create_and_shake.h"
#include "game.h"
#include "save.h"
#include <string.h>
#include "open.h"
int menu(){

    char input[100];
    int number;
    system ("clear");
    printf("Choose option:");
    printf("\n1.Game\n");
    printf("\n2.Rules\n");
    printf("\n3.Cheat code\n");
    printf("\n4.Continue\n");
    printf("\nEnter menu item number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &number) != 1) {
        return 1;
    }


    return number;
}

int main() {
    int n;


    n = menu();
int f = 0;
    while (n != -1) {

        if(n == 4){

         n = 1;
         f = 1;
        }
        switch (n) {
            case 0:
                n = menu();
                continue;

            case 1:
                n;
                int move_number = 0;
                int board[SIZE][SIZE] ;
                if (f == 1) {
                    open(board);
                }
                else {
                    fillBoard(board);
                    shakeBoard(board);
                }
                time_t startTime = time(NULL);

                while (!isGameOver(board)) {
                    system("clear");
                    printBoard(board);
                    char input[20];
                    move_number++;
                    printf("Move: %d \n", move_number);
                    printf("Enter number to move (0 for exit): ");
                    scanf("%11s", input);

                    if (strcmp(input, "0") == 0) {
                        printf("GaMe oVeR!\n");
                        break;
                    }
                    if (strcmp(input, "save") == 0) {
                        save(board);
                      break;
                    }
                    if (strcmp(input, "iwanttowin") == 0) {
                        solveGame(board);
                        printBoard(board);
                        continue;
                    }



                    int isNumber = 1;
                    for (int i = 0; i < strlen(input); i++) {
                        if (!isdigit(input[i])) {
                            isNumber = 0;
                            break;
                        }
                    }

                    if (isNumber == 0) {
                        printf("Wrong move, try again!\n");
                        continue;
                    }

                    int move = atoi(input);

                    if (move == 0) {
                        printf("GaMe oVeR\n");
                        return 1;
                    }

                    moveNumber(board, move);
                }

                time_t endTime = time(NULL);
                int totalTime = (int) (endTime - startTime);
                printf("sec needed: %d\n", totalTime);
                printf("Moves needed %d", move_number);
                return 1;


            case 2:
                system("clear");
                printf("There are 15 chips numbered from 1 to 15 on a 4*4 square field. There is one\n"
                       "free position Arrange the chips in ascending\n"
                       " order of their numbers horizontally.\n"
                       "You can move chips only to the adjacent free position.\n"
                       "if you want to save your progress put save to command line!\n");
                printf("Enter 1, if you want to play game, 0 if you want to go back to the menu: ");
                scanf("%d", &n);
                while ((getchar()) != '\n');
                break;

            case 3:
                system("clear");
                printf("iwanttowin\n");
                printf("Enter 1, if you want to play game, 0 if you want to go back to the menu: ");
                scanf("%d", &n);
                while ((getchar()) != '\n');
                continue;

            default:
                printf("\nPlease enter a valid menu item number.\n");
                system ("clear");
                n = menu();



        }



    }


    return 0;
}