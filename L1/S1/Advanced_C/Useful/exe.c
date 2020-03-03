#include <stdio.h>
#include <stdlib.h>

int V_new(float x, float y, float z, float **thenew)
{
	*thenew = /*(float*)*/ calloc(3,sizeof(float));
	
	*thenew[0] = x; 
	*thenew[1] = y; 
	*thenew[2] = z;

	return 0;
}

int main()
{
	float *v;
	int diagnosis = V_new (1, 2, 3, &v);
	printf(" (%f,%f,%f)\n", v[0], v[1], v[2]);

	return 0;
}
