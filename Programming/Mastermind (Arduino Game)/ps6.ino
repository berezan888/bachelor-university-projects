#include "lcd_wrapper.h"
#include "mastermind.h"
#include <time.h>

void setup() {
    srand(time(NULL));
    lcd_init();
}

void loop() {
    char* code = generate_code(false, 4);
    play_game(code);
    free(code);
}