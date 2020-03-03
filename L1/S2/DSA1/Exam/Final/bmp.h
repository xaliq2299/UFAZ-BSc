#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char byte;

typedef struct bmpfile{
    unsigned int size;              // size of file in bytes
    unsigned int pxl_offset;        // file offset to pixel array
    unsigned int width;             // image width
    unsigned int height;            // image height
    unsigned short bits_per_pixel;  // # of bits per pixel
} bmp_file;

bmp_file *BMP_read(char *filename, byte **img_file);
bool BMP_args_check();
void BMP_cut_strip_and_save(bmp_file *img, byte *img_file, int strip_width, char *strip_name);
void BMP_print_summary(bmp_file *img);

#endif
