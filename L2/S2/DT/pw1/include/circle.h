#ifndef _VAR_CIRCLE
#define _VAR_CIRCLE

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

typedef struct {
	Point cen; // center
	float radius;
}Circle;

Circle getCircle();
void printCircle(Circle c);
int isIntersectingIn2Points(Circle *c1, Circle *c2);
int isInside(Circle c, Point p);

#endif