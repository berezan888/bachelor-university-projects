#include <stdio.h>
#include "c4.h"

//nomer zadania 6

    void initialize_board(int rows, int cols, char board[rows][cols]){
    //sama funkcia

        short fof = 0;
        for( ; fof < rows; ++fof){
          //  ++fof;
            short fif = 0;
            for( ; fif < cols; ++fif){
            //    ++fif;
                board[fof][fif] = '.';
            }    
        }}
    //vyvod i proverka

   /* for(short kik =0;kik < rows;++kik){
      
        printf("%d |", kik+1);
        for(short pip = 0; pip < cols;++pip){
          
            printf(" %c |", board[kik][pip]);
        } 
        if(kik < rows - 1){
            for(short pip = 0; pip<cols;++pip){
            
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("   ");
    for(short pip = 0;pip<cols;++pip){
    
    printf("--- ");
    }
    printf("\n");
    printf("    ");
    for(short pip =0; pip<cols;++pip){
      
        printf("%d   ", pip + 1);
    }
    printf("\n");
    }*/



    //nomer zadania 8
    int is_valid_move(int rows, int cols, const char board[rows][cols], int col){
        if(col<1 || col > cols){
            return 0;
        }//nekorekyny stlp

        for(int xlot = 0; xlot < rows; xlot++){
        if(board[xlot][col-1] == '.'){
            return 1;
        }//chod zapolnen
    }
    return 0;}

    //nomer zadania 9
    int drop_piece(int rows, int cols, char board[rows][cols], int col, char player_piece){
        if (col > cols || col<0){
            return 0;
        }
        for(int wiw = rows -1; wiw >= 0; --wiw){
            if(board[wiw][col-1] == '.'){
                board[wiw][col-1] = player_piece;
                    return wiw;
            }        
        }
        return 0;
    }    

    //nomer zadania 10
   int check_win(int rows, int cols, const char board[rows][cols], int row, int col, char player_piece){
    return 1;
    }
    //11
     int is_board_full(int rows, int cols, const char board[rows][cols]){
        return 1;
    }    
        







 /* int main(){
        int rows = 4;
        int cols = 6;
        int col = 2;
        int row=2;
        char player_piece = 2;
        char board[rows][cols];
        initialize_board(rows, cols, board);
        is_valid_move(rows, cols, board, col);
        drop_piece(rows, cols, board, col, player_piece);
        check_win( rows,  cols,  board, row,  col,  player_piece);
        is_board_full( rows,  cols, board);
  
        return 0;
    }  */ 




