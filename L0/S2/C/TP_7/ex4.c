#include <stdio.h>

struct product{
	int quantity;
	float price;
};

int main()
{
FILE *fp; 
FILE *fp1;
int N, b;

fp=fopen("product.txt", "r");
fscanf( fp, "%d", &N);
struct product data[N];

for(int a=0;a<N;a++)
{
if(!feof(fp))
fscanf( fp, " %f %d", &(data[a].price), &data[a].quantity );
}
printf("Enter the line: ");
scanf("%d", &b);

fclose(fp);

fp1=fopen("command.txt", "r");
printf("%f\n", data[b-1].price);
return 0;
}
