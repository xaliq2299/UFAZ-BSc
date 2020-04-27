#include <stdio.h>

struct product{
	float price;
	int quantity;
};

int main()
{
FILE *fp; 
int N, b;

fp=fopen("product.txt", "r");
fscanf( fp, "%d", &N);
struct product data[N];

for(int a=0;a<N;a++)
{
if(fp!=NULL)
fscanf( fp, "\n%f %d", &(data[a].price), &data[a].quantity );
}
fclose(fp);

printf("Enter the line: ");
scanf("%d", &b);
printf("%.2f\n", data[b].price); 

return 0;
}


