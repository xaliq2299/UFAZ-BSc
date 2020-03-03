#ifndef _VAR_RECT
#define _VAR_RECT

#include <stdio.h>
#include "circle.h"

typedef struct {
	float xmin, xmax, ymin, ymax;
}Rectangle;

Rectangle getRect(Circle c1, Circle c2);
void printRect(Rectangle r);
float calcAreaRect(Rectangle r);

#endif