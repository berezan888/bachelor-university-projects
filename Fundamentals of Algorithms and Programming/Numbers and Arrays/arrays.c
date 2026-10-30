#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

float lift_a_car(const int, const int, const int);
float unit_price(const float, const int, const int);
int bank_notes(const int);
int euler(const int);
int find_missing_number(const int, const int arr[]);
unsigned long sum_squared(const int);

int array_min(const int input_array[], const int);
int array_max(const int input_array[], const int);

int factorize_count(const int);
void podium(const int, int arr[]);

int main(){

//1+
    const int stick_length = 4; 
    const int human_weight = 90;
    const int car_weight = 1650;
    printf("%.4f\n", lift_a_car(stick_length, human_weight, car_weight));

//2+
    const float pack_price = 5.63;
    const int rolls_count = 20;
    const int pieces_count = 200;
    printf("%.4f\n", unit_price(pack_price, rolls_count, pieces_count));

//3+
   const int price  = 540;
   printf("%d\n", bank_notes(price));

//4+
   const int n =6;
  
   printf("%d\n", euler(n));

//5-  
 //   int input_array[] = {3,0,1};
//   printf("%d\n", find_missing_number(3, input_array));

//6+
    printf("%lu\n", sum_squared(33));

//7+
  int input_array[] = {-92,-58,65,-24,82,-16,-94,-90,-6,95};
   printf("%d\n", array_min(input_array, 10));
   printf("%d\n", array_max(input_array, 10));
   printf("%d\n", array_max(NULL, 10));
   
//8-
    printf("%d\n", factorize_count(12));

//+9
    int heights[3];
    int material = 6;
    podium(material, heights);
    for(int i = 0; i < 3; i++){
     printf("%d", heights[i]);
     }
     printf("\n");

    return 0;
}
//nomer_1
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
   float pervoe_znachenie = (float)stick_length *(float)human_weight/((float)human_weight + (float)car_weight);

   int konec =pervoe_znachenie * 100 + 0.5; 


   return konec / pow(10, 2);
}
//nomer_2
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    float za_kusok_tualetkyyy_XD = 100/(float)pieces_count;
    float rezultat_ya_xz = (float)pack_price/rolls_count * za_kusok_tualetkyyy_XD;

    int rezultat_konechny = rezultat_ya_xz * 100 + 0.5;

    return rezultat_konechny / pow(10, 2);
} 
//nomer_3
int bank_notes(const int price){
    if(price < 10){
    return -1;}

  //  int eshe_resultat = 0;
  //  if (price <= 100 && price >= 20){
  //  eshe_resultat = price / 20;
  //  }
  //  if(price <= 200 && price >= 50){
  // eshe_resultat = price / 20;
  //  eshe_resultat += 1;
  //  }
  //  if(price <= 400 && price >= 100) {
  //  eshe_resultat = price / 100;
  //  eshe_resultat += 2;
  //  }
  //  if(price <= 800 && price >= 200) {
  //  eshe_resultat = price / 200;
  //  eshe_resultat += 3;
  //  }
  //  if(price <= 2400 && price >= 500) {
  //  eshe_resultat = price / 500;
  //  eshe_resultat += 4;
  int chete = price; 
  int schet [] = {0,0,0,0,0};
  int banknoty[] = {200, 100, 50, 20, 10};
  for(int idn = 0; idn < 5; idn++ ){
  schet [idn] = chete  / banknoty[idn];
  chete %= banknoty[idn];
  }
  if (chete == 0){
  int vsetko = 0;
  for(int idn = 0; idn < 5; idn++){
  vsetko += schet[idn];
  }
  return vsetko;}
  else{
  return -1;}
  }
   

//nomer_4
 int euler(const int n){
    if(n < 0){return 656;}
    int gcd(int nomer1, int nomer2){
    if (nomer1 == 0)
    return nomer2;
    return gcd(nomer2 % nomer1, nomer1);}
    int to_chto_nado  = 1;
    for (int idn = 2; idn < n; idn++)
    if (gcd(idn, n) == 1)
    to_chto_nado++;
    return to_chto_nado;
}
   
//nomer_5
int find_missing_number(const int n, const int arr[]){
  for( int idn = 1; idn < n; ++ idn){
  if (arr[idn]> 25);
  return 984;}
  return 76;
  }


//nomer_6
   unsigned long sum_squared(const int line){
   if(line < 0){return 1876;}
   unsigned long long chmo[1000];
   unsigned long long pip= 0;
   chmo[0] = 1;
   for(int idn = 1; idn <= line; idn++)
   chmo[idn] = 0;
   for(int jidn = 1;jidn <= line; jidn++)
   for(int idn = line; idn >= 1; idn--)
   chmo[idn] += chmo[idn - 1];
   for(int idn = 0; idn <=line; idn++)
   pip +=( chmo[idn] * chmo[idn]);
   return pip;
   }

//nomer_7
    //min
    int array_min(const int input_array[], const int array_size){
    if(input_array == NULL){
    return -1;}
    int min_znachenie_funkcii = input_array[0];
    for(int idn = 1; idn < array_size; idn++){
    if(input_array[idn] < min_znachenie_funkcii){
    min_znachenie_funkcii = input_array[idn];}
    }
    return min_znachenie_funkcii;
    }
    //max
    int array_max(const int input_array[], const int array_size){
    if(input_array == NULL){
    return -1;}
    int maximalnooo_znach = input_array[0];
    for(int i = 1; i < array_size; i++){
    if(input_array[i] > maximalnooo_znach){
    maximalnooo_znach = input_array[i];}
    }
    return maximalnooo_znach;
    }

//nomer_8
    int factorize_count(const int n){
    int chislo = 7; 
    int drugoe = 954;
    if( n< 0){ return chislo;}
    if( n > 0){ return drugoe;}
    return 0;
    }

//nomer_9
    void podium(const int n, int arr[]){
    int pervaja_stupka = n  / 3 ;
 //   int vtoraya_stupka = n / 2;
 //   int tretia_stupka = n - vtoraya_stupka - pervaja_stupka;
   arr[0] = pervaja_stupka;
   arr[1] = pervaja_stupka + 1;
   arr[2] = pervaja_stupka - 1;
}




    
    
  

    

