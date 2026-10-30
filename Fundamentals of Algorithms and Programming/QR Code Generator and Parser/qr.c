#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define R return
#define F for
#define FI if

//decaration
void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blockes[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);



int main(){
    
    printf("task_1:\n\n");
    bool bits1[8];
    encode_char('A', bits1);
    for(int i = 0; i < 8; i++){
        printf("%d", bits1[i]);
    }
    printf("\n\n");
    bool bits2[8] = {0,1,0,1,0,0,0,1};
    printf("%c\n", decode_byte(bits2));
    printf("\n");
    printf("task_2:\n\n");
    char* text ="Hello, how are you?";
    const int len = strlen(text);
    bool bytes1[len+1][8];
    encode_string(text, bytes1);
    for(int j=0; j<=len ; j++){
        printf("%c: ", text[j]);
        for(int i=0; i<8; i++){
            printf("%d", bytes1[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    bool bytes2[7][8]={
        {0,1,0,0,1,0,0,0},
        {0,1,1,0,0,1,0,1},
        {0,1,1,0,1,1,0,0},
        {0,1,1,0,1,1,0,0},
        {0,1,1,0,1,1,1,1},
        {0,0,1,0,0,0,0,1},
        {0,0,0,0,0,0,0,0}
    };
    char string[7];
    decode_bytes(7, bytes2, string);
    printf("%s\n", string);
    printf("\n");
    printf("task_3:\n\n");
    int length = 4+1, cols = 3, offset = 2;
 /*   bool bytes1[4+1][8]={
        {0,1,0,0,0,0,0,1},
        {0,1,1,0,1,0,0,0},
        {0,1,1,0,1,1,1,1},
        {0,1,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,0}
    };*/
    bool blocks1[offset*8][cols];
    bytes_to_blocks(cols, offset, blocks1, length, bytes1);
    for(int j =0; j < offset*8; j++){
        for(int i =0; i<cols; i++){
            printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
        }
        printf("\n");
        if(j % 8 == 7){
            printf("\n");
        }    
    }
    bool blocks2[2*8][3]={
        {0,0,0},
        {1,1,1},
        {0,1,1},
        {0,0,0},
        {0,1,1},
        {0,0,1},
        {0,0,1},
        {1,0,1},
        {0,0,0},
        {1,0,0},
        {1,0,0},
        {0,0,0},
        {1,0,0},
        {0,0,0},
        {1,0,0},
        {0,0,0}
    };
   /* bool bytes2[length][8];*/
    blocks_to_bytes(3,2, blocks2, length, bytes2);
    for(int j =0; j< length; j++){
        for(int i = 0; i< 8;i++){
            printf("%d", bytes2[j][i]);
        }
        printf("\n");
    }

    return 0;
}

//definition
//task_1
void encode_char(const char character, bool bits[8]){
    char t = character;
    short i=7;
    F(;i>=0;i=i-1){ 
    bits[i] = t & 1;
    t>>=1;
    }  
} 
char decode_byte(const bool bits[8]){
    char result = 0;
    short i=0;
    F(; i<8;++i){
        result =(result << 1)|bits[i];
    }
    short o;
    o=6;
    FI(o != 6){
    R 1;
    }
    R result;
}    
//task_2
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    short len = strlen(string);
    short l= 223;
    FI(l==223){
        short i=0;
        F(; i< len; ++i){
            char ch = string[i];
            short j = 0;
            F(; j<8; ++j){
                bytes[i][j]= (ch >>(7-j)) &1;
            }
         }
    }
    short j=0;
    F(; j< 8; ++j){
        bytes[len][j]=0;
    }
}    
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    short l1 = rows;
    short l2 = rows+1;
    FI(l2 > 0){
        short i =0;
        F(;i<l1; i=i+1){
            char result = 0;
            short j=0;
            F(;j<8; j=j+1){
                result = (result << 1) | bytes[i][j];
            }    
            string[i] = result;
        }    
    }    
}
//task_3
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    short i=0;
    FI(i != 0){
        short k=2;
        short w =9;
        short r3= k+w;
        printf("%d",r3);
    }
    F(;i<cols;i=i+1){
        short j=0;
        F(;j<offset*8; j=j+1){
            blocks[j][i]=0;
        }
    }
    short u=0;
    FI(u != 0){
        short n =3;
        short e =7;
        short r2= e-n;
       printf("%d",r2);
    }
    F(; u<rows; u=u+1){
        short j=0;
        F(;j<8;j=j+1){
            blocks[j+8*(u/cols)][u%cols]=bytes[u][j];
        }
    }
    short s=4;
    FI(s != 4){
        short f=1;
        short r1= f*3;
        printf("%d",r1);
    }
}
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows , bool bytes[rows][8]){
    short i=0;
    F(; i<offset; i++){
        short r=0;
        F(; r< cols; r++){
            short s=0;
            F(; s<8; s++){
                short k =4;
                FI(r+i*cols<rows&&  k == 4){
                    short m = 6;
                    FI(blocks[s+(i*8)][r] && m == 6){
                        bytes[r+(i*cols)][s]=true;
                    }
                        else{
                            bytes[r+(i*cols)][s]=false;
                        }
                    }
                short c = 8;
                FI(r+i*cols>rows && c == 8){
                    bytes[r+(i*cols)][r]= false;
                }
            }
        }
    }
    short x =1;
    short v =7;
    FI(x !=1 || v !=7){
        short xv = v-x*1+0;
        printf("%d", xv);
    }
}


///
