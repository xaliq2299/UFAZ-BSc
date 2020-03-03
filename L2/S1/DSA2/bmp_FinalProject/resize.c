#include "bmp.h"
#include <string.h>

int main(int argc, char **argv){
	if(!BMP_args_check(argc, argv)) return -1;         // if something is wrong with the arguments or file itself, exit
	char *filename = argv[1];                          // the first argument is our filename

	// generating resized file name
	char *resized = "Resized.bmp";
	char *targetFileName = malloc(strlen(filename) + strlen(resized));    
	strcpy(targetFileName, filename);
	strcpy(&targetFileName[strlen(targetFileName)-4], resized);

    // Step 0: preparing the target file to resize
	byte *fSource, *fTarget;
	float maxPSF = findPSF(0); // maximal Pixel Scaling Factor: corresponds to the top of an image
	bmp_file *img = BMP_read(filename, &fSource); // read needed info into a bmp_file struct
	//BMP_print_summary(img);

	// writing the important parameters of fTarget (read from fSource)
	// the only important change will be width, which will also affect to few other parameters
	int target_width = img->width*maxPSF;
	int img_padding = ((img->width*(img->bits_per_pixel/8)) % 4) == 0 ? 0 : 4 - ((img->width*(img->bits_per_pixel/8)) % 4); // calculate padding
	int header_size = img->pxl_offset; // 14 + 40 bytes for BMP and DIB headers
	int target_size = header_size+img->height*(target_width*(img->bits_per_pixel/8)+img_padding); // the size of a new resized bmp file
	
	fTarget = malloc(sizeof(byte)*(target_size)); // allocate enough space for fTarget
	fTarget[0] = 'B'; fTarget[1] = 'M'; // the signature of BitMap
	*((unsigned int *) &fTarget[2]) = target_size; // the size of the whole bmp file
	*((unsigned int *) &fTarget[10]) = header_size; // the size of BMP (1st) and DIB (2nd) headers
	*((unsigned int *) &fTarget[14]) = 40; // the size of the DIB (2nd) header
	*((unsigned int *) &fTarget[18]) = target_width; // the width (updated) of a new target bmp file
	*((unsigned int *) &fTarget[22]) = img->height; // the height of a bmp file (not changed)
	*((unsigned short *) &fTarget[26]) = 1;	// number of color planes
	*((unsigned short *) &fTarget[28]) = img->bits_per_pixel; // needed bits to store one pixel
	*((unsigned int *) &fTarget[30]) = 0; // BI_RGB, no pixel array compression used
	*((unsigned int *) &fTarget[34]) = target_size-header_size; // Size of the raw bitmap data (including padding)

	// Step 1: Resizing
	for(int line=img->height-1;line>=0;line--){
		float per, cur, PSF=findPSF(line); // per stands for percentage
		int counter = img->pxl_offset+(img->height-1-line)*4*target_width;
		// the 1st pixel's RGB values + alpha mask
		fTarget[counter++] = fSource[img->pxl_offset+line*4*img->width];
		fTarget[counter++] = fSource[img->pxl_offset+line*4*img->width+1];
		fTarget[counter++] = fSource[img->pxl_offset+line*4*img->width+2];
		fTarget[counter++] = fSource[img->pxl_offset+line*4*img->width+3];
		// the following pixels
		for(int pxlCounter=1;pxlCounter<img->width*PSF;pxlCounter++){
			// finding the percentages: cur stands for current percentage
			if(PSF-per > 1)	{ cur = 1; per+=1; }
			else			{ cur=PSF-per; per=1-cur; }
			// finding fTarget pixels as the weighted sum of fSource pixels (we have for loop 4 times bcz of RGB values + alpha mask)
			for(int h=0;h<4;h++){
				float temp = (float)pxlCounter/PSF; // was important to do bcz of the index problem in array
				fTarget[counter++] = fSource[img->pxl_offset+line*4*img->width+4*(int)temp+h]*cur+
									 fSource[img->pxl_offset+line*4*img->width+4*(int)temp+4+h]*(1-cur);
			}
		}
	}
	
	// Step 2: Centering the lines
	for(int line=img->height-1;line>=0;line--){
		float PSF=findPSF(line);
		int shifting=(target_width-PSF*img->width)/2;
		if(shifting == 0) continue; // to save time
		int counter = img->pxl_offset+(img->height-1-line)*4*target_width+PSF*img->width*4;
	
		for(int i=img->pxl_offset+(img->height-1-line)*4*target_width+4*(shifting+img->width*PSF);i>img->pxl_offset+(img->height-1-line)*4*target_width+4*shifting;i--){
			fTarget[i] = fTarget[counter];
			fTarget[counter--] = 0;
		}
	}

	// writing fTarget to a resized_file
	FILE *resized_file = fopen(targetFileName, "wb");
	fwrite(fTarget, target_size, 1, resized_file);
	fclose(resized_file);

	free(fTarget);
	free(targetFileName);
	free(img);

    return 0;
}