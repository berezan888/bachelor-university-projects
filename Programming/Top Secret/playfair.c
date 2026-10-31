#include<stdio.h>
#include "playfair.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//char* playfair_encrypt(const char* key, const char* text);
//char* playfair_decrypt(const char* key, const char* text);
//void find_coordinates(char matica[5][5], char co, int* row, int* col);
//void build_matica(const char* key, char matica[5][5]);



/*void find_coordinates(char matica[5][5], char co, int* row, int* col){
    int i = 0;
    int j = 0;
    for( ; i < 5; ++i){
        for( ; j < 5; ++j){
            if(matica[i][j] == co){
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void build_matica(const char* key, char matica)*/

char* playfair_encrypt(const char* key, const char* text){

  /*  if(key == NULL || text ==NULL ){
        return NULL;

    }

    if(strlen(key)==0 || strlen(text)==0){
        return NULL;
    }

    for(int i=0;i < strlen(key);i++){
        if(!isalpha(key[i])){
            return NULL;
        }
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i]!=32 && (text[i] < 65 || text[i]>90) && (text[i] < 97 || text[i]>122)) {
            return NULL;
        }

    }*/
    if (key == NULL) {
        return NULL;
    }
    if (text == NULL) {
        return NULL;
    }
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i]!=32 && (key[i] < 65 || key[i]>90) && (key[i] < 97 || key[i]>122)) {
            return NULL;
        }

    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i]!=32 && (text[i] < 65 || text[i]>90) && (text[i] < 97 || text[i]>122)) {
            return NULL;
        }

    }

    char* abeceda = calloc(26, sizeof(char));

    int p = 0;
    for (int i = 0; i < 25; i++) {
        if (65+i == 87) p = 1;

        abeceda[i] = 65+i+p;
    }

    abeceda[25] = 0;

//    abeceda = "ABCDEFGHIJKLMNOPQRSTUVXYZ\0";
    char matica[5][5];
    int index[100];

    char* keyy = calloc(strlen(key) + 1, sizeof(char) );

    for(int i = 0; i < strlen(key); i++){//proverka verchnyj registr key
        keyy[i] = toupper(key[i]);
    }
    for (int i = 0; i < strlen(keyy); ++i) {
        for (int j = i+1; j < strlen(keyy); ++j) {
            if (keyy[i] == keyy[j] && key[j] != '_') {
                keyy[j] = '_';
            }
        }
    }

    char* key_reduced = calloc(strlen(keyy), sizeof(char));
    int idx = 0;

    for (int i = 0; i < strlen(keyy); i++) {
        key_reduced[i] = 0;
    }

    for (int i = 0; i < strlen(keyy); i++) {
        if (keyy[i] != '_') {
            key_reduced[idx] = keyy[i];
            idx++;
        }
    }

    for (int i = 0; i < strlen(key_reduced); i++) {
        for (int j = 0; j < 25; j++) {
            if (abeceda[j] == key_reduced[i]) {
                abeceda[j] = '_';
            }
        }
    }

    char* reduced_abeceda = calloc(26, sizeof(char));

    for (int i = 0; i < 26; i++) {
        reduced_abeceda[i] = 0;
    }

    idx = 0;

    for (int i = 0; i < strlen(abeceda); i++) {
        if (abeceda[i] != '_') {
            reduced_abeceda[idx] = abeceda[i];
            idx++;
        }
    }

    char* matica_flat = calloc(25, sizeof(char));

    for (int i = 0; i < 25; ++i) {
        matica_flat[i] = 0;
    }

    for (int i = 0; i < strlen(key_reduced); i++) {
        matica_flat[i] = key_reduced[i];
    }

    for (int i = 0; i < strlen(reduced_abeceda); i++) {
        matica_flat[strlen(key_reduced)+i] = reduced_abeceda[i];
    }

    printf("key matica: \n");//vvod danych v masiv
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matica[i][j] = matica_flat[i * 5 + j];
        }
    }
    for(int i = 0;i < 5; i++){//vyvod masiva
        for(int j = 0; j < 5;j++){
            printf("%c ", matica[i][j]);
        }
        printf("\n");
    }
    char* textt = calloc(strlen(text)+ 1, sizeof(char));
    for(int i = 0; i < strlen(textt); i++){// proverka na verchnyj registr
        textt[i] = tolower(key_reduced[i]);
    }
    for(int i = 0; i < strlen(textt); i++){// obrabotka dublirovania d
        if(textt[i] == textt[i + 1]){
            memmove(textt + i + 1, textt + i + 2, strlen(textt) - i);
            textt[strlen(textt) - 1] = '\0';
        }
    }
    if(strlen(textt) % 2 != 0){//dobavlenie symvola v text d
        textt[strlen(textt)] = 'X';
        textt[strlen(textt) + 1] = '\0';
    }
    for(int i = 0; i < strlen(textt); i += 2){//form dygram
        printf("%5c%c", textt[i], textt[i + 1]);
    }
    printf("\n");
    for(int i = 0; i < strlen(textt); i++){// najst index v matice
        for(int j = 0; j<5; j++){
            for(int k = 0; k < 5; k++){
                index[i] = j;
                index[i + 1] = k;
            }
        }
    }

   printf("%s\n", (char*) index);//
////d

    for( int i = 0; i < strlen(text); i++){//proverka verchnyj registr key
        textt[i] = toupper(text[i]);
    }
    //printf("%s\n", textt);
    //printf("\n\n");
    int n = 0;
    int j = 0;
    while(textt[n] != '\0'){
        if(textt[n] == ' '){
            for(j = n+1; textt[j]; j++){
                textt[j-1] = textt[j];
            }
            textt[j-1]='\0';
        }else if(textt[n] == 'w' || textt[n] == 'W') {
            textt[n] = 'V';
        }else{
            n++;
        }
    }
    int count = 0;
    for (int i = 1; textt[i]; i++){
        if(textt[1-i] == textt[i]) count++;
    }
    //printf("%d\n", count);

   n =1;
    while(textt[n]!='\0'){
        if(textt[n-1] == textt[n] && (textt[n-1] != 'X') &&
           (n-1)%2 == 0){
            int l =strlen(textt);
            for(int s = l-1; s>=n; s--){
                textt[s+1] = textt[s];
            }textt[l+1] = '\0';

            textt[n] = 'X';
            n+=2;
        }else{
            n++;
        }
    }
    if (strlen(textt) %2 == 1){
        int ll =strlen(textt);
        textt[ll]  = 'X';
        textt[ll+1]='\0';
    }
    printf("%s\n\n\n", textt);
//HELXLOVORLDX
    int kuku = 0;
    char para[strlen(textt)/2][2];
    int i = 0;
    int dlina = strlen(textt)/2;
    for( ; i < dlina; i++){
        para[i][0] = textt[kuku];
        kuku++;
        para[i][1] = textt[kuku];
        kuku++;
    }
    //printf("%c\n", para);
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    char a;
    char b;
    int ii = 0;
    for( ;ii < dlina; ii++){
        a = para[ii][0];
        b = para[ii][1];

        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++){
                if(a == matica[y][x]){
                    x1 = x;
                    y1 = y;
                }
                if(b == matica[y][x]){
                    x2 = x;
                    y2 = y;
                }
            }
            if(x1 == x2){
                para[ii][0] = matica[(y1+1)%5][x1];
                para[ii][1] = matica[(y2+1)%5][x2];
            }else if(y1 == y2){
                para[ii][0] = matica[y1][(x1+1)%5];
                para[ii][1] = matica[y2][(x2+1)%5];
            }else{
                para[ii][0] = matica[y1][x2];
                para[ii][1] = matica[y2][x1];
            }
        }
    }
   // printf("%c\n", matica);
    char *result_en = calloc(strlen(textt),sizeof(char));
    int mim = 0;
    for(int i = 0; i < strlen(textt)/2  ; i++){
        result_en[mim] = para[i][0];
        mim++;
        result_en[mim] = para[i][1];
        mim++;
        result_en[mim] =' ';
        mim++;
    }
    result_en[strlen(result_en)-1] = '\0';
    printf("\n%s\n", result_en);
    ////d
    return result_en;
}

char* playfair_decrypt(const char* key, const char* text){
  /*  if(key == NULL || text ==NULL ){
        return NULL;
    }

    if(strlen(key)==0 || strlen(text)==0){
        return NULL;

    }
    for(int i=0;i < strlen(key);i++){
        if(!isalpha(key[i])){
            return NULL;
        }
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != 32 && (text[i] < 65 || text[i]>90) && (text[i] < 97 || text[i]>122)) {
            return NULL;
        }
    }*/
    if (key == NULL) {
        return NULL;
    }
    if (text == NULL) {
        return NULL;
    }
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i]!=32 && (key[i] < 65 || key[i]>90) && (key[i] < 97 || key[i]>122)) {
            return NULL;
        }

    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i]!=32 && (text[i] < 65 || text[i]>90) && (text[i] < 97 || text[i]>122)) {
            return NULL;
        }

    }
    char abeceda[26] = {0};

    int p = 0;
    for (int i = 0; i < 25; i++) {
        if (65+i == 87) p = 1;

        abeceda[i] = 65+i+p;
    }

//    abeceda = "ABCDEFGHIJKLMNOPQRSTUVXYZ\0";
    char matica[5][5];
    int index[100];
    char* keyy = calloc(strlen(key) + 1, sizeof(char) );

    for(int i = 0; i < strlen(key); i++){//proverka verchnyj registr key
        keyy[i] = toupper(key[i]);
    }
    for (int i = 0; i < strlen(keyy); ++i) {
        for (int j = i+1; j < strlen(keyy); ++j) {
            if (keyy[i] == keyy[j] && key[j] != '_') {
                keyy[j] = '_';
            }
        }
    }

    char* key_reduced = calloc(strlen(keyy), sizeof(char));
    int idx = 0;

    for (int i = 0; i < strlen(keyy); i++) {
        key_reduced[i] = 0;
    }

    for (int i = 0; i < strlen(keyy); i++) {
        if (keyy[i] != '_') {
            key_reduced[idx] = keyy[i];
            idx++;
        }
    }

    for (int i = 0; i < strlen(key_reduced); i++) {
        for (int j = 0; j < 25; j++) {
            if (abeceda[j] == key_reduced[i]) {
                abeceda[j] = '_';
            }
        }
    }

    char* reduced_abeceda = calloc(26, sizeof(char));

    for (int i = 0; i < 26; i++) {
        reduced_abeceda[i] = 0;
    }

    idx = 0;

    for (int i = 0; i < strlen(abeceda); i++) {
        if (abeceda[i] != '_') {
            reduced_abeceda[idx] = abeceda[i];
            idx++;
        }
    }

    char* matica_flat = calloc(25, sizeof(char));

    for (int i = 0; i < 25; ++i) {
        matica_flat[i] = 0;
    }

    for (int i = 0; i < strlen(key_reduced); i++) {
        matica_flat[i] = key_reduced[i];
    }

    for (int i = 0; i < strlen(reduced_abeceda); i++) {
        matica_flat[strlen(key_reduced)+i] = reduced_abeceda[i];
    }

    printf("key matica: \n");//vvod danych v masiv
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matica[i][j] = matica_flat[i * 5 + j];
        }
    }
    for(int i = 0;i < 5; i++){//vyvod masiva
        for(int j = 0; j < 5;j++){
            printf("%c ", matica[i][j]);
        }
        printf("\n");
    }
    char* textt = calloc(strlen(text)+ 1, sizeof(char));
    for(int i = 0; i < strlen(textt); i++){// proverka na verchnyj registr
        textt[i] = tolower(key_reduced[i]);
    }
    for(int i = 0; i < strlen(textt); i++){// obrabotka dublirovania d
        if(textt[i] == textt[i + 1]){
            memmove(textt + i + 1, textt + i + 2, strlen(textt) - i);
            textt[strlen(textt) - 1] = '\0';
        }
    }
    if(strlen(textt) % 2 != 0){//dobavlenie symvola v text d
        textt[strlen(textt)] = 'X';
        textt[strlen(textt) + 1] = '\0';
    }
    for(int i = 0; i < strlen(textt); i += 2){//form dygram
        printf("%5c%c", textt[i], textt[i + 1]);
    }
    printf("\n");
    for(int i = 0; i < strlen(textt); i++){// najst index v matice
        for(int j = 0; j<5; j++){
            for(int k = 0; k < 5; k++){
                index[i] = j;
                index[i + 1] = k;
            }
        }
    }

    printf("%s\n", (char*) index);//
////d

    for( int i = 0; i < strlen(text); i++){//proverka verchnyj registr key
        textt[i] = toupper(text[i]);
    }
    //printf("%s\n", textt);
    //printf("\n\n");
    int n = 0;
    int j = 0;
    while(textt[n] != '\0'){
        if(textt[n] == ' '){
            for(j = n+1; textt[j]; j++){
                textt[j-1] = textt[j];
            }
            textt[j-1]='\0';
        }else if(textt[n] == 'w' || textt[n] == 'W') {
            textt[n] = 'V';
        }else{
            n++;
        }
    }
    int count = 0;
    for (int i = 1; textt[i]; i++){
        if(textt[1-i] == textt[i]) count++;
    }
    //printf("%d\n", count);

    n =1;
    while(textt[n]!='\0'){
        if(textt[n-1] == textt[n] && (textt[n-1] != 'X') &&
           (n-1)%2 == 0){
            int l =strlen(textt);
            for(int s = l-1; s>=n; s--){
                textt[s+1] = textt[s];
            }textt[l+1] = '\0';

            textt[n] = 'X';
            n+=2;
        }else{
            n++;
        }
    }
    if (strlen(textt) %2 == 1){
        int ll =strlen(textt);
        textt[ll]  = 'X';
        textt[ll+1]='\0';
    }
    printf("%sпринт плиз  465\n", textt);
//HELXLOVORLDX
    char pairs[count/2][2];
    int ppp =0;
    for(int i = 0; text[i]; i++){
        pairs[ppp][0] = text[i];
        i++;
        pairs[ppp][1] = text[i];
        ppp++;
        i++;
    }
    int x1=0,x2=0,y1=0,y2=0;
    char a,b;
    for(int i = 0;i <count/2; i++){
        a = pairs[i][0];
        b = pairs[i][1];
        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++){
                if(a == matica[y][x]){
                    x1 = x;
                    y1 = y;
                }
                if(b == matica[y][x]){
                    x2 = x;
                    y2 = y;
                }
            }
            if(x1 == x2){
                int ya = (y1-1)%5;
                int yb = (y2-1)%5;
                ya = (ya == -1) ? 4: ya;
                yb = (yb == -1) ? 4: yb;
                pairs[i][0] = matica[ya][x1];
                pairs[i][1] = matica[yb][x2];
            }else if(y1 == y2){
                int xa = (x1-1)%5;
                int xb = (x2-1)%5;
                xa = (xa == -1) ? 4:xa;
                xb = (xb == -1) ? 4:xb;
                pairs[i][0] = matica[y1][xa];
                pairs[i][1] = matica[y2][xb];
            }else{
                pairs[i][0] = matica[y1][x2];
                pairs[i][1] = matica[y2][x1];

            }
        }
    }
    char *ans = calloc(strlen(text), sizeof(char));
    int d = 0;
    for(int i = 0; i< count/2; i++){
        ans[d] = pairs[i][0];
        d++;
        ans[d] = pairs[i][1];
        d++;
    }
    //ans[d] ='\0';
   // ans[strlen(ans)-1] = '\0';
    printf("\n%s.сегментейшн.523.\n", ans);


    return ans;
}