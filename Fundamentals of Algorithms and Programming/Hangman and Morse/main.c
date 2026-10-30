#include "hangman.h"
#include<stdbool.h>
#include<time.h>

//int get_word(char secret[]);

int main(){

 //  char output[150];
 //  text_to_morse("Hello", output);
 //  puts(output);
     char secret[15]= "lender";
     get_word(secret);
   

   hangman(secret);

    

  //nover1  
 // int is_word_guessed(/*"secret", "aeiou"*/ const char secret[], const char letters_guessed[]);
//  printf("%d\n", is_word_guessed("hello", "aeihoul"));
  //nomer2
//  char result[30];
// void  get_guessed_word(/*"container", "arpstxgoieyu", result*/ const char secret[], const char lette
  //nomer3
 // char result[30];
// void get_available_letters(/*"arwnbxe", result*/ const char letters_guessed[], char available_letters[]);

// int get_word(char secret[]);
    
// srand(time(NULL));
 //   srand((unsigned int)time(NULL)/2);
// char secret[26];
// int error =  get_word(secret);
//if(error == 1) return error;

  return 0;
  }
