#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define RESIZED_STRIP_WIDTH 82 // the width that's extracted from resized files

typedef unsigned char byte;

typedef struct bmpfile{
    unsigned int size;              // size of file in bytes
    unsigned int pxl_offset;        // file offset to pixel array
    unsigned int width;             // image width
    unsigned int height;            // image height
    unsigned short bits_per_pixel;  // # of bits per pixel
} bmp_file;

bmp_file *BMP_read(char *filename, byte **img_file); // reads important data into a struct and points img_file to image file in memory
bool BMP_args_check(); // checks args and file signature, prints usage if needed
void BMP_print_summary(bmp_file *img); // for some debugging process
float findPSF(int height); // finds Pixel Scaling Factor for each line according to the evolving radius formula (approximate solution)

#endif
