#include <superkarel.h>

//function declaration
void na_levo();
void na_pravo();
void idii();
void povorot();
void uborka();
void povorot_1();
void povorot_2();
void stav();

int main(){
    turn_on("task_3.kw");
    set_step_delay(206);

    if(facing_north()){
    na_pravo();}
    if(facing_south()){
    na_levo();}
    if(facing_west()){
    na_levo();
    na_levo();}
    idii();
        if(!front_is_clear()){
        na_pravo();
        idii();}
    if(front_is_blocked()){
    na_pravo();
    na_pravo();
    step();
    na_levo();}

    idii();
    if(front_is_blocked()){
    na_pravo();
    step();
    na_pravo();}
    idii();
    povorot_2();
    idii();
    povorot_1();
    idii();
    povorot_2();

    if(right_is_blocked()){
    idii();
    if(front_is_blocked()){
    na_levo();
    na_levo();}
    }
    else{
    idii();
    povorot_1();
    idii();
    if(front_is_blocked()){
    na_levo();
    na_levo();
    idii();
    if(front_is_blocked()){
    na_levo();
    na_levo();}}
    }
    while(front_is_clear()){
    step();}
    
    
    if(left_is_clear()){
    na_levo();
    na_levo();
    step();
    na_levo();
}
    na_pravo();

    put_beeper();

    step();
    put_beeper();

    step();
    put_beeper();

    step();
    put_beeper();

    step();
    put_beeper();

    na_pravo();
    step();
    step();
    na_pravo();
    step();

    stav();
    put_beeper();
    na_levo();
    step();
    na_levo();

    put_beeper();
    
    step();
    put_beeper();
    step();
    put_beeper();
   
    na_pravo();
    step();
    na_pravo();
    step();
    stav();
    put_beeper();
    na_levo();
    step();
    step();
    na_levo();

    put_beeper();

    step();
    put_beeper();

    na_pravo();
    step();
    step();
    na_pravo();
    step();
    na_pravo();

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
void idii(){
    if(beepers_present()){
    pick_beeper();
    }
    else{step();}
    if(beepers_present()){
    pick_beeper();
    }
    while(front_is_clear()){
    idii();
    }
}
void povorot(){
    if(facing_east()){
    na_pravo();
    step();
    if(beepers_present()){
    pick_beeper();}
    na_pravo();
    step();
    if(beepers_present()){
    pick_beeper();}
    }
    else{
    na_levo();
    step();
    if(beepers_present()){
    pick_beeper();}
    na_levo();
    step();
    if(beepers_present()){
    pick_beeper();}}
    }
void uborka(){
    idii();
    povorot();
    }
void povorot_1(){
    if(front_is_blocked()){
    na_pravo();
    step();
    na_pravo();}
    }
void povorot_2(){
    if(front_is_blocked()){
    na_levo();
    step();
    na_levo();}
    }
void stav(){
    while(!front_is_blocked()){
    put_beeper();
    step();}
}    


    




