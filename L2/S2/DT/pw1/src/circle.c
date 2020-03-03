#include "circle.h"
#include  "point.h"

Circle getCircle(){
	Circle c;
	printf("Enter the radius: ");
	scanf("%f", &c.radius);
	printf("Enter the coordinates of a center: ");
	scanf("%f%f", &c.cen.x, &c.cen.y);

	return c;
}

void printCircle(Circle c){
	printf("=====================================================\n");
	printf("Circle of\n");
	printf("radius: %.3lf\n", c.radius);
	printf("and center: (%.3lf, %.3lf)\n", c.cen.x, c.cen.y);
	printf("=====================================================\n");
}

int isIntersectingIn2Points(Circle *c1, Circle *c2){
	float length = distance(c1->cen, c2->cen);
	if((c1->cen).x == (c2->cen).x && (c1->cen).y == (c2->cen).y && c1->radius == c2->radius) // infinite intersection
		return 0;
	if(length == c1->radius+c2->radius || length == abs(c1->radius-c2->radius)) // 1 intersection
		return 0;
	if(length < c1->radius+c2->radius && length > abs(c1->radius-c2->radius)) // 2 intersections
		return 1;
	return 0; // for all other cases no intersection
}


int isInside(Circle c, Point p){
	if( (p.x-c.cen.x)*(p.x-c.cen.x)+(p.y-c.cen.y)*(p.y-c.cen.y) < c.radius*c.radius ) // TODO
		return 1;
	else	return 0;
}