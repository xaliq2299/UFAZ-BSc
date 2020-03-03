#include <stdio.h>
#include <stdlib.h>

struct vector{ float x,y,z; };

float* V_new1(float x,float y,float z){
	float *thenew = (float*) calloc(3,sizeof(int));
	thenew[0] = x;
	thenew[1] = y;
	thenew[2] = z;
	return thenew;
}

struct vector V_new2(float x,float y,float z){
	struct vector thenew;
	thenew.x = x;
	thenew.y = y;
	thenew.z = z;
	return thenew;
}

int main(){
	float *v1 = V_new1(5,6,7);
	struct vector v2 = V_new2(1,2,3);
	printf("v1 : (%f,%f,%f)\n", v1[0],v1[1],v1[2]);
	printf("v2 : (%f,%f,%f)\n", v2.x,v2.y,v2.z);
	
	return 0;
}
