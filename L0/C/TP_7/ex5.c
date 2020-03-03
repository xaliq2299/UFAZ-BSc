#include <stdio.h>

struct product{
	int quantity;
	float price;
};

int main()
{
FILE *fp; 
FILE *fp1;
int N, b, change;

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
printf("How much do you want to use? ");
scanf("%d\n", &change);
printf("%d\n", data[b-1].quantity-change);
fclose(fp1);

return 0;
}
