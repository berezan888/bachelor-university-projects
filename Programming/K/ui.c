#include <stdio.h>
#include <string.h>

#include "k.h"

void render(const struct game game){
    printf("score: %d\n", game.score);
    int row;
    int col;
    for(row = 0; row < SIZE; row=row+1){
        printf("+...+---+...+---+\n|");
        for(col = 0; col < SIZE; col=col+1){
            printf(" %c |", game.board[row][col]);
        }
        printf("\n");
    }
    printf("+...+---+...+---+\n");
}