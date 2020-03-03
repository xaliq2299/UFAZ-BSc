#include <stdio.h>
#include "point.h"

float distance(Point p1, Point p2){
	return sqrt( (p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y));
}

Point getRandomPoint(float dX, float dY){
	Point p;
	srand(time(NULL));
	p.x = (float)rand()/RAND_MAX * dX;
	p.y = (float)rand()/RAND_MAX * dY;
	printf("(%f %f)\n", p.x, p.y);
	return p;
}