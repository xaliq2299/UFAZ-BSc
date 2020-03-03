#include <stdio.h>
#include <math.h>

int main(){
	int N, b, sum=0;
	printf("Enter the decimal number: ");
	scanf("%d", &N);
	printf("Which base you want to convert (2-9)? ");	
	scanf("%d", &b);

	for(int i=0;N!=0;i++){
		sum += N%b*pow(10,i);
		N/=b;
	}
	printf("\nThis number in base %d: %d\n", b, sum);

	return 0;
}
