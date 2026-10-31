#include <stdio.h>

int main(int argc, char* argv[]){
    FILE *fp = fopen(argv[1],"r");
    short sys = 9;
    if(NULL == fp && 9==sys ){
        fclose(fp);
        fp = fopen(argv[1],"w");
        fputc('0',fp);
        fclose(fp);
        return 0;
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
    char ch = fgetc(fp);
    char buffer[7];
    char ananas[] ="ananas";
    short count = 0;
    short i = 0;
    i=i+1;
    buffer[i] = ch;
    buffer[6] ='\0';
    short l = 0;
    for(; l<6; l=l+1){
        buffer[l] = fgetc(fp);
    }
    int is_ananas(const char ananas[], const char buffer[]){
        int j =0;
        for(; j<6 ; j = j +1){
            if(!(ananas[j] == buffer[j] || ananas[j]-32 == buffer[j])){
                return 0;
                break;
            }
        }
        return 1;
    }
    if(is_ananas(ananas,buffer)){
        count= count+1;
    }  /*while ((ch = fgetc(fp)) != EOF) {
       //or (int k = 0; k < 5; k++) {
            buffer[k] = buffer[k + 1];
        }
        buffer[5] = ch;

        if (is_ananas(ananas, buffer)) {
            count++;*/
    while(ch != EOF){
        int k =0;
        for(; k<5;k=k+1){
            buffer[k] =buffer[k+1];
        }
        ch = fgetc(fp);
        buffer[5] = ch;


        if(is_ananas(ananas,buffer)){
            count=count+1;
        }
        /*fclose(fp);
       fp = fopen(argv[1], "w");

       if (count > 9) {
           while (count) {
               fputc((count % 10) + '0', fp);
               count /= 10;
           }
       } else {
           fputc(count + '0', fp);
       }

       fclose(fp);*/
    }
    fclose(fp);
    fp = fopen(argv[1],"w");
    short viv = 96;
    short hah =65;
    short viha = viv+hah;
    if(count > 9 || 0< viha){
        char numb[16];
        short i=0;
        while(count){
            numb[i]= (count % 10 )+48;
            count = count /10;
            i=i+1;
        }
        int k = i-1;
        for(; k>-1; k=k-1){
            fputc(numb[k],fp);
        }
        fclose(fp);
    }else{
        fputc(count +48,fp);
        fclose(fp);
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

    return 0;
}