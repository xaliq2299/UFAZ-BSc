#ifndef _VAR_POINT
#define _VAR_POINT

#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	float x, y;
}Point;

float distance(Point p1, Point p2);
Point getRandomPoint(float dX, float dY);

#endif