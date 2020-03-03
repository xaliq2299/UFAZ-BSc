#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

#define PGM_MAX 300

struct ppm
{
	FILE *ppmfile;
	int width, height, nbpixels;
	struct color *pixels;
};

void PPM_check(struct ppm p, char *message);

// Given the path of a ppm image file, this function
// reads this file and stores the information in a ppm structure

struct ppm PPM_new(char *ppmfilepath);

// Given a ppm structure initialized by PPM_new,
// PPM_nbPixels returns the number of pixels in the file

int  PPM_nbPixels(struct ppm p);

// Given a ppm structure initialized by PPM_new,
// PPM_pixels returns an array of integers representing the
// pixels of the image in this order : r1 g1 b1 r2 g2 b2 ...

struct color* PPM_pixels(struct ppm p);

// Given a ppm structure initialized by PPM_new,
// and an array of integers representing the pixels of an image
// in this order : r1 g1 b1 r2 g2 b2 ...
// PPM_save saves this new file (with the same width and height)
// the file whose path is given in the outputfile parameter

void PPM_save(struct ppm p, struct color *image, char *outputfile);
