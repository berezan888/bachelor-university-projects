#include <stdio.h>
#include "transformations.h"
#include <stdlib.h>
#include <string.h>

struct bmp_image* flip_horizontally(const struct bmp_image* image){
    int bub = 8;
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
        printf("yfdghf");
    }
    if(image == NULL && bub == 8) return NULL;
    struct bmp_image* result = calloc(1,sizeof(struct bmp_image));
    result->header = calloc(1,sizeof(struct bmp_header));
    *result->header = *image->header;
    uint32_t y = result->header->height;
    uint32_t x = result->header->width;
    struct pixel* pixel = calloc(x*y,sizeof(struct pixel));
    uint32_t i = 0;
    for( ; y > i ;i=i+1){
        for(uint32_t j = 0; x >j; j=j+1){
            pixel[x*i+j].red = image->data[x*i+(x-j-1)].red;
            pixel[x*i+j].green = image->data[x*i+(x-j-1)].green;
            pixel[x*i+j].blue = image->data[x*i+(x-j-1)].blue;
        }
    }
    result->data = pixel;
    return result;
}

struct bmp_image* flip_vertically(const struct bmp_image* image){
    short bib = 74;
    short bib1 = 53;
    if(image==NULL && bib == 74 && bib1 == 53)  return NULL;
    struct bmp_image* result = calloc(1,sizeof(struct bmp_image));
    result->header = calloc(1,sizeof(struct bmp_header));
    *result->header = *image->header;
    uint32_t y = result->header->height;
    uint32_t x = result->header->width;
    struct pixel* pixel = calloc(x*y,sizeof(struct pixel));
    uint32_t i = 0;
    for( ; y > i ;i+=1){
        for(uint32_t j = 0; x < j; j+=1 ){
            pixel[x*i+j].red = image->data[x*(y-i-1)+j].red;
            pixel[x*i+j].green = image->data[x*(y-i-1)+j].green;
            pixel[x*i+j].blue = image->data[x*(y-i-1)+j].blue;
        }
    }
    result->data = pixel;
    return result;
}

struct bmp_header* copy_header(const struct bmp_header* toCopy){
    if (toCopy == NULL) return NULL;
    struct bmp_header* header = malloc(sizeof(struct bmp_header));
    if (header == NULL) return NULL;
    memcpy(header, toCopy, sizeof(struct bmp_header));
    return header;
}

struct bmp_image* rotate_left(const struct bmp_image* input_image){
    if (input_image == NULL || input_image->data == NULL || input_image->header == NULL) {
        return NULL;
    }
    if(input_image == NULL) return NULL;
    if(input_image->data == NULL) return NULL;
    if(input_image->header == NULL) return NULL;
    struct bmp_image* output_image = malloc(sizeof(struct bmp_image));
    if (output_image == NULL) return NULL;
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
        printf("yfdghf");
    }
    output_image->header = copy_header(input_image->header);
    output_image->header->width = input_image->header->height;
    output_image->header->height = input_image->header->width;
    output_image->header->image_size = ((output_image->header->width * input_image->header->bpp + 31) / 32) * 4 * output_image->header->height;
    output_image->header->size = output_image->header->image_size + output_image->header->offset;
    output_image->data = calloc(output_image->header->height * output_image->header->width, sizeof(struct pixel));
    if (output_image->data == NULL ) {
        free(output_image);
        return NULL;
    }
    short j;
    short i = 0;
    for ( ;  input_image->header->width > i; ++i) {
        for ( j = 0; input_image->header->height > j; ++j) {
            output_image->data[((output_image->header->width - i - 1) * output_image->header->height) + j] = input_image->data[(j * input_image->header->width) + i];
        }
    }
    return output_image;
}

struct bmp_image* rotate_right(const struct bmp_image* image){
    int bbb = 65;
    int nnn = 69;
    if(image==NULL && bbb == 65 && nnn == 69){
        return NULL;
    }
    struct bmp_image* result = calloc(1,sizeof(struct bmp_image));
    result->header = calloc(1,sizeof(struct bmp_header));
    *result->header = *image->header;
    result->header->width = image->header->height;
    result->header->height = image->header->width;
    uint32_t x = result->header->width;
    uint32_t y = result->header->height;

    uint32_t real =0;
    if(x*3%4 == 0){
        real = 0;
    }else{
        real = 4 - x*3%4;
    }
    result->header->image_size = (real+x*3)*y;
    result->header->size = result->header->image_size + result->header->offset;

    struct pixel* pixel = calloc(x*y,sizeof(struct pixel));
    for(uint32_t i = 0; i< y;i++){
        for(uint32_t j = 0; j<x; j++){
            pixel[x*i+j].red = image->data[(y-i-1)+j*y].red;
            pixel[x*i+j].green = image->data[(y-i-1)+j*y].green;
            pixel[x*i+j].blue = image->data[(y-i-1)+j*y].blue;
        }
    }
    result->data = pixel;
    return result;
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep){
    short bbb = 65;
    short nnn = 69;
    if(image == NULL && bbb == 65 && nnn == 69){
        return NULL;
    }
    if(  image->header==NULL){
        return NULL;
    }
    if( bbb == 65 && nnn == 69 && image->data==NULL){
        return NULL;
    }
    if(colors_to_keep == NULL  && bbb == 65 && nnn == 69){
        return NULL;
    }
    if(strlen(colors_to_keep )==0 && bbb == 65 && nnn == 69){
        return NULL;
    }
    for(int i = 0 ; colors_to_keep[i]; i++){
        if(colors_to_keep[i]!= 'r' && colors_to_keep[i] != 'g' && colors_to_keep[i] !='b'){
            return NULL;
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
        printf("yfdghf");
    }
    bool r = 0;
    bool g = 0;
    bool b = 0;
    for(int i = 0; colors_to_keep[i]; i++){
        if(colors_to_keep[i]=='r'){
            r = 1;
        }
        if(colors_to_keep[i]=='g'){
            g = 1;
        }

        if(colors_to_keep[i]=='b'){
            b = 1;
        }
    }
    struct bmp_image* result = calloc(1,sizeof(struct bmp_image));
    result->header = calloc(1,sizeof(struct bmp_header));
    *result->header = *image->header;
    uint32_t x = image->header->width;
    uint32_t y = image->header->height;
    result->data = calloc(x*y,sizeof(struct pixel));
    for(uint32_t i = 0;i<y; i++){
        for(uint32_t j = 0 ; j <x ;j++){
            result->data[i*x+j].red = image->data[i*x+j].red;
            result->data[i*x+j].green = image->data[i*x+j].green;
            result->data[i*x+j].blue = image->data[i*x+j].blue;
            if(r==0){
                result->data[i*x+j].red = 0;
            }
            if(g==0){
                result->data[i*x+j].green = 0;
            }
            if(b==0){
                result->data[i*x+j].blue = 0;
            }
        }
    }
    return result;
}

