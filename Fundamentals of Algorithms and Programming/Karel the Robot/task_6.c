#include <superkarel.h>

//function declaration

void hody();
void pova_na_leva();
void pova_na_prava();
void vozzzmyyy();

int main(){
    turn_on("task_6.kw");
    set_step_delay(197);

    hody();    
    pick_beeper();
    pick_beeper();
    pick_beeper();
    pova_na_prava();
    step();
    while(!beepers_present()){
    step();}
    if(beepers_present()){
    pick_beeper();}
    pick_beeper();
    pick_beeper();
    
    pova_na_prava();
    hody();
    pick_beeper();

    pova_na_prava();
    hody();

    pova_na_prava();
    hody();
    vozzzmyyy();

    pova_na_leva();
    hody();
    vozzzmyyy();
    vozzzmyyy();

    pova_na_leva();
    hody();
    vozzzmyyy();
    vozzzmyyy();
    vozzzmyyy();


    pova_na_leva();
    hody();
    pova_na_leva();
    hody();
    vozzzmyyy();
    vozzzmyyy();
    vozzzmyyy();
    pova_na_prava();
    hody();
    pick_beeper();
    pick_beeper();

    pova_na_prava();
    hody();
    vozzzmyyy();
    pova_na_prava();
    hody();
    pova_na_prava();
    hody();
    pick_beeper();
    pick_beeper();
    vozzzmyyy();

    pova_na_prava();
    hody();
    vozzzmyyy();
    vozzzmyyy();

    pova_na_prava();
    hody();
    vozzzmyyy();
    vozzzmyyy();
    vozzzmyyy();
    pova_na_leva();
    hody();
    pova_na_leva();
    hody();
    vozzzmyyy();
    pova_na_leva();

    hody();
    vozzzmyyy();
    vozzzmyyy();
    vozzzmyyy();
    vozzzmyyy();

    turn_off();
    return 0;
}    

//function definicion
void pova_na_leva(){
    turn_left();
}    
void pova_na_prava(){
    turn_left();
    turn_left();
    turn_left();
}
void hody(){
    while(!beepers_present()){
    step();}
    if(beepers_present()){
    pick_beeper();}
 }
 void vozzzmyyy(){
    pick_beeper();}
