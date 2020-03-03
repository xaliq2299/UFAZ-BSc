#include "image.h"

void I_print(struct color img[], int nb_pixels){
	for(int i=0;i<nb_pixels;i++)
		C_print(img[i]);
}

void I_coef(struct color img[], int nb_pixels, float coef){
	for(int i=0;i<nb_pixels;i++)
		img[i] = C_multiply(img[i], coef);
}

void I_negative(struct color img[], int nb_pixels){
	for(int i=0;i<nb_pixels;i++)
		img[i] = C_negative(img[i]);
}

void I_permute(struct color img[], int nb_pixels){
	for(int i=0;i<nb_pixels;i++)
		img[i] = C_permute(img[i]);
}

void I_grayScale(struct color img[], int nb_pixels){
	for(int i=0;i<nb_pixels;i++)
		img[i] = C_grayScale(img[i]);
}

void I_threshold(struct color img[], int nb_pixels, int th){
	for(int i=0;i<nb_pixels;i++){
		img[i].red = img[i].green = img[i].blue = C_threshold(img[i], th);
	}
}

void I_compose(struct color img1[], struct color img2[], int nb_pixels, struct color target){
	for(int i=0;i<nb_pixels;i++){
		if( C_areEqual(img1[i], target) )
			img1[i] = C_new(img2[i].red, img2[i].green, img2[i].blue);
	}
}

void I_addColor(struct color img[], int nb_pixels, struct color c){
	for(int i=0;i<nb_pixels;i++)
		img[i] = C_addCoef(img[i],c,1);
}

void I_gradient(struct color img_in[], struct color img_out[], int nb_pixels){
	struct color gray = C_new(127, 127, 127);
	for(int i=1;i<nb_pixels;i++){
		img_out[i] = C_addCoef(img_in[i], img_in[i-1], -1);
		img_out[i] = C_addCoef(img_out[i], gray, 1);
	}
}

struct color I_average(struct color img[], int nb_pixels, int fromhere, int nb_pixels_average){
	int sumr=0, sumg=0, sumb=0;
	if(fromhere+nb_pixels_average < nb_pixels){
		for(int i=fromhere;i<=fromhere+nb_pixels_average-1;i++){
			sumr += img[i].red;
			sumg += img[i].green;
			sumb += img[i].blue;
		}
	}
	return C_new(sumr/nb_pixels_average, sumg/nb_pixels_average, sumb/nb_pixels_average);
}

void I_motionBlur(struct color img[], struct color img_out[], int nb_pixels, int strength){
	for(int i=0;i<nb_pixels;i++){
		if(nb_pixels-i-1 < strength)
			img_out[i] = I_average(img, nb_pixels, i, nb_pixels-i);
		else
			img_out[i] = I_average(img, nb_pixels, i, strength);
	}
}
