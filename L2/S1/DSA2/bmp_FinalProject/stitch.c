#include <stdio.h>
#include "bmp.h"

// this is the function that gets as an argument a filename and returns the filename consecutive to it
char* nextFileName(int fileCounter, char *filename){
	if(fileCounter<=9)
		filename[12]=fileCounter+'0'; // converting integer digit to character
	else if(fileCounter==10){
		// shifting characters
		for(int i=strlen(filename)-1;i>=strlen(filename)-16;i--)
			filename[i+1]=filename[i];
		
		filename[12]=fileCounter/10+'0'; // converting integer digit to character
		filename[13]=fileCounter%10+'0'; // converting integer digit to character
	}
	else if(fileCounter>10 && fileCounter<=99){
		filename[12]=fileCounter/10+'0'; // converting integer digit to character
		filename[13]=fileCounter%10+'0'; // converting integer digit to character	
	}
	else if(fileCounter==100){
		// shifting characters
		for(int i=strlen(filename)-1;i>=strlen(filename)-16;i--)
			filename[i+1]=filename[i];

		filename[12]=fileCounter/100+'0'; // converting integer digit to character
		filename[13]=(fileCounter/10)%10 +'0'; // converting integer digit to character
		filename[14]=fileCounter%10 +'0'; // converting integer digit to character
	}
	else{
		filename[12]=fileCounter/100+'0'; // converting integer digit to character
		filename[13]=(fileCounter/10)%10 +'0'; // converting integer digit to character
		filename[14]=fileCounter%10 +'0'; // converting integer digit to character
	}
	return (char*)filename;
}

int main(){
	int nbIMGs=361, flattened_width=RESIZED_STRIP_WIDTH*nbIMGs, fileCounter=1, flattened_size;
	char *filename = malloc(sizeof(char)*35);
	strcpy(filename, "AzCroppedPot1Resized_S82.bmp");
	
	// the 2 following commented lines were only for 16 strips that had to be stitched before we test on all 360 images
	//nbIMGs=16; flattened_width=RESIZED_STRIP_WIDTH*nbIMGs; fileCounter=25;
	//strcpy(filename, "AzCroppedPot25Resized_S82.bmp");

	flattened_size=54+2230*(flattened_width*(32/8)); // header_size+img->height*(target_width*(img->bits_per_pixel/8));
	
	byte *fImg, *fFlattened;
	FILE *fp = fopen("flattenedPot.bmp", "wb");
	fFlattened = malloc(sizeof(byte)*(flattened_size)); // allocate enough space 
	fFlattened[0] = 'B'; fFlattened[1] = 'M'; // the signature of BitMap
	*((unsigned int *) &fFlattened[2]) = flattened_size; // the size of the whole bmp file
	*((unsigned int *) &fFlattened[10]) = 54; // the size of BMP (1st) and DIB (2nd) headers
	*((unsigned int *) &fFlattened[14]) = 40; // the size of the DIB (2nd) header
	*((unsigned int *) &fFlattened[18]) = flattened_width; // the width (updated) of a new flattened bmp file
	*((unsigned int *) &fFlattened[22]) = 2230; // the height of a flattened bmp file (not changed)
	*((unsigned short *) &fFlattened[26]) = 1;	// number of color planes
	*((unsigned short *) &fFlattened[28]) = 32; // needed bits to store one pixel
	*((unsigned int *) &fFlattened[30]) = 0; // BI_RGB, no pixel array compression used
	*((unsigned int *) &fFlattened[34]) = flattened_size-54; // Size of the raw bitmap data (including padding)
	
	for(int iFile=0;iFile<nbIMGs;iFile++){
		printf("\t%s\n", filename);
		BMP_read(filename, &fImg);

		for(int line=2229;line>=0;line--){
			int counter=54+(2229-line)*flattened_width*4+4*RESIZED_STRIP_WIDTH*iFile;
			for(int h=54+(2229-line)*RESIZED_STRIP_WIDTH*4;h<54+(2229-line)*RESIZED_STRIP_WIDTH*4+RESIZED_STRIP_WIDTH*4;h++)
				fFlattened[counter++]=fImg[h];
		}
	    fileCounter++;
		filename = nextFileName(fileCounter,filename);
	}

	fwrite(fFlattened, flattened_size, 1,fp);
	fclose(fp);

	free(filename);
	free(fFlattened);

	return 0;
}