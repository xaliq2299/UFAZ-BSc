#include <stdio.h>
#include <math.h>

typedef struct {
	float x, y;
	}Point;

void exchange(Point *A, Point *B);
Point present(Point A);
float distance(Point A, Point B);

int main()
{
	Point point1, point2;

	printf("Enter the coordinates of the first point: ");
	scanf("%f%f", &point1.x, &point1.y);

	printf("Enter the coordinates of the second point: ");
	scanf("%f%f", &point2.x, &point2.y);

	exchange(&point1, &point2);
	
	point1=present(point1);
	point2=present(point2);
	
	printf("(%f, %f)\n", point1.x, point1.y );
	printf("(%f, %f)\n", point2.x, point2.y );
	
	printf("The distance between these two points: %.3f\n", distance( point1, point2 ) ); 

	return 0;	
}

void exchange(Point *A, Point *B)
{
	Point hold;

	hold.x=(*A).x;
	(*A).x=(*B).x;
	(*B).x=hold.x;

	hold.y=(*A).y;
	(*A).y=(*B).y;
	(*B).y=hold.y;
}

Point present(Point A)
{
	return A;
}

float distance(Point A, Point B)
{
	float dist;
	dist=sqrt( pow((A.x-B.x),2) + pow((A.y-B.y), 2)  );
	return dist;
}
