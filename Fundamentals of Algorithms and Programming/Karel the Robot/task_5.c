#include <superkarel.h>

//fuction declaration
void naleva();
void naprava();
void stavvvv();
void idiii();
void nazad();



int main(){
    turn_on("task_5.kw");
    set_step_delay(207);

    while(front_is_clear()){
    step();}
    if(facing_north()){
    naleva();}
    if(facing_south()){
    naprava();}
    if(facing_east()){
    naprava();}

    stavvvv();
    naleva();
    stavvvv();
    naleva();
    stavvvv();
    naleva();
    stavvvv();
    naleva();
    idiii();
    naleva();
    idiii();
    nazad();

    turn_off();
    return 0;
}    

void naleva(){
    turn_left();}
void naprava(){
    naleva();
    turn_left();
    naleva();}
void stavvvv(){
    while(front_is_clear()){
   step();
   put_beeper();}
   }
void idiii(){
    step();
    step();
    step();}
void nazad(){
    naleva();
    naleva();}
