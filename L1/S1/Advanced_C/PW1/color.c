#include <stdio.h>
#include "color.h"

void C_print(struct color c){
	printf("(%d,%d,%d)\n", c.red, c.green, c.blue);
}

static int _clamp(int n){
	if(n<0)  return 0;
	else if(n>255)   return 255;
	else  return n;
}

struct color C_new(int r, int g, int b){
	struct color c;
	c.red = _clamp(r); 
	c.green = _clamp(g); 
	c.blue = _clamp(b);
	return c;
}

struct color C_multiply(struct color c, float coef){
	if(coef > 0){
		c.red *= coef; c.red = _clamp(c.red);
		c.green *= coef; c.green = _clamp(c.green);
		c.blue *= coef; c.blue = _clamp(c.blue);
	}
	return c;
}

struct color C_negative(struct color c){
	c.red = 255-c.red;
	c.green = 255-c.green;
	c.blue = 255-c.blue;
	return c;
}

struct color C_permute(struct color c){
	int hold = c.red;
	c.red = c.green;
	c.green = c.blue;
	c.blue = hold;
	return c;
}

int C_intensity(struct color c){
	return ( (c.red+c.green+c.blue)/3 );
}

struct color C_grayScale(struct color c){
	c.red = c.green = c.blue = C_intensity(c);
	return c;
}

int C_threshold(struct color c, int th){
	if(C_intensity(c) > th)  return 255;
	else 		return 0;
}

int C_areEqual(struct color c1, struct color c2){
	if(c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue)
		return 1;
	else  return 0;
}

struct color C_addCoef(struct color c1, struct color c2, float coef){
	return C_new(c1.red+coef*c2.red, c1.green+coef*c2.green, c1.blue+coef*c2.blue);
}
