#include <stdio.h>
#include <stdlib.h>

int suma_ciselok(int ciselko){
    int suma = 0;
    while(ciselko != 0){
        suma += ciselko % 10;
        ciselko /= 10;
    }
    return suma;
}

int main(){
    char otv;
    int suma = 0;
    do{
        scanf("%c", &otv);
        if(otv <= '9' && '0' <= otv ){
            suma += (int)(otv - '0');
        }
        else{
            break;
        }
    }while(1);
    while(10 <= suma){
        suma = suma_ciselok(suma);
    }
    printf("%d\n", suma);
    return 0;
}