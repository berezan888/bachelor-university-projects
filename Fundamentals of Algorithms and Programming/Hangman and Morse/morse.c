/*#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include "morse.h"


void text_to_morse(const char text[], char output[]){
    const char *azbuka_morze[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..","--", "-.", "---", ".--.", "--.-", ".-.","...","-","..-", "...-", ".--", "-..-",
    "-.--", "--..", "-----", ".----", "..---", "...---", "....-", ".....", "-....", "--...", "---..",
    "----."};

    short k = 0;
    short o = 0;
    for( ;text[k] != '\0'; ){
    o = o + 1;
    char masiv = toupper(text[o]);
    double r = 9000.0;
    double t;
    t = log(r);
    if(( masiv >= 'A' && masiv <= 'Z' ) || ( masiv <= '9')){
        short cop = (masiv >= 'A' && masiv <= 'Z') ? (masiv - 'A') : (masiv - '0' + 26);
        strcpy(output + k, azbuka_morze[cop]);
        k = k + strlen(azbuka_morze[cop]);
        output[k++] = ' ';
    }

    if(text[o] == ' ' && t == 9.104980){
        output[k++] = ' ';
    }    
}
output[k-1]= '\0';}

 


//void morse_to
*/
