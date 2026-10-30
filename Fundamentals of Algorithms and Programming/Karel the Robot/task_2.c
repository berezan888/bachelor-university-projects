#include <superkarel.h>

//function decleration
void na_leva();
void na_prava();
void idi();
void obratno_idi();
void nazad();

int main(){
    turn_on("task_2.kw");
    set_step_delay(204);

    idi();
    if(left_is_clear()){
    na_leva();}
    if(right_is_clear()){
    na_prava();}
    if(front_is_blocked()){
    nazad();}
    obratno_idi();

    turn_off();
    return 0;
}

//function definition
void na_leva(){
    turn_left();
}
void idi(){
    while(!front_is_blocked()){
        step();
        if(beepers_present()){
        pick_beeper();}
        }
        if(front_is_blocked()){
        na_leva();
        }
      while(!beepers_in_bag()){
      idi();} 
        if(beepers_in_bag()){
        na_leva();}
}
void na_prava(){
    turn_left();
    turn_left();
    turn_left();
} 
void obratno_idi(){
    while(!front_is_blocked()){
    step();}
    if(front_is_blocked()){
    na_prava();
    }
    while(!front_is_blocked()){
    obratno_idi();
    }
}    
void nazad(){
    na_leva();
    na_leva();}






