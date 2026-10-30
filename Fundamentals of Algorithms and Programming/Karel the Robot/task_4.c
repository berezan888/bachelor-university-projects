#include <superkarel.h>

//function declaration
void na_levo();
void na_pravo();
void stroj();
void nazad();

int main(){
    turn_on("task_4.kw");
    set_step_delay(205);

    na_levo();
    stroj();
        if(!front_is_clear()){
        na_pravo();
        step();}
        while(left_is_clear()){
        step();
        }
        if(!left_is_clear()){
        na_pravo();
        }
    stroj();
        if(!beepers_present()){
        put_beeper();}
        nazad();
        while(front_is_clear()){
        step();}
        if(!front_is_clear()){
        na_pravo();
        step();}
        while(left_is_clear()){
        step();
        }
        if(!left_is_clear()){
        na_pravo();
        }
    stroj();
        if(!beepers_present()){
        put_beeper();}
        nazad();
        while(!front_is_blocked()){
        step();}
        if(front_is_blocked()){
        na_pravo();
        step();}
        while(!front_is_blocked()){
        step();}
        if(front_is_blocked()){
        na_pravo();
        }
    stroj();    
        if(!beepers_present()){
        put_beeper();}
        nazad();
    stroj();
        if(!beepers_present()){
        put_beeper();
        }
        nazad();
    while(front_is_clear()){
        step();}
        if(!front_is_clear()){
        na_levo();}
        


    turn_off();
    return 0;
}    

//function definicion
void na_levo(){
    turn_left();
}
void na_pravo(){
    turn_left();
    turn_left();
    turn_left();
}
void stroj(){
    if(!beepers_present()){
    put_beeper();
    step();
    }
    else{step();}
    while(front_is_clear()){
    stroj();
    }
}    
void nazad(){
    na_levo();
    na_levo();
    }

