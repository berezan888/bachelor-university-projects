#include <superkarel.h>

//function declaration
void naleva();
void naprava();

int main(){
    turn_on("task_7.kw");
    set_step_delay(189);

    naleva();
    step();
    step();
    put_beeper();
    while(!right_is_clear()){
    step();}
    if(right_is_clear()){
    naprava();}
    while(front_is_clear()){
    step();
}
    if(front_is_blocked()){
    naprava();}
    while(!front_is_blocked()){
    step();}
    if(right_is_blocked()){
    naleva();
    step();
    naprava();
    step();
    put_beeper();
    step();}


    naprava();
    step();
    if(right_is_clear()){
    naleva();
    naleva();
    while(front_is_clear()){
    step();}

    naleva();
    step();
    put_beeper();
    step();
    naleva();
    step();
    naleva();
    step();
    put_beeper();
    step();
    naprava();
    while(!front_is_blocked()){
    step();}
    }
    step();
    naleva();
    step();

    turn_off();
    return 0;
}

//function definicion

void naleva(){
    turn_left();
}
void naprava(){
    turn_left();
    turn_left();
    turn_left();
}    

