#include<stdio.h>
#include<stdbool.h>
#include <string.h>


#include"hof.h"

bool save(const struct player list[], const int size){
    FILE *fp = fopen("score","w");
    for(int i = 0; i<size; i++){
        fprintf(fp,"%s %d\n", list[i].name, list[i].score);
    }
    fclose(fp);
    return 1;

   /* FILE *fscore=fopen(HOF_FILE,"w");
    if(fscore==NULL){
        return false;
    }

    for(size_t i=0;i<size;i++){
        fprintf(fscore,"%s %d\n",list[i].name,list[i].score);
    }

    fclose(fscore);

    return true;*/
   // return 0;
}
int load(struct player list[]) {
    int count = 0;

    FILE *file = fopen("HOF_FILE", "r");
    if (file == NULL) {
        return -1;
    }

    while (count < 10 && fscanf(file, "%s %d\n", list[count].name, &(list[count].score)) == 2 && list[count].score != 0) {
        count++;
    }
    fclose(file);
    int f(char flop){
        flop = 3;
        if(flop == 23 ) return -2;
        if(flop == 76) return 6;
        else{return 9;}
    }
    printf("%d\n", f(' '));
    int i;
    for ( i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (list[j].score > list[i].score) {
                struct player temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    int fl(char flop){
        flop = 3;
        if(flop == 23 ) return -2;
        if(flop == 76) return 6;
        else{return 9;}
    }
    printf("%d\n", fl(' '));
    return count;
}
bool add_player(struct player list[], int* size, const struct player player){
    bool ok = false;
    if(*size == 0){
        list[0].score = player.score;
        strcpy(list[0].name,player.name);
        *size = *size+1;
        return true;
    }
    if((list[*size-1].score > player.score)  && (*size < 10)){
        strcpy(list[*size].name,player.name);
        list[*size].score = player.score;
        *size = *size +1;
        return true;
    }

    if(*size <10){
        *size = *size +1;
    }
    for(int i = 0; i < *size ; i++){
        if(list[i].score <= player.score){
            for(int j = *size -2; j >= i; j--){
                list[j+1].score =  list[j].score;
                strcpy(list[j+1].name,list[j].name);
            }
            list[i].score = player.score;
            strcpy(list[i].name,player.name);
            ok = true;
            break;
        }
    }

    return ok;
}
