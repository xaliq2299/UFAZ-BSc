#include <stdio.h>

struct product{
	float price;
	int quantity;
};

int main()
{
int save(FILE *fp);
return 0;
}

int save(FILE *fp)
{
int N;

fp=fopen("product.txt", "r");
fscanf( fp, "%d", &N);
struct product data[N];

if(fp==NULL)
printf("Error \n");
else
{
for(int a=0;a<N;a++)
fscanf( fp, "\n%f %d", &data[a].price, &data[a].quantity );
}

fclose(fp);

for(int a=0;a<N;a++)
printf( "%.2f %d\n", data[a].price, data[a].quantity );

return 0;
}
