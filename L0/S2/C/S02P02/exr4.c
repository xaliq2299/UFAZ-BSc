#include<stdio.h>
#include<math.h>

typedef struct point{
	float x,y;
}Point;

void exchange(Point *a, Point *b){
	Point t;
	t.x=a->x;
	t.y=a->y;
	a->x=b->x;
	a->y=b->y;
	b->x=t.x;
	b->y=t.y;
}

float distance(Point A,Point B){
	float d;
	d=sqrt(pow(B.x-A.x,2)+pow(B.y-B.x,2));
	return d;
}

void show(Point Q){
	printf("The point is (%f,%f)\n",Q.x,Q.y);
}

int main(){
	Point M,N;
	printf("Coordinate of first point:\n");
	scanf("%f %f",&M.x,&M.y);
	printf("Coordinate of second point:\n");
	scanf("%f %f",&N.x,&N.y);
	exchange(&M,&N);
	show(M);
	show(N);
	printf("d=%f \n",distance(M,N));
	return 0;
}
