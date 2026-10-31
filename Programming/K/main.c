#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "k.h"
#include "ui.h"
#include "hof.h"

int main(){
    // true 1, false 2
    //uloha 1
    printf("=================================================\n");
    struct game game = {
            .board = {
                    {'A', 'B', 'C', 'D'},
                    {'W', 'F', 'G', 'H'},
                    {'I', 'K', 'Y', 'A'},
                    {'B', 'L', 'U', 'E'}
            },
            .score = 0
    };

    printf("is won: %d\n", is_game_won(game));
    /*struct game game = {
            .board = {
                    {'A', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', 'A'},
                    {'B', ' ', ' ', ' '}
            },
            .score = 0
    };

    printf("is won: %d\n", is_game_won(game));*/
    //uloha 2
    printf("=================================================\n");
    printf("is move possible: %d\n", is_move_possible(game));
    //uloha 3
    printf("=================================================\n");
    //bool result = update(&game, 1, 1);
    /*struct game game1 = {
            .board = {
                    {'A', ' ', 'A', 'A'},
                    {'B', 'B', 'B', 'B'},
                    {'C', 'C', 'C', 'C'},
                    {'D', 'D', 'D', 'D'}
            },
            .score = 0
    };*/
    struct game game1 = {
            .board = {
                    {'A', ' ', ' ', ' '},
                    {'B', ' ', ' ', 'B'},
                    {'C', 'C', 'C', ' '},
                    {'D', 'D', 'D', 'D'}
            },
            .score = 0
    };

   // bool result = update(&game, 0, 1);//

    bool result1 = update(&game1, 0, 1);
    printf("Result: %d -> 1\n", result1);
    printf("Score: %d -> 88\n", game1.score);
    //poslednyaya
    printf("=================================================\n");
    render(game);
    printf("=================================================\n");
    struct player list[10];
    struct player player= {.name = "Matt", .score=1234};
    int size = load(list);
    save(list, size);
    add_player(list, &size, player);
    return 0;
}