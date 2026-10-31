#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <math.h>

#include "k.h"

//uloha 1
bool is_game_won(const struct game game) {
    int row;
    int col;
    for ( row = 0; row < 4; row+=1) {
        for (col = 0; col < 4; col+=1) {
            if (game.board[row][col] == 75) {
                return true;
            }
        }
    }
    return false;

}
//uloha 2
bool is_move_possible(const struct game game){
    int i;
    int j;
    for (i = 0; i < SIZE; i+=1) {
        for (j = 0; j < SIZE; j+=1) {
            if (game.board[i][j] == ' ') {
                return true;
            }
            if ((i - 1 >= 0 && game.board[i - 1][j] == game.board[i][j]) ||
                (i + 1 < 4 && game.board[i + 1][j] == game.board[i][j]) ||
                (j - 1 >= 0 && game.board[i][j - 1] == game.board[i][j]) ||
                (j + 1 < 4 && game.board[i][j + 1] == game.board[i][j])) {
                return true;
            }
        }
    }
    return false;
}
//uloha 3
bool update(struct game *game, int dy, int dx) {
    if((dy<-1 && dy>1) || (dx<-1 && dx>1))
    {
        return false;
    }
    char copy[SIZE][SIZE];
    for(int a=0; a<=SIZE-2; a++)
    {
        for(int b=0; b<=SIZE-2; b++)
        {
            copy[a][b]=game->board[a][b];
        }
    }
    switch(dy) {
        case 1:
            if(dx==0)
            {

                char pole[SIZE];
                for(int a=0; a<SIZE; a++)
                {
                    for(int b=0; b<SIZE; b++)
                    {
                        pole[b]=game->board[SIZE-1-b][a];
                    }
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int a=0; a<SIZE-1; a++)
                    {
                        if(pole[a]==pole[a+1] && pole[a]!=' ')
                        {
                            if(pole[a]=='A')
                            {
                                pole[a]='B';
                            }
                            else if(pole[a]=='B')
                            {
                                pole[a]='C';
                            }
                            else if(pole[a]=='C')
                            {
                                pole[a]='D';
                            }
                            else if(pole[a]=='D')
                            {
                                pole[a]='E';
                            }
                            else if(pole[a]=='E')
                            {
                                pole[a]='F';
                            }
                            else if(pole[a]=='F')
                            {
                                pole[a]='G';
                            }
                            else if(pole[a]=='G')
                            {
                                pole[a]='H';
                            }
                            else if(pole[a]=='H')
                            {
                                pole[a]='I';
                            }
                            else if(pole[a]=='I')
                            {
                                pole[a]='J';
                            }
                            else
                            {
                                pole[a]='K';
                            }
                            pole[a+1]=' ';
                            game->score = game->score + (int)pow(2.0, pole[a] - 64);
                        }
                    }
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int b=0; b<SIZE; b++)
                    {
                        game->board[SIZE-1-b][a]=pole[b];
                    }
                }
            }
            else
            {
                return false;
            }
            break;
        case 0:
            if(dx==1)
            {
                char pole[SIZE];
                for(int a=0; a<SIZE; a++)
                {
                    for(int b=0; b<SIZE; b++)
                    {
                        pole[b]=game->board[a][SIZE-1-b];
                    }
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int a=0; a<SIZE-1; a++)
                    {
                        if(pole[a]==pole[a+1] && pole[a]!=' ')
                        {
                            if(pole[a]=='A')
                            {
                                pole[a]='B';
                            }
                            else if(pole[a]=='B')
                            {
                                pole[a]='C';
                            }
                            else if(pole[a]=='C')
                            {
                                pole[a]='D';
                            }
                            else if(pole[a]=='D')
                            {
                                pole[a]='E';
                            }
                            else if(pole[a]=='E')
                            {
                                pole[a]='F';
                            }
                            else if(pole[a]=='F')
                            {
                                pole[a]='G';
                            }
                            else if(pole[a]=='G')
                            {
                                pole[a]='H';
                            }
                            else if(pole[a]=='H')
                            {
                                pole[a]='I';
                            }
                            else if(pole[a]=='I')
                            {
                                pole[a]='J';
                            }
                            else
                            {
                                pole[a]='K';
                            }
                            pole[a+1]=' ';
                            game->score = game->score + (int)pow(2.0, pole[a] - 64);
                        }
                    }
                    //usporiadaj(pole);
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int b=0; b<SIZE; b++)
                    {
                        game->board[a][SIZE-1-b]=pole[b];
                    }
                }
            }
            else if(dx==-1)
            {
                char pole[SIZE];
                for(int a=0; a<SIZE; a++)
                {
                    for(int b=0; b<SIZE; b++)
                    {
                        pole[b]=game->board[a][b];
                    }
                    //usporiadaj(pole);
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int a=0; a<SIZE-1; a++)
                    {
                        if(pole[a]==pole[a+1] && pole[a]!=' ')
                        {
                            if(pole[a]=='A')
                            {
                                pole[a]='B';
                            }
                            else if(pole[a]=='B')
                            {
                                pole[a]='C';
                            }
                            else if(pole[a]=='C')
                            {
                                pole[a]='D';
                            }
                            else if(pole[a]=='D')
                            {
                                pole[a]='E';
                            }
                            else if(pole[a]=='E')
                            {
                                pole[a]='F';
                            }
                            else if(pole[a]=='F')
                            {
                                pole[a]='G';
                            }
                            else if(pole[a]=='G')
                            {
                                pole[a]='H';
                            }
                            else if(pole[a]=='H')
                            {
                                pole[a]='I';
                            }
                            else if(pole[a]=='I')
                            {
                                pole[a]='J';
                            }
                            else
                            {
                                pole[a]='K';
                            }
                            pole[a+1]=' ';
                            game->score = game->score + (int)pow(2.0, pole[a] - 64);
                        }
                    }
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int b=0; b<SIZE; b++)
                    {
                        game->board[a][b]=pole[b];
                    }
                }
            }
            else
            {
                return false;
            }
            break;
        case -1:
            if(dx==0)
            {

                char pole[SIZE];
                for(int a=0; a<SIZE; a++)
                {
                    for(int b=0; b<SIZE; b++)
                    {
                        pole[b]=game->board[b][a];
                    }
                    //usporiadaj(pole);
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int a=0; a<SIZE-1; a++)
                    {
                        if(pole[a]==pole[a+1] && pole[a]!=' ')
                        {
                            if(pole[a]=='A')
                            {
                                pole[a]='B';
                            }
                            else if(pole[a]=='B')
                            {
                                pole[a]='C';
                            }
                            else if(pole[a]=='C')
                            {
                                pole[a]='D';
                            }
                            else if(pole[a]=='D')
                            {
                                pole[a]='E';
                            }
                            else if(pole[a]=='E')
                            {
                                pole[a]='F';
                            }
                            else if(pole[a]=='F')
                            {
                                pole[a]='G';
                            }
                            else if(pole[a]=='G')
                            {
                                pole[a]='H';
                            }
                            else if(pole[a]=='H')
                            {
                                pole[a]='I';
                            }
                            else if(pole[a]=='I')
                            {
                                pole[a]='J';
                            }
                            else
                            {
                                pole[a]='K';
                            }
                            pole[a+1]=' ';
                            game->score = game->score + (int)pow(2.0, pole[a] - 64);
                        }
                    }
                    //usporiadaj(pole);
                    for(int p=0; p<SIZE; p++)
                    {
                        for(int a=0; a<SIZE-1; a++)
                        {
                            if(pole[a]==' ')
                            {
                                for(int b=a; b<SIZE-1; b++)
                                {
                                    pole[b]=pole[b+1];
                                    pole[b+1]=' ';
                                }
                            }
                        }
                    }
                    for(int b=0; b<SIZE; b++)
                    {
                        game->board[b][a]=pole[b];
                    }
                }
            }
            else
            {
                return false;
            }
            break;
        default:
            break;
    }

    for(int a=0; a<=SIZE-2; a++)
    {
        for(int b=0; b<=SIZE-2; b++)
        {
            if(game->board[a][b]!=copy[a][b]){
                return true;
            }
        }
    }
    return false;
}


