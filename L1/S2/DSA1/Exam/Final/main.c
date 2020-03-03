#include <string.h>
#include "bmp.h"


int main(int argc, char **argv){

    if(!BMP_args_check(argc, argv)) return 1;         // if something is wrong with the arguments or file itself, exit

    int strip_width  = atoi(&argv[1][1]);
    char *filename   = argv[2];                       // parse the args

    // all of this is just to generate output file name
    char wdth[12];
    sprintf(wdth, "_S%d.bmp", strip_width);
    char *strip_name = malloc(strlen(filename) + strlen(wdth));    
    strcpy(strip_name, filename);
    strcpy(&strip_name[strlen(strip_name)-4], wdth);

    byte *img_pixels;
    bmp_file *img = BMP_read(filename, &img_pixels);               // read needed info into a bmp_file struct
    //BMP_print_summary(img);

	// check whether the strip_width is positive and actually fits in image
    if(strip_width >= img->width){
        fputs("[!] Strip width is too large.\n", stderr);
        return 2;
    }
    if(strip_width <= 0){
        fprintf(stderr, "[!] Bad strip width: %d\n", strip_width);
        return 3;
    }

    BMP_cut_strip_and_save(img, img_pixels, strip_width, strip_name);
    
    free(img_pixels);
	free(strip_name);
    free(img);

    return 0;
}
