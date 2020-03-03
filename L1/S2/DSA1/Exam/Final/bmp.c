#include "bmp.h"
#include <string.h>


// reads important data into a struct and points img_file to image file in memory
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
    img->pxl_offset     = *((unsigned int *)   &imagefile[10]);
    img->width          = *((unsigned int *)   &imagefile[18]);
    img->height         = *((unsigned int *)   &imagefile[22]);
    img->bits_per_pixel = *((unsigned short *) &imagefile[28]);

    *img_file = imagefile;                                   // set the pointer to image
    return img;
}


// checks to see whether string is a valid number - needed for a check in BMP_args_check
bool is_number(char *s){
	for(int i=0;s[i] != '\0';i++){
		if(s[i] == '0' ||
		   s[i] == '1' ||
		   s[i] == '2' ||
		   s[i] == '3' ||
		   s[i] == '4' ||
		   s[i] == '5' ||
		   s[i] == '6' ||
		   s[i] == '7' ||
		   s[i] == '8' ||
		   s[i] == '9' )
		   continue;
		else
			return true;
	}
	return false;
}

// checks args and file signature, prints usage if needed
bool BMP_args_check(int argc, char **argv){

    // user requested help
    if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        printf("Usage: ./extractStrip -width filename\n");
        return false;
    }

    else if(argc < 3) {
        fputs("[!] Too few arguments.\n", stderr);
        printf("Usage: ./extractStrip -width filename\n");
        return false;
    }
    else if(argc > 3) {
        fputs("[!] Too many arguments.\n", stderr);
        printf("Usage: ./extractStrip -width filename\n");
        return false;
    }

    else{
        if( strlen(argv[2]) > 4 && strcmp(&argv[2][strlen(argv[2])-4], (const char*)&".bmp") ) {
            fputs("[!] Wrong extension: expected '.bmp'\n", stderr);
        }
        char buff[3];
        FILE *fp = fopen(argv[2], "r");
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

        // checking the width argument
        if(argv[1][0] != '-'){
            printf("Usage: ./extractStrip -width filename\n");
            return false;
        }
        
        // checking whether the entered width is a number
        if(is_number(&argv[1][1])){
        	fputs("[!] Width argument not a number\n", stderr);
        	printf("Usage: ./extractStrip -width filename\n");
            return false;
        }
    }
    return true;
}


// kind of a "god function", does what its title says it
void BMP_cut_strip_and_save(bmp_file *img, byte *img_file, int strip_width, char *strip_name){

    // calculate padding values
    int strip_padding = ((strip_width*(img->bits_per_pixel/8)) % 4) == 0 ? 0 : 4 - ((strip_width*(img->bits_per_pixel/8)) % 4);
    int img_padding = ((img->width*(img->bits_per_pixel/8)) % 4) == 0 ? 0 : 4 - ((img->width*(img->bits_per_pixel/8)) % 4);

    int strip_size = img->pxl_offset + img->height*(strip_width*(img->bits_per_pixel/8) + strip_padding);

    // The images of the pot actually used a BITMAPV5HEADER (hence 124 bit DIB header size) so the program
    // saves strips using this header too. We will be allocating needed bytes per pixel in malloc for strip.
    byte *strip = malloc(strip_size);

    memcpy(strip, img_file, img->pxl_offset);         // copy header from input image to output image

    // modifying necessary fields
    *((unsigned int *) &strip[2])  = strip_size;
    *((unsigned int *) &strip[10]) = img->pxl_offset;
    *((unsigned int *) &strip[18]) = strip_width;
    *((unsigned int *) &strip[34]) = img->height * strip_width * (img->bits_per_pixel/8);

	// creating a pointer to start of strip in pixel array in input image, for ease of use
	byte *pxl = &img_file[ img->pxl_offset + (img->width - strip_width)/2*(img->bits_per_pixel/8) ];
	
    // copying needed pixels from middle of each row
    for(int i=0; i<img->height; i++){
    	memcpy(&strip[img->pxl_offset + i*(strip_width*(img->bits_per_pixel/8)+strip_padding)], pxl, strip_width*(img->bits_per_pixel/8));
        pxl += img->width*(img->bits_per_pixel/8) + img_padding;
    }

    // writing the strip to a file
    FILE *output_file = fopen(strip_name, "wb");
    fwrite(strip, strip_size, 1, output_file);

    fclose(output_file);

    free(strip);
}


// mainly for debugging, not necessary for user to know
void BMP_print_summary(bmp_file *img){
    printf("%-12s : %.2f MiB\n", "file size", (float) img->size / (1024 * 1024));
    printf("%-12s : %u\n", "header size", img->pxl_offset);
    printf("%-12s : %u\n", "width", img->width);
    printf("%-12s : %u\n", "height", img->height);
    printf("%-12s : %hu\n\n", "bits/pixel", img->bits_per_pixel);
}
