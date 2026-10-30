#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <time.h>
#include <math.h>

void generator(const int rows, const int columns, char field[rows][columns])
{
    srand(time(NULL));

    char znacki[] = {'n', '9', 's', 'p', '4', '1', '*', 'H'};


    for(short yo = 0; yo < rows;yo++)
    {
        for(short xi =0; xi < columns;xi++)
        {
            field[yo][xi]=' ';
        }
    }

    int rx1ilona = rand() % columns;
    int rx2sasa;
    do{
        rx2sasa = rand() % columns;
    }while(rx1ilona==rx2sasa);

    
    for(short xopp, y, znak =0, rachuvac = 0; znak< columns -2; )
    {
        y = rand() % rows;
        xopp = rand() % columns;

        if(field[y][xopp]!= ' '|| xopp == rx1ilona || xopp==rx2sasa)
        {
            continue;
        }

        field[y][xopp] = znacki[znak];
        rachuvac += 1;

        if(rachuvac == rows)
        {
            znak+=1;
            rachuvac = 0;
        }
    }
}


// void generator(const int rows, const int columns, char field[rows][columns]){
// /*    srand(time(NULL));
//     short pustoj_stolp1;
//     short pustoj_stolp2;
//     do{
//         pustoj_stolp1 = rand() % columns;
//         pustoj_stolp2 = rand() % columns;
//     }while(pustoj_stolp1 == pustoj_stolp2);*/
//     short limitich = columns - 2;
//     short kolichestvosym = rows;

//     srand((unsigned int)time(NULL));



//  /*   for(short pip = 0;pip < columns;++pip){
       
//         if(pip == pustoj_stolp1 || pip == pustoj_stolp2){
//             for(short kik = 0; kik < rows;++kik){
           
//             field[kik][pip] = ' ';
//             }
//         }else{
//             for(short kik = 0;kik < rows;++kik){*/
               
//             char znacki[kolichestvosym];
//           /*  switch(rand()%4){
//                 case 0:
//                     znacka = '@';
//                     break;
//                 case 1:
//                     znacka = '*';
//                     break;
//                 case 2:
//                     znacka = '^';
//                     break;
//                 case 3:
//                     znacka = '+';
//                     break;
//             }*/ znacki[0]='a';
//                 znacki[1]='c';
//                 znacki[2]='b';
//                 znacki[3]='*';
//                 znacki[4]='m';
//                 znacki[5]='p';
//                 znacki[6]='g';
//                 znacki[7]='n';

//                 short lim[kolichestvosym];
//                 for(int i = 0; i < kolichestvosym; ++i){
//                     lim[i]= limitich;}
                
//                 //tasovka
//                 for(int i = kolichestvosym - 1; i>0; --i){
//                     int j = rand() %(i+1);
//                     char temp = znacki[i];
//                     znacki[i]= znacki[j];
//                     znacki[j]= temp;}


//                 for (int row = 0; row < rows; ++row){
//                     for (int col = 0; col < columns; ++col){
//                         if(col == 1 || col == 3){
//                             field[row][col] = ' ';
//                         }else{ 
//                             char znacka = ' ';
//                             for (int i = 0; i < kolichestvosym; ++i){
//                                 if(lim[i]>0){
//                                     znacka =znacki[i];
//                                     lim[i]--;
//                                     break;
//                                  }
//                             }


//                             field[row][col] = znacka;
//             }
//          }   

//     }  

//  /* for(short kik =0;kik < rows;++kik){
      
//         printf("%d |", kik+1);
//         for(short pip = 0; pip < columns;++pip){
          
//             printf(" %c |", field[kik][pip]);
//         } 
//         if(kik < rows - 1){
//             for(short pip = 0; pip<columns;++pip){
            
//             }
//             printf("\n");
//         }
//     }
//     printf("\n");
//     printf("   ");
//     for(short pip = 0;pip<columns;++pip){
    
//     printf("--- ");
//     }
//     printf("\n");
//     printf("    ");
//     for(short pip =0; pip<columns;++pip){
      
//         printf("%d   ", pip + 1);
//     }
//     printf("\n");*/
//     }

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){
    if(y<1 ||x<1 ||y>columns || x>columns){
        printf("Errorrrrrrrrr: Invalid colums specifiled.\n");
        return;
    }
    if(y == x){
        printf("Errorrrrrrrrr: The same columns are selected.\n");
    }
    short emtyroww =0;
    while(emtyroww< rows && field[emtyroww][y - 1] != ' '){
        ++emtyroww;
    }
    if(emtyroww == rows){
        printf("Errorrrrrrr: Column %d is completely full.\n", y);
        return;
    }

    
    short newro = rows -1;
    while(newro >= 0 && field[newro][y - 1] != ' '){
        --newro;
    }
    if(emtyroww == -1){
        printf("Error:rrrrr Column %d is completely full.\n", y);
        return;
    }

    if(field[newro + 1][y-1] != ' ' && field[emtyroww][x-1] != field[newro + 1][y-1]&& field[newro][y]&& newro+1 != rows){
        printf("Error\n");
    }



    field[newro][y-1]= field[emtyroww][x-1];
    field[emtyroww][x-1] = ' ';
    }

/*    for(short kik =0;kik < rows;++kik){
      
        printf("%d |", kik+1);
        for(short pip = 0; pip < columns;++pip){
          
            printf(" %c |", field[kik][pip]);
        } 
        if(kik < rows - 1){
            for(short pip = 0; pip<columns;++pip){
            
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("   ");
    for(short pip = 0;pip<columns;++pip){
    
    printf("--- ");
    }
    printf("\n");
    printf("    ");
    for(short pip =0; pip<columns;++pip){
      
        printf("%d   ", pip + 1);
    }
    printf("\n");}*/
    

bool check(const int rows, const int columns, char field[rows][columns]){
    for(short mim = 0; mim < columns; ++mim){
        char prvsym = field[0][mim];
        for(short lul = 1; lul < rows; ++lul){
            if(field[lul][mim] != prvsym){
                return false;
            }
        }
    }
    return true;
    }


/*int main(){
    const int rows = 4;
    const int columns = 6;

    char field[rows][columns];
    
    printf("\n");
    printf("task_1\n");
    printf("\n");
    generator(rows, columns, field);
    printf("\n");
    printf("task_2\n");
    printf("\n");
 //   char field[4][6]= {
 //       {'*', ' ', '^', '@', '@', ' '},
 //      {'+', ' ', '^', '@', '^', ' '},
 //       {'+', ' ', '*', '+', '+', ' '},
 //       {'*', ' ', '*', '@', '^', ' '}
 //   } ;  
    
  //  printf("Source field:\n");
  //  display_field(rows, columns, field);
  //  printf("\n");
    down_possible(rows, columns, field, 1, 2);
    down_possible(rows, columns, field, 3, 4);
    down_possible(rows, columns, field, 5, 6);
    printf("\n");
    printf("task_3\n");
    printf("\n");
    printf("Check: %s\n",check(rows, columns, field) ? "true" : "false");

return 0;
}*/
