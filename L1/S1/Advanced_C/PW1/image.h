#include <stdio.h>
#include "color.h" // because image functions wil also necessarily deal with colors

void I_print    (struct color img[], int nb_pixels);
void I_coef     (struct color img[], int nb_pixels, float coef);
void I_negative (struct color img[], int nb_pixels);
void I_permute  (struct color img[], int nb_pixels);
void I_grayScale(struct color img[], int nb_pixels);
void I_threshold(struct color img[], int nb_pixels, int th);
void I_compose  (struct color img1[], struct color img2[], int nb_pixels, struct color target);
void I_addColor(struct color img[], int nb_pixels, struct color c);
void I_gradient(struct color img_in[], struct color img_out[], int nb_pixels);
struct color I_average(struct color img[], int nb_pixels, int fromhere, int nb_pixels_average);
void I_motionBlur(struct color img[], struct color img_out[], int nb_pixels, int strength);
