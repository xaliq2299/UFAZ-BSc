#include<stdio.h>
#include<math.h>

float f(float x){
	float y;
	y=((2*pow(x,3)+3)*(pow(x,2)-1))/sqrt(3*pow(x,2)+1);
	return y;
}

float fPrim(float x, float h){
	return (f(x+h)-f(x-h))/(2*h);
}

float fSecond(float x, float h){
	return (fPrim(x+h,h)-fPrim(x-h,h))/(2*h);
}

int sign(float x){
	float h, dSecond;
	printf("Give the approximation level h:");
	scanf("%f",&h);
	dSecond =fSecond(x,h);
	if(dSecond<0.0)
		return -1;
	if(dSecond==0.0)
		return 0;
	return 1;
}

void choice(){
	int c;
	float x, h;
	printf("Please give your choice ... \n");
	printf("1 the value of f\n");
	printf("2 the value of f'\n");
	printf("3 the value of f''\n");
	c=getchar();
	printf("x=");
	scanf("%f",&x);
	switch(c){
		case '1':
			printf("f(%f)=%f\n", x, f(x));
			break;
		case '2':
			printf("please give h=");scanf("%f",&h);
			printf("f'(%f)=%f\n", x, fPrim(x,h));
			break;
		case '3':
			printf("please give h=");scanf("%f",&h);
			printf("f''(%f)=%f\n", x, fSecond(x,h));
			break;
		default :
			printf("Undefined Choice ...");
			printf("Please give your choice ... \n");
			printf("1 the value of f\n");
			printf("2 the value of f'\n");
			printf("3 the value of f''\n");
			c=getchar();
	}
}

int main(){
	choice();
	return 0;
}
