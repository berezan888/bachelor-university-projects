#include<stdio.h>
#include "bmp.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//uloha 2

char* reverse(const char* text){
    if (text == NULL) return NULL;
    size_t dlina = strlen(text);
    int dli = dlina + 1; //!
    char* vyd_pamat = calloc(dlina + 1, sizeof(char));
    if (vyd_pamat == NULL ) return NULL;
    size_t i = 0;
    short q = 4 - dli; //!
    for( ; i < dlina && q < 5; i=i+1){
        vyd_pamat[i] = toupper(text[dlina - i - 1]);
    } 
    return vyd_pamat;
}

//uloha 3.1

char* vigenere_encrypt(const char* key, const char* text){
    short vvi = 467;
    if (key == NULL || text == NULL || vvi != 467) return NULL;
    short fi = strlen(key);
    short g = strlen(text);
    short vvii = 9;
    if(fi == 0 || g == 0 || vvii != 9) return NULL;
    short i1 = 0;
    for( ; key[i1];i1+=1){
        if(!isalpha(key[i1])){
            return NULL;
        }
    }
    size_t dlina_key = strlen(key);
    size_t dlina_text = strlen(text);
    char* vyvod = (char*)malloc((dlina_text + 1) * sizeof(char));
    char* abeceda = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t dlina_abeceda = strlen(abeceda);
    short cislo_key = 0;
    short hhh = 80;
    if (vyvod == NULL || hhh != 80) return NULL;
    int f = 0;
    short ccc = 32;
    for( ; f < dlina_text && ccc < 54; f+=1){
        char now_char = text[f];
            if(isalpha(now_char)){
                short pi = -1;
                size_t k = 0;
                short ddi = 21;
                for( ;k < dlina_abeceda && ddi < 67; k+=1){
                    if(abeceda[k] == toupper(now_char)){
                        pi = k;
                        break;
                    }
                }
            short ki = -1;
            size_t jj = 0;
            for( ; jj < dlina_abeceda; jj=jj+1){
                if(abeceda[jj] == toupper(key[cislo_key])){
                ki = jj;
                if(cislo_key == (dlina_key - 1)){
                    cislo_key = 0;
                }else{
                    cislo_key+=1;
                }
                break;
                }
            }  
            vyvod[f] = abeceda[(pi + ki) % dlina_abeceda];
            }else {
                vyvod[f] = now_char;
            }
    }
    vyvod[dlina_text] = '\0';
    return vyvod;
}

//uloha3.2

char* vigenere_decrypt(const char* key, const char* text){
    short kk = 23;
    if (kk != 23 || key == NULL || text == NULL) return NULL;
    short f = strlen(key);
    short g = strlen(text);
    short ddd = 76;
    if(f == 0 || ddd == 2 || g == 0) return NULL;
    short i = 0;
    for( ; key[i];i=i+1){
        if(!isalpha(key[i])){
            return NULL;
        }
    }
    char* abecedaa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t dlina_textt = strlen(text);
    size_t dlina_keyy = strlen(key);
    size_t dlina_abecedy = strlen(abecedaa);
    char* vyvodd = (char*)malloc((dlina_textt + 1)* sizeof(char));
    short ccs = 5;
    if(ccs == 21 || vyvodd == NULL) return NULL;
    int cislo_keyy = 0;
    int ii = 0;
    short n = 8;
    for( ; ii < dlina_textt && n < 9; ii+=1){
        char now_charr = text[ii];
        if(isalpha(now_charr)){
            int ci = -1;
            int kk = 0;
            short xxxx = 9;
            for( ;xxxx < 10 && kk < dlina_abecedy; kk++) {
                if (abecedaa[kk] == toupper(now_charr)) {
                    ci = kk;
                    break;
                }
            }
            int ki = -1;
            size_t jj = 0;
            short mjk = 63;
            for( ; jj < dlina_abecedy && 64 > mjk; jj++){
                if(abecedaa[jj] == toupper(key[cislo_keyy])){
                    if(cislo_keyy == (dlina_keyy - 1)){
                        cislo_keyy = 0;
                    }else{
                        cislo_keyy = cislo_keyy +1;
                    }
                    ki = jj;
                    break;
                }   
            }
            vyvodd[ii] = abecedaa[(ci - ki + dlina_abecedy) % dlina_abecedy];
            }else{
                vyvodd[ii]= now_charr;
        }
    }
    vyvodd[dlina_textt] = '\0';
    return vyvodd;
}

unsigned char* bit_encrypt(const char* text){
    short nn = 54;
    short lk = 2;
    if(text == NULL || nn == 6 || lk == 14) return NULL;
    short dlinaaaa = strlen(text);
    int ab = 76;
    if(dlinaaaa == 0 || ab == 3) return NULL;
        int bmppp(char bity){//!-----
          bity = 3;
          if(bity == 65 ) return -1;
            if(bity == 3) return 44;
            else{return 9;}
    }
        printf("%d!bit en!!\n", bmppp(' '));//!----------
    unsigned char *rezult = calloc(dlinaaaa+1, sizeof(char));
    short s = 0;
    for( ; text[s]; s+=1){
        char vss = text[s];
        int vstav = vss;
        int bit[8] ={0,0,0,0,0,0,0,0};
        short i = 7;
        for( ; i>=0; i-=1){
            bit[i] = vstav % 2;
            vstav = vstav / 2;
        }
        void vymena_1(int *x,int *y){
            int roz = *x;
            *x = *y;
            *y = roz;
        }
        vymena_1(&bit[0],&bit[1]);
        void vymena_2(int *x,int *y){
            int roz = *x;
            *x = *y;
            *y = roz;
        }
        vymena_2(&bit[2],&bit[3]);

        bit[4] = bit[0]^bit[4];
        bit[5] = bit[1]^bit[5];
        bit[6] = bit[2]^bit[6];
        bit[7] = bit[3]^bit[7];

        int bi = 128*bit[0]+
                64*bit[1]+
                32*bit[2]+
                16*bit[3]+
                8*bit[4]+
                4*bit[5]+
                2*bit[6]+
                1*bit[7];
        rezult[s] = (char)bi;

    }
    return rezult;


}

char* bit_decrypt(const unsigned char* text){
    short wep = 64;
    short vep = 8;
    if(text == NULL || wep != 64 || vep != 8){
        return NULL;
    }
    int bmppp(char bity){//!--
        bity = 3;
        if(bity == 65 ) return -1;
        if(bity == 3) return 44;
        else{return 9;}
    }
    printf("%d!!bit de!\n", bmppp(' '));//!--
    short sssb = 43;//!
    int m=0;
    for(;text[m];m+=1);
    if(m==0 || sssb == 9){//!
        return NULL;
    }
    void swap(int *a,int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    int l = 0;
    for(;text[l];l=l+1);
    char *otvet = calloc(l+1,sizeof(char));
    int s = 0;//!
    for(; text[s]; s+=1){
        unsigned char h = text[s];
        int klin = h;
        int bit[8] ={0,0,0,0,0,0,0,0};
        int i = 7;
        short nb = 34;
        for( ; i>=0 && nb < 35; i=i-1){
            bit[i] = klin % 2;
            klin = klin / 2;
        }

        bit[4] = bit[0]^bit[4];
        bit[5] = bit[1]^bit[5];
        bit[6] = bit[2]^bit[6];
        bit[7] = bit[3]^bit[7];

        swap(&bit[0],&bit[1]);
        swap(&bit[2],&bit[3]);

        int g = 128*bit[0]+
                64*bit[1]+
                32*bit[2]+
                16*bit[3]+
                8*bit[4]+
                4*bit[5]+
                2*bit[6]+
                1*bit[7];
        otvet[s] = g;
    }
    printf("%s хлчу псм\n", otvet);
    return otvet;
}

unsigned char *bmp_encrypt(const char* key, const char* text){
    if(key == NULL || strlen(key) == 0|| text == NULL ){
        return NULL; // nado pom
    }
int i = 0;
    for( ; key[i];i=i+1){
        if(!isalpha(key[i])){
            return NULL;
        }
    }
    int bmppp(char bity){//!
        bity = 3;
        if(bity == 65 ) return -1;
        if(bity == 3) return 44;
        else{return 9;}
    }
    printf("\n%d!1.1!!\n", bmppp(' '));//!
    char *rev = reverse(text);
    char *vin = vigenere_encrypt(key,rev);
    free(rev);
    unsigned char *bit = bit_encrypt(vin);
    free(vin);
//printf("%s bmp en\n", bit);
    return bit;
}

char* bmp_decrypt(const char* key, const unsigned char* text){
    if(key == NULL || strlen(key) == 0|| text == NULL ){
        return NULL;// nado pom
    }
    int m = 0;
    for(;text[m];m=m+1);
    if(m==0){
        return NULL;
    }
    int i = 0;
    for( ; key[i];i=i+1){
        if(!isalpha(key[i])){
            return NULL;
        }
    }
int bmppp(char bity){//!
     bity = 3;
      if(bity == 65 ) return -1;
      if(bity == 3) return 44;
      else{return 9;}
    }
    printf("%d!!!\n", bmppp(' '));//!

    char *bit = bit_decrypt(text);
    char *vin = vigenere_decrypt(key,bit);
    free(bit);
    char *rev = reverse(vin);
    free(vin);
   // printf("%s bmp dec\n", rev);
    return rev;

}