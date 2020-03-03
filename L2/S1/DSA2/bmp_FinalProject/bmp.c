#include "bmp.h"

bmp_file *BMP_read(char *filename, byte **img_file){
    bmp_file *img = malloc(sizeof * img);
    FILE *fp = fopen(filename, "rb");

    fseek(fp, 2, SEEK_SET);                                  // skip first 2 bytes: signature
    fread(&img->size, sizeof img->size, 1, fp);              // read size of file
    byte *imagefile = malloc(img->size);                     // allocate enough space for the whole file
    fseek(fp, 0, SEEK_SET);                                  // go back to the start of the file
    fread(imagefile, img->size, 1, fp);                      // read the image to array
    fclose(fp);

    // read necessary information from image header
    img->pxl_offset     =  *((unsigned int *)   &imagefile[10]);
    img->width          =  *((unsigned int *)   &imagefile[18]);
    img->height         = -*((unsigned int *)   &imagefile[22]);
    img->bits_per_pixel =  *((unsigned short *) &imagefile[28]);

    *img_file = imagefile;                                   // set the pointer to image
    return img;
}

bool BMP_args_check(int argc, char **argv){
    // user requested help
    if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        printf("Usage: ./resize filename\n");
        return false;
    }

    else if(argc < 2) {
        fputs("[!] Too few arguments.\n", stderr);
        printf("Usage: ./resize filename\n");
        return false;
    }
    else if(argc > 2) {
        fputs("[!] Too many arguments.\n", stderr);
        printf("Usage: ./resize filename\n");
        return false;
    }

    else{
        if( strlen(argv[1]) > 4 && strcmp(&argv[1][strlen(argv[1])-4], (const char*)&".bmp") ) {
            fputs("[!] Wrong extension: expected '.bmp'\n", stderr);
        }
        char buff[3];
        FILE *fp = fopen(argv[1], "r");
        if(!fp){
            fputs("[!] Couldn't open file\n", stderr);
            return false;
        }
        fread(buff, sizeof *buff *2, 1, fp);
        if(buff[0] != 'B' || buff[1] != 'M'){
            fputs("[!] Wrong file signature\n", stderr);
            return false;
        }
        fclose(fp);    
    }
    return true;
}

void BMP_print_summary(bmp_file *img){
    printf("%-12s : %.2f MiB\n", "file size", (float) img->size / (1024 * 1024));
    printf("%-12s : %u\n", "header size", img->pxl_offset);
    printf("%-12s : %u\n", "width", img->width);
    printf("%-12s : %u\n", "height", img->height);
    printf("%-12s : %hu\n\n", "bits/pixel", img->bits_per_pixel);
}

float findPSF(int height){
	return 74/(sqrt(height)+25);
}