#include <Arduino.h>
#include "lcd_wrapper.h"
#include "mastermind.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

char* generate_code(bool repeat, int length){

    if(length < 1) return NULL;
    if(!repeat && length > 10) return NULL;

    char *code = (char*)calloc(length + 1, sizeof(char));

    bool used_cifry[10] = { false };
    for (int i = 0; i < length; i++) {
        int cifra;
        do {
            cifra = rand() % 10;
        } while (!repeat && used_cifry[cifra]);

        code[i] = '0' + cifra;
        used_cifry[cifra] = true;
    }

    code[length] = '\0';
    return code;
}

void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){
    *peg_a = 0;
    *peg_b = 0;
    char gg[10];

    strcpy(gg, guess);
    for (int i = 0; secret[i]; i+=1) {
        for (int j = 0; gg[j]; j +=1) {
            if (secret[i] == gg[j]) {
                *peg_b +=1;
                gg[j] = ' ';
                break;
            }
        }
        if (secret[i] == guess [i]) {
            *peg_a += 1;
            *peg_b -= 1;
        }
    }
}

void turn_off_leds() {
    for (int i = 6; i < 14; i++) {
        digitalWrite(i, LOW);
    }
}

void lights_greeting() {
    for (int i = 6; i < 14; i++){
        digitalWrite(i, HIGH);
        delay(150);
        turn_off_leds();
    }
    delay(200);
    for (int i = 6; i < 14; i++){
        digitalWrite(i, HIGH);
        delay(150);
        turn_off_leds();
    }
    delay(200);
    for (int i = 6; i < 14; i++){
        digitalWrite(i, HIGH);
        delay(150);
        turn_off_leds();
    }
    delay(200);
    for(int i = LED_BLUE_1; i <= LED_BLUE_4; i+=2) {
        digitalWrite(i, HIGH);
    }
    delay(500);
    turn_off_leds();
    delay(200);
    for(int i = LED_RED_1; i <= LED_RED_4; i+=2) {
        digitalWrite(i, HIGH);
    }
    delay(500);
    turn_off_leds();
    delay(200);
}

char change_number(char symbol) {

    if (symbol < '0' || symbol > '9') return symbol;

    if (symbol == '9') return '0';
    else{
        return symbol + 1;
    }
}

void render_leds(const int peg_a, const int peg_b) {
    int blue_led = LED_BLUE_1;
    for(int i = 0; i < peg_a; i++) {
        digitalWrite(blue_led, HIGH);
        blue_led += 2;
    }

    int red_led = LED_RED_1;
    for(int i = 0; i < peg_b; i++) {
        digitalWrite(red_led, HIGH);
        red_led += 2;
    }
}

void render_history(char* secret, char** history, const int entry){
    int a,b;
    lcd_set_cursor(10, 1);
    lcd_num(entry + 1);
    lcd_print((char *) ":");
    get_score(secret, history[entry], &a, &b);
    lcd_num(a);
    lcd_print((char *) "A");
    lcd_num(b);
    lcd_print((char *) "B");
    turn_off_leds();
    render_leds(a, b);
}

void play_game(char* secret){
    lights_greeting();
    lcd_clear();

    lcd_print_at(2, 0, "Welcome to ");
    lcd_print_at(2, 1, "MasterMind ");

    delay(2000);
    lcd_clear();


    int guesses = 0;
    int delay_time = 250;
    char gues[5] = "0000";
    char **history = (char **) calloc(10, sizeof(char *));
    for(int i = 0; i < 10; i++) {
        history[i] = (char *) calloc(5, sizeof(char));
    }



    while(guesses < 10) {
        int led_a = 0;
        int led_b = 0;
        char guess[] = "0000";
        int history_position = guesses - 1;

        if(guesses > 0) {
            render_history(secret, history, history_position);
        }

        lcd_set_cursor(0, 0);
        lcd_print("Your guess: ");
        lcd_print_at(12, 0, guess);

        while(analogRead(BTN_ENTER_PIN) < 1000) {
            if(digitalRead(BTN_1_PIN) == HIGH) {
                unsigned long pressed_time = millis();
                while(digitalRead(BTN_1_PIN) == HIGH) {
                    if(guesses == 0) {
                        break;
                    }
                    if (digitalRead(BTN_2_PIN) == HIGH) {
                        if (history_position > 0) {
                            history_position -= 1;
                        }
                        render_history(secret, history, history_position);
                        delay(200);
                    } else if (digitalRead(BTN_3_PIN) == HIGH) {
                        if (history_position != guesses - 1) {
                            history_position += 1;
                        }
                        render_history(secret, history, history_position);
                        delay(200);
                    }
                }
                unsigned long released_time = millis();
                if((released_time - pressed_time) < delay_time) {
                    guess[0] = change_number(guess[0]);
                    lcd_print_at(12, 0, guess);
                    delay(delay_time);
                }
            } else if(digitalRead(BTN_2_PIN) == HIGH) {
                guess[1] = change_number(guess[1]);
                lcd_print_at(12, 0, guess);
                delay(delay_time);
            } else if(digitalRead(BTN_3_PIN) == HIGH) {
                guess[2] = change_number(guess[2]);
                lcd_print_at(12, 0, guess);
                delay(delay_time);
            } else if(digitalRead(BTN_4_PIN) == HIGH) {
                guess[3] = change_number(guess[3]);
                lcd_print_at(12, 0, guess);
                delay(delay_time);
            }
        }

        delay(delay_time);
        get_score(secret, guess, &led_a, &led_b);

        if(led_a == 4) {

            lcd_clear();
            lcd_print_at(0, 0, "Winner Winner");
            lcd_print_at(2, 1, "Winner Winner");

            for(int i = LED_BLUE_1; i <= LED_RED_4; i++) {
                digitalWrite(i, HIGH);
            }

            delay(5000);
            turn_off_leds();
            lcd_clear();

            break;
        } else {
            guesses += 1;
            strcpy(history[guesses - 1], guess);
            lcd_clear();
            lcd_print_at(0, 0, "Your guess: ");
            lcd_print_at(12, 0, guess);
            char result[16];
            sprintf(result, "%02d: %s %dA%dB", guesses, guess, led_a, led_b);
            lcd_print_at(0, 1, result);

            delay(2000);
            lcd_clear();
            turn_off_leds();
            render_leds(led_a, led_b);
        }
    }

    if(guesses == 10) {

        lcd_clear();
        lcd_print_at(0, 0, "You lost :(");
        lcd_print_at(0, 1, "Try one more");

        delay(5000);
        lcd_clear();
    }

    for(int i = 0; i < 10; i++) {
        free(history[i]);
    }
    free(history);
}