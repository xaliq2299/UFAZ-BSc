#include "ppm.h"

void PPM_check(struct ppm p, char *message)
{
	int n;
	printf("width    : %d\n",p.width);
	printf("height   : %d\n",p.height);
	printf("nbpixels : %d\n",p.nbpixels);

	for(n=0;n<p.nbpixels;n++)
		C_print(p.pixels[n]);

	printf("\n");
}

//-----------------------------------------------------------
// Given the path of a ppm image file, this function
// reads this file and stores the information in a ppm structure

struct ppm PPM_new(char *ppmfilepath)
{
	struct ppm ppm_new;
	char dump[300], command[300];
	int n;

	sprintf(command,"cat %s | grep -v \\# > ppmdumppppp",ppmfilepath);
	// printf("command = %s\n",command);
	system(command); // In order to eliminate comments

	ppm_new.ppmfile = fopen("ppmdumppppp","r");
	if(ppm_new.ppmfile==NULL)
	{
		perror(ppmfilepath);
		exit(1);
	}
	else
	{
		fscanf(ppm_new.ppmfile,"%s",dump);
		if(strcmp(dump,"P3")!=0)
		{
			printf("File %s is not a ppm file.\n",ppmfilepath);
			exit(1);
		}
		else
		{
			fscanf(ppm_new.ppmfile,"%s",dump);
			ppm_new.width = atoi(dump);

			fscanf(ppm_new.ppmfile,"%s",dump);
			ppm_new.height = atoi(dump);

			fscanf(ppm_new.ppmfile,"%s",dump);
			ppm_new.nbpixels = ppm_new.width * ppm_new.height;

			ppm_new.pixels = (struct color*)calloc(ppm_new.nbpixels,sizeof(struct color));

			for(n=0;n<ppm_new.nbpixels;n++)
			{
				int r,g,b;

				fscanf(ppm_new.ppmfile,"%s",dump);
				r = atoi(dump);

				fscanf(ppm_new.ppmfile,"%s",dump);
				g = atoi(dump);

				fscanf(ppm_new.ppmfile,"%s",dump);
				b = atoi(dump);

				ppm_new.pixels[n] = C_new(r,g,b);
			}
			// PPM_check(ppm_new,"init");
		}
		fclose(ppm_new.ppmfile);
		system("rm ppmdumppppp");
	}

	return(ppm_new);
}

//-----------------------------------------------------------
// Given a ppm structure initialized by PPM_new,
// PPM_nbPixels returns the number of pixels in the file

int  PPM_nbPixels(struct ppm p)
{
	return(p.nbpixels);
}


//-----------------------------------------------------------
// Given a ppm structure initialized by PPM_new,
// PPM_pixels returns an array of integers representing the
// pixels of the image in this order : r1 g1 b1 r2 g2 b2 ...

struct color* PPM_pixels(struct ppm p)
{
	return(p.pixels);
}


//-----------------------------------------------------------
// Given a ppm structure initialized by PPM_new,
// and an array of integers representing the pixels of an image
// in this order : r1 g1 b1 r2 g2 b2 ...
// PPM_save saves this new file (with the same width and height)
// the file whose path is given in the outputfile parameter

void PPM_save(struct ppm p, struct color *image, char *outputfile)
{
	FILE *ppmfile;
	int n;

	ppmfile = fopen(outputfile,"w");
	if(ppmfile==NULL)
	{
		perror(outputfile);
		exit(1);
	}
	else
	{
		fprintf(ppmfile,"P3\n");
		fprintf(ppmfile,"# File created by ppmfilecreator Arash Habibi\n");
		fprintf(ppmfile,"%d %d\n",p.width,p.height);
		fprintf(ppmfile,"%d\n",255);
		for(n=0;n<p.nbpixels;n++)
		{
			fprintf(ppmfile,"%d ",image[n].red);
			fprintf(ppmfile,"%d ",image[n].green);
			fprintf(ppmfile,"%d ",image[n].blue);
		}
		fclose(ppmfile);
	}
}
