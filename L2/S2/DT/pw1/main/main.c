#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "point.h"
#include "circle.h"
#include "rectangle.h"

int main(){
	Circle c1 = getCircle();
	Circle c2 = getCircle();
	if( c1.radius <= 0 || c2.radius <= 0) {
		printf("Negative or zero radius!\n");
		return -1;
	}
	printCircle(c1);
	printCircle(c2);

	Rectangle r = getRect(c1, c2);
	printRect(r);

	if(isIntersectingIn2Points(&c1, &c2)){
		int nRand, nInside=0;
		float rangeX=(r.xmax-r.xmin)+r.xmin; 
		float rangeY=(r.ymax-r.ymin)+r.ymin;
		printf("Enter the number of random points in a plane: ");
		scanf("%d", &nRand);
		for(int i=0;i<nRand;i++){
			Point p = getRandomPoint(rangeX, rangeY);
			if(isInside(c1, p) && isInside(c2, p))
				nInside++;
		}
		printf("The number of points inside: %d\n", nInside);
		float areaRect = calcAreaRect(r);
		float area = (float)nInside/nRand*(float)areaRect;
		printf("Area of the intersection between these 2 circles: %.3f\n", area);
	}
	else
		printf("The circles don't intersect in 2 points.\n");

	return 0;
}