#include <stdio.h>

struct product{
	float price;
	int quantity;
};

void save();
void show(int size, struct product array);

int main()
{	
save();
return 0;
}

void save()
{
FILE *fp;
fp=fopen("product.txt", "r");
int N;
fscanf(fp, "%d", &N);
struct product data[N];


for(int a=0;a<N;a++)
{
	if(fp==NULL)
	printf("Error, file does not exist\n");
	
	fscanf( fp, "%f", &data[a].price );
	fscanf( fp, "%d", &data[a].quantity );
}
fclose(fp);
show(N, data[N]);
}

void show(int size, struct product array)
{
	for(int a=0;a<size;a++)	
	printf("%f  %d", array[a].price, array[a].quantity);
} 
