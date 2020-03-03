#include <stdio.h>
#include "color.h"
#include "image.h"
#include "ppm.h"

int main(){
	struct ppm p = PPM_new("merida.ppm"); // reads the file and puts everything in p
	int nbpixels = PPM_nbPixels(p);
	struct color *img = PPM_pixels(p);    // img is the color array

	//TODO...
	PPM_save(p,img,"res.ppm"); // saves the result in res.ppm

	return 0;
}
