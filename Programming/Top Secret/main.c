#include <stdio.h>
#include "playfair.h"
#include <stdlib.h>
#include "bmp.h"
#include <string.h>

int main(){
    printf("____Modul_Playfair____\n");
    char *encrypted, *decrypted;

    encrypted = playfair_encrypt("secret", "hello");//1.1
    printf("%s", encrypted);
    decrypted = playfair_decrypt("SeCRet", encrypted);//1.2
    printf("%s", decrypted);
    free(encrypted);
    free(decrypted);


    printf("\n____Modul_BMP____\n");
    char* reversed = reverse("Ale len zrazu vyskoci a povie hostinskemu");//2
    printf("%s\n", reversed);
    char* encryptedd = vigenere_encrypt("CoMPuTeR", "Hello world!");//3.1
    printf("%s\n", encryptedd);
    char* decryptedd = vigenere_decrypt("CoMPuter", "JSXAI PSINR!");//3.2
    printf("%s\n", decryptedd);
    unsigned char* encrypteddd;
 //   unsigned char* decc;
// basic test with long text
    encrypteddd = bit_encrypt("Hello world!");
    for(int i=0; i < 12;i++){
        printf("%x ", encrypteddd[i]);
        //80 9c 95 95 96 11 bc 96 b9 95 9d 10
    }
    free(encrypteddd);
    /*char* decc;
    decc = bit_decrypt("80 9c 95 95 96 11 bc 96 b9 95 9d 10");
    for(int i=0; i < 12;i++) {
        printf("%x ", decc[i]);
        //80 9c 95 95 96 11 bc 96 b9 95 9d 10
    }
    free(decc);
*/
    unsigned char *bmpEnk;
    char *bmpDek;
    bmpEnk = bmp_encrypt("world","hello");
    int i = 0;
    for( ; bmpEnk[i];i=i+1){
        printf("%x ",bmpEnk[i]);
    }
    printf("\n");
    bmpDek = bmp_decrypt("world",bmpEnk);
    printf("%s\n",bmpDek);
    free(bmpEnk);
    free(bmpDek);

}

