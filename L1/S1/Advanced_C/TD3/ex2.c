#include <stdio.h>

struct vector{
	float array[4];
	int nb_dims;
};

void V_allZero(float vector[], int nb_dims){
	for(int i=0;i<nb_dims;i++)
		vector[i] = 0;
}

void V_print(float vector[], int nb_dims){
	for(int i=0;i<nb_dims;i++)
		printf("%6.2f", vector[i]);
	printf("\n");
}

int V_belongsTo(float x, float vector[], int nb_dims){
	for(int i=0;i<nb_dims;i++){
		if(vector[i] == x)
			return 1;
	}
	return 0;
}

struct vector V_new(int nb_dims){
	struct vector v;
	v.nb_dims = nb_dims;
	return v;
}

void V_allZero2(struct vector v){
	for(int i=0;i<v.nb_dims;i++)
		v.array[i] = 0;
}

void V_print2(struct vector v){
	for(int i=0;i<v.nb_dims;i++)
		printf("%6.2f", v.array[i]);
	printf("\n");	
}

int V_belongsTo2(struct vector v, int x){
	for(int i=0;i<v.nb_dims;i++){
		if(v.array[i] == x)
			return 1;
	}
	return 0;
}

int main(){
	float v[2];
	//...
	V_allZero(v,3);
	V_print(v,3);
	
	return 0;
}
