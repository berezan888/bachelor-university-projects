#include <stdio.h>
#include "bmp.h"
#include "transformations.h"
#include <stdlib.h>

int main() {
    FILE* input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return EXIT_FAILURE;
    }
    struct bmp_image* input_image = read_bmp(input_file);
    fclose(input_file);
    if (input_image == NULL) {
        fprintf(stderr, "Error: Unable to read input BMP file.\n");
        return EXIT_FAILURE;
    }
    struct bmp_image* flipped_horizontally = flip_horizontally(input_image);
    struct bmp_image* flipped_vertically = flip_vertically(input_image);
    struct bmp_image* rotated_left = rotate_left(input_image);
    struct bmp_image* rotated_right = rotate_right(input_image);
    struct bmp_image* extracted = extract(input_image, "rgb");
    FILE* flipped_horizontally_file = fopen("flipped_horizontally.bmp", "wb");
    if (flipped_horizontally_file == NULL) {
        fprintf(stderr, "Error: Unable to create output file for horizontally flipped image.\n");
        return EXIT_FAILURE;
    }
    write_bmp(flipped_horizontally_file, flipped_horizontally);
    fclose(flipped_horizontally_file);
    FILE* flipped_vertically_file = fopen("flipped_vertically.bmp", "wb");
    if (flipped_vertically_file == NULL) {
        fprintf(stderr, "Error: Unable to create output file for vertically flipped image.\n");
        return EXIT_FAILURE;
    }
    write_bmp(flipped_vertically_file, flipped_vertically);
    fclose(flipped_vertically_file);

    FILE* rotated_left_file = fopen("rotated_left.bmp", "wb");
    if (rotated_left_file == NULL) {
        fprintf(stderr, "Error: Unable to create output file for left rotated image.\n");
        return EXIT_FAILURE;
    }
    write_bmp(rotated_left_file, rotated_left);
    fclose(rotated_left_file);

    FILE* rotated_right_file = fopen("rotated_right.bmp", "wb");
    if (rotated_right_file == NULL) {
        fprintf(stderr, "Error: Unable to create output file for right rotated image.\n");
        return EXIT_FAILURE;
    }
    write_bmp(rotated_right_file, rotated_right);
    fclose(rotated_right_file);

    FILE* extracted_file = fopen("extracted.bmp", "wb");
    if (extracted_file == NULL) {
        fprintf(stderr, "Error: Unable to create output file for extracted image.\n");
        return EXIT_FAILURE;
    }
    write_bmp(extracted_file, extracted);
    fclose(extracted_file);
    free_bmp_image(input_image);
    free_bmp_image(flipped_horizontally);
    free_bmp_image(flipped_vertically);
    free_bmp_image(rotated_left);
    free_bmp_image(rotated_right);
    free_bmp_image(extracted);

    return EXIT_SUCCESS;
}

