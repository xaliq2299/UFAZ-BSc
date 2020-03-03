#include <stdio.h>
#define SIZE 100

int read_array(double *a, int max_elem, int *nb_elem){
	int read=0, i;
	for(i=0;i<max_elem;i++){
		if(scanf("%lf", &a[i]))
			read++;
	}
	*nb_elem=read;
	if(*nb_elem < max_elem) return -1; else return 0;
}

void sort_array(double *a, int nb_elem){
	for(int pass=1;pass<nb_elem;pass++){
		for(int i=0;i<nb_elem-1;i++){
			if(a[i]>a[i+1]){
				double hold=a[i];
				a[i]=a[i+1];
				a[i+1]=hold;
			}
		}
	}
}

void display_array(double *a, int nb_elem){
	for(int i=0;i<nb_elem;i++)
		printf("%lf\n", a[i]);
}

int main(){
	double a[SIZE]; int nbElems;
	read_array(a,3,&nbElems);
	display_array(a,nbElems);
	sort_array(a,nbElems);
	printf("\n");
	display_array(a,nbElems);
	
	return 0;
}