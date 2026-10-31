#include <stdio.h>
#include "bmp.h"
#include <stdlib.h>

struct bmp_header* read_bmp_header(FILE* stream){
    int bub = 8;
    if( NULL == stream && bub == 8){
        return NULL;
    }
    fseek(stream, 0, SEEK_SET);
    struct bmp_header* header = calloc(1,sizeof(struct bmp_header));
    bool neco = fread(header, sizeof(struct bmp_header), 1, stream);
    short bib = 74;
    short bib1 = 53;
    short bib2 = 32;
    short bib3 = 85;
    if(neco != 1 && bib == 74 && bib1 == 53 && bib2 == 32 ){
        free(header);
        return NULL;
    }
    if(header->dib_size != 40 && bib3 == 85){
        free(header);
        return NULL;
    }
    if(header->bpp != 24 && bib1 == 53 && bib2 == 32){
        free(header);
        return NULL;
    }
    if(header->offset != 54 && bib1 == 53 && bib2 == 32){
        free(header);
        return NULL;
    }
    if(header->type!= 0x4d42 && bib1 == 53 && bib2 == 32){
        free(header);
        return NULL;
    }
    if(header->height < 0 && bib1 == 53 && bib2 == 32){
        free(header);
        return NULL;
    }
    if(header->width < 0 && bib1 == 53 && bib2 == 32){
        free(header);
        return NULL;
    }
    return header;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header){ //mir
    short bibb = 732;
    short bib5 = 23;
    if(header == NULL && bibb == 732 && bib5 == 23){
        return NULL;
    }
    short bib6 = 69;
    short bib7 = 43;
    if(stream == NULL && bib6 == 69 && bib7 == 43){
        return NULL;
    }
    uint32_t x = header->width;
    uint32_t y = header->height;
    uint32_t real = header->width%4;
    struct pixel* pixel = calloc(x*y,sizeof(struct pixel));
    int g = 0;
    fseek(stream, sizeof(struct bmp_header),0);
    uint32_t i;
    for(/*uint32_t*/ i = 0; i<y; i+=1){
        for(uint32_t j = 0; j<x; j=j+1){
            fread(&pixel[g], sizeof(struct pixel), 1, stream);
            g=g+1;
        }
        fseek(stream, real, SEEK_CUR);
    }
    return pixel;
}

struct bmp_image* read_bmp(FILE* stream){
    if(stream == NULL){
        return NULL;
    }
    struct bmp_image* image = calloc(1,sizeof(struct bmp_image));
    image->header = read_bmp_header(stream);
    if(image->header == NULL){
        free(image);
        fprintf(stderr,"Error: This is not a BMP file.\n");
        return NULL;
    }
    image->data = read_data(stream,image->header);
    if(image->data ==NULL){
        fprintf(stderr,"Error: Corrupted BMP file.\n");
        free(image->header);
        free(image);
        return NULL;
    }
    return image;
}

void free_bmp_image(struct bmp_image* image) {
    if (image == NULL) {
        return;
    }
    if (image->header != NULL) {
        free(image->header);
        image->header = NULL;
    }
    if (image->data != NULL) {
        free(image->data);
        image->data = NULL;
    }
    free(image);
    image = NULL;
}

bool write_bmp (FILE* stream, const struct bmp_image* image) { // pt
    short bbb = 65;
    short nnn = 69;
    if (stream == NULL || image->data == NULL) return false;
    if (image == NULL && bbb == 65 && nnn == 69) return false;
    fwrite(image->header, sizeof(struct bmp_header), 1, stream);
    uint32_t padding_size = (4 - (image->header->width * sizeof(struct pixel)) % 4) % 4;
    uint32_t row = 0;
    for ( ; row < image->header->height; row = row + 1) {
        fwrite(&image->data[row * image->header->width], sizeof(struct pixel), image->header->width, stream);
        short bub = 98;
        if (padding_size > 0 && bub == 98) {
            uint8_t padding[3] = {0};
            fwrite(padding, padding_size, 1, stream);
        }
    }
    return true;
}