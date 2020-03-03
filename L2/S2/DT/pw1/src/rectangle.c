#include "rectangle.h"

Rectangle getRect(Circle c1, Circle c2){
	Rectangle r;
	// determining the coordinates of a rectangle
	if(c1.cen.x - c1.radius < c2.cen.x - c2.radius )
		r.xmin = c1.cen.x - c1.radius; // problem TODO ???
	else
		r.xmin = c2.cen.x - c2.radius;

	if(c1.cen.x + c1.radius > c2.cen.x + c2.radius)
		r.xmax = c1.cen.x + c1.radius;
	else
		r.xmax = c2.cen.x + c2.radius;

	if(c1.cen.y - c1.radius < c2.cen.y - c2.radius )
		r.ymin = c1.cen.y - c1.radius; // problem TODO ???
	else
		r.ymin = c2.cen.y - c2.radius;

	if(c1.cen.y + c1.radius > c2.cen.y + c2.radius)
		r.ymax = c1.cen.y + c1.radius;
	else
		r.ymax = c2.cen.y + c2.radius;
	return r;
}

void printRect(Rectangle r){
	printf("xmin=%f, xmax=%f, ymin=%f, ymax=%f\n", r.xmin, r.xmax, r.ymin, r.ymax);
}

float calcAreaRect(Rectangle r){
	return (r.xmax-r.xmin)*(r.ymax-r.ymin);
}