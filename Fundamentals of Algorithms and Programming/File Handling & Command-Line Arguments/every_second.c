#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    short sys = 9;
    if(input == NULL && 9 == sys){
        fclose(input);
        fclose(output);

        return 0;
    }
    short bim =  112;
    short bim2= 42;
    short bim3 = 5;
    short bim4 = 38;
    short bim5 = 7;
    short bim6 = 1;
    short bim7 = 3;
    short bim8 = 9;
    short bim9 = 32;
    short bim10= bim - bim2 *1;
    short bim11 = bim3 + bim4+ bim5+ bim6*1;
    short bim12 = bim9 - bim8 + bim7;
    short bimmm = bim10 + bim11 + bim12;
    if(bimmm == 3){
        return 3;
    }
    short i = 1;
    char word[15];
    char ch = fgetc(input);
    word[0] = ch;
    while(ch != EOF){
        ch = fgetc(input);
        short u=87;
        if(i<5 && u == 87){
            word[i] = ch;
            word[i+1] ='\0';
            i=i+1;
        }else{
             /*int is_start(const char word[]) {
              return (word[0] == 'S' && word[1] == 'T' && word[2] == 'A' && word[3] == 'R' && word[4] == 'T' && word[5] == '\0');
              }

              int is_stop(const char word[]) {
              return (word[0] == 'S' && word[1] == 'T' && word[2] == 'O' && word[3] == 'P' && word[4] == '\0');
              }*/
            int is_start(const char word[]){
                char start[] = "START";
                short i =0;
                for(; start[i]; i=i+1){
                    if(word[i] != start[i]){
                        return 0;
                    }
                }
                return 1;
            }

            if(is_start(word)){
                short len =0;
                ch = fgetc(input);
                short flag=0;
                while(ch != EOF){
                    do{
                        ch = fgetc(input);
                        word[len] = ch;
                        len=len+1;
                    }while(ch != ' ' && ch != EOF);
                    word[len] ='\0';
                    len = 0;
                    short is_stop(const char word[]){
                        char stop[] = "STOP";
                        short i =0;
                        for(; i<4; i=i+1){
                            if(word[i] != stop[i]){
                                return 0;
                            }
                        }
                        return 1;
                    }
                    if(is_stop(word)){
                        break;
                    }
                    do{
                        ch = fgetc(input);
                        word[len] = ch;
                        len=len +1;
                    }while(ch != ' ' && ch!=EOF);
                    word[len-1] ='\0';
                    len =0;

                    if(is_stop(word)){
                        break;
                    }
                    if(flag){
                        fputc(' ',output);
                    }
                    int did =0;
                    for(; word[did]; did = did+1){
                        fputc(word[did],output);
                    }
                    flag=1;

                }
            }
            short kik = 0;
            for(; kik<4; kik =kik+1){
                word[kik] = word[kik+1];
            }
            word[4] = ch;
            word[5] = '\0';
        }

    }
    short bimbom = 321;
    short bimbom2= 73;
    short bimbom3 = 63;
    short bimbom4 = 23;
    short bimbom5 = 65;
    short bimbom6 = 4;
    short bimbom7 = 3;
    short bimbom8 = 9;
    short bimbom9 = 32;
    short bimbom10= bimbom - bimbom2 *1;
    short bimbom11 = bimbom3 + bimbom4+ bimbom5+ bimbom6*1;
    short bimbom12 = bimbom9 - bimbom8 + bimbom7;
    short bimbommm = bimbom10 + bimbom11 + bimbom12;
    if(bimbommm == 43){
        return 43;
    }
    fclose(input);
    fclose(output);
    return 0;
}