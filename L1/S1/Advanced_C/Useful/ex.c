#include <stdio.h>
#include <stdlib.h>

float *V_new(float x, float y, float z)
{
	float *thenew;
	thenew = (float*)malloc(sizeof(float)*3);
	
	thenew[0] = x;
	thenew[1] = y;
	thenew[2] = z;
	
	return(thenew);
}

void V_print(float *v)
{
	printf("(%f,%f,%f)\n", v[0], v[1], v[2] );
}

int main()
{
	float *v;
	
	v=V_new(1,2,3);
	V_print(v);
	V_print(v);
	
	return 0;
}
