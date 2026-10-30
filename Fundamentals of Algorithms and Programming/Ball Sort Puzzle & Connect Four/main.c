#include "ballsortpuzzle.h"

int main(){

 /*   const int rows = 4;
    const int columns = 6;

    char field[rows][columns];
    
    printf("\n");
    printf("task_1\n");
    printf("\n");
    generator(rows, columns, field);
    printf("\n");
    printf("task_2\n");
    printf("\n");
 
    down_possible(rows, columns, field, 1, 2);
    down_possible(rows, columns, field, 3, 4);
    down_possible(rows, columns, field, 5, 6);
    printf("\n");
    printf("task_3\n");
    printf("\n");
    printf("Check: %s\n",check(rows, columns, field) ? "true" : "false");

       int rows = 4;
        int cols = columns;
        char board[rows][cols];
        initialize_board(rows, cols, board);*/
    int rows = 4;
    int columns = 6;
    char field[rows][columns];
    generator(rows, columns, field); 

return 0;
}
