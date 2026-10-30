#include <superkarel.h>

//function declaration
void levo();
void pravo();
void idi();
void padaj();
void nazad();
void jump();
void jump_1_2();
void idi_2();
void podnymajsa();
void podnymajsa_2();
void padaj_2();
void jump_2();

int main(){
    turn_on("task_1.kw");
    set_step_delay(244);

    levo();
    if(beepers_present()){
    pick_beeper();}

    


    
    idi();
    if(beepers_present()){
    pick_beeper();}
    padaj();
    if(beepers_present()){
    pick_beeper();}

    jump();
    if(beepers_present()){
    pick_beeper();}
    padaj();
    if(beepers_present()){
    pick_beeper();}
  
    while(facing_east()){
        step();
        if(right_is_clear()){
        pravo();
        }
} if(beepers_present()){
    pick_beeper();}
    while(!front_is_blocked()){
        step();
        if(beepers_present()){
        pick_beeper();}
}    
    nazad();
    podnymajsa();
        if(beepers_present()){
        pick_beeper();}
    jump_1_2();
        if(beepers_present()){
        pick_beeper();}
    padaj_2();
        if(beepers_present()){
        pick_beeper();
        }  
    jump_2();
    padaj_2();
    while(facing_west()){
    step();
    if(left_is_clear()){
    levo();
    }
}
    padaj_2();
    jump_2();
    padaj_2();

    while(facing_west()){
        step();
        if(left_is_clear()){
        levo();
        }
}
    while(!front_is_blocked()){
        step();
        if(front_is_blocked()){
        pravo();
        }
}        

    turn_off();
    return 0;
}        
    
//function definition
void levo(){
    turn_left();
}    
void pravo(){
    turn_left();
    turn_left();
    turn_left();
}    
void nazad(){
    levo();
    levo();
}    
void podnymajsa(){
    while(right_is_blocked()){
            step();
            if(beepers_present()){
            pick_beeper();}
            }
}            
void jump(){
    step();
    pravo();
    if(front_is_clear()){
    step();
    }if(beepers_present()){
    pick_beeper();}

}    
void jump_1_2(){
    pravo();
    step();
    pravo();
    if(beepers_present()){
    pick_beeper();}
}    
void idi(){
    while(right_is_blocked()){ 
            step();
            if(beepers_present()){
            pick_beeper();}
            }

    if(right_is_clear()){
            pravo();
            step();
            if(beepers_present()){
            pick_beeper();}
            } 
    while(right_is_blocked()){
            step();
            if(beepers_present()){
            pick_beeper();}
            }

    if(right_is_clear()){
            pravo();
            step();
            if(beepers_present()){
            pick_beeper();}
            }
    
}    
void padaj(){
    while(!front_is_blocked()){
            step();
            if(beepers_present()){
            pick_beeper();}
            }
    if(front_is_blocked()){
            nazad();
            podnymajsa();
            if(beepers_present()){
            pick_beeper();}
    }       
    if(right_is_clear()){
            pravo();
       }        
}
void idi_2(){
    while(left_is_blocked()){
            step();
            }
    if(left_is_clear()){
            levo();
            step();
            }
    while(left_is_blocked()){
            step();
            }
    if(left_is_clear()){
            levo();
            step();
            }
}            
void podnymajsa_2(){
    while(left_is_blocked()){
    step();
    }if(beepers_present()){
    pick_beeper();}
}    
void padaj_2(){
    while(!front_is_blocked()){
    step();
        if(beepers_present()){
    pick_beeper();}
    }
    if(front_is_blocked()){
    nazad();
    podnymajsa_2();
        if(beepers_present()){
        pick_beeper();}
    }
    if(left_is_clear()){
    levo();
    }
}        
void jump_2(){
    step();
    levo();
    step();
    if(beepers_present()){
    pick_beeper();}
}    








