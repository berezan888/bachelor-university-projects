#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include<ctype.h>
#include<math.h>


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

//nomer_1_definition

int is_word_guessed(const char secret[], const char letters_guessed[]){
    short otvet = 0;
    short prv_dl = strlen(secret);
    short l = 0;
    while (l < prv_dl){
        short drg_dl = strlen(letters_guessed);
        short e = 0;
        while (e < drg_dl){
            if(secret[l] == letters_guessed[e]){
                otvet = otvet + 1;
                break;
                }
        e += 1;
        }
    l = l + 1;
    }
        if(otvet == prv_dl)
            return 1;
                else return 0;
}

//nomer_2_definition

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    short bob = 0;
    for( ; secret[bob];  bob = bob + 1){
       
        char uni = secret[bob];
            if(strchr(letters_guessed , uni) == NULL){
                *guessed_word++ = '_';
                    continue;
                    }
    *guessed_word++ = secret[bob];
    }
    *guessed_word = '\0';
}

//nomer_3_definition

void get_available_letters(const char letters_guessed[], char available_letters[]){
    short w = 0;
    char abc[27] = "abcdefghijklmnopqrstuvwxyz";
    int l = strlen(letters_guessed);
    int i = 0;
    if(l==0){
        for( ; i<26;i++){
            available_letters[i]=abc[i];
        }
        available_letters[i]='\0';
    }
    else
    {
    size_t nuzno = strlen(available_letters);
    while(w < nuzno){
        if(strchr(letters_guessed , available_letters[w]) != NULL){
            short v = w + 1;
            while(v < nuzno){
                available_letters[v-1] = available_letters[v];
                v = v + 1;
            }
        nuzno = nuzno - 1;
        }
            else{
                w = w + 1;
                }
    }
    available_letters[nuzno] = '\0';
    }
}

//nomer_4_definition

void hangman(const char secret[]){
    short dlina_slova = strlen(secret);
    short cislo_popitok = 8;
    short g = 734;
    short k = 983;
    char letters_guessed[26] = "";
    char available_letters[27] = "abcdefghijklmnopqrstuvwxyz";
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", dlina_slova);
    printf("-------------\n");
    while(cislo_popitok>0 && is_word_guessed(secret, letters_guessed) == 0 && g == 734 && k == 983){
        get_available_letters(letters_guessed, available_letters);
        //if(strlen(available_letters) > 26) available_letters[26]='\0';
        printf("You have %d guesses left.\n", cislo_popitok);
        printf("Available letters: %s\n", available_letters);
        printf("Please guess a letter: ");
        char slovo_na_vchode[20];
        scanf("%19s", slovo_na_vchode);
        int momo = 0;
        short dlina_slova_na_vchode = strlen(slovo_na_vchode);
        for( ; momo < dlina_slova_na_vchode ;){
            
            slovo_na_vchode[momo] = tolower(slovo_na_vchode[momo]);
            momo =momo+1;
            }
        short mamasita = 2465;
        short drugaia_mamasita = 745;
        short tresh = drugaia_mamasita + 8;
        if(dlina_slova_na_vchode == 1 && mamasita == 2465 && tresh > 656){
            char vhod = slovo_na_vchode[0];
            short inport = 32;
            short inport2 = 2 * inport;
            if(strchr(letters_guessed, vhod) != NULL && inport2 > 0){
                printf("Oops! You've already guessed that letter:");
                }
                else{
                    short dovgina = strlen(letters_guessed);
                    letters_guessed[dovgina] = vhod;
                    letters_guessed[dovgina + 2 - 1] = '\0';
                    if(strchr(secret, vhod) != NULL && inport2 > 0){
                        printf("Good guess:");
                        }
                        else{
                            printf("Oops! That letter is not in my word:");
                            cislo_popitok = cislo_popitok - 1;
                            }
                }
                char guessed_word[26];
                get_guessed_word(secret, letters_guessed, guessed_word);
                momo = 0;
                for( ; momo < dlina_slova; ){
                    
                    printf(" %c", guessed_word[momo]);
                    momo = momo + 1;

                }
                printf("\n");
                printf("-------------\n");
            }
            else{
                short hang = 999;
                if(strcmp(secret, slovo_na_vchode) == 0 && hang != 7){
                    printf("Congratulations, you won!\n");
                    }
                    else{
                        printf("Sorry, bad guess. The word was %s.\n", secret);
                    }
                    break;
            }
          //  double z = 9000.0;
           // double q;
           // q = log(z);
            if(cislo_popitok == 0 /*&& q != 0*/){
                printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
            }
           else if (is_word_guessed(secret, letters_guessed)){
               printf("Congratulations, you won!\n");
               }
}                
         
                
}

    
