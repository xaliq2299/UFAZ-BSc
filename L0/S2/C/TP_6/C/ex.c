#include <stdio.h>

typedef struct {
	char code;
	int ref;
	float price;
	int stock;
}Product;

void getProduct(Product *A);
void showProduct(Product *A);
float command(Product *A, int);

int main()
{
	int choice, choice1, quantity;	
	Product Motherboard, Processor, Hard_disk, Graphic;
	
	printf("1.Motherboard\n2.Processor\n3.Hard-disk\n4.Graphic\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: getProduct(&Motherboard);
			printf("\nMotherboard\n");			
			showProduct(&Motherboard);
			break;		
		case 2: getProduct(&Processor);
			printf("\nProcessor\n");
			showProduct(&Processor);
			break;		
		case 3: getProduct(&Hard_disk);
			printf("\nHard-disk\n");
			showProduct(&Hard_disk);
			break;		
		case 4: getProduct(&Graphic);
			printf("\nGraphic\n");
			showProduct(&Graphic);
			break;		
		default: printf("Enter smth available\n"); return 1;
	}

	printf("\n1.Motherboard\n2.Processor\n3.Hard-disk\n4.Graphic\n");
	printf("Which product?\n");
	scanf("%d", &choice1);
	printf("Enter also the quantity you want: ");
	scanf("%d", &quantity);
	
	switch(choice1)
	{
		case 1: printf("The price you should pay: %f\n", command(&Motherboard, quantity) );
			break;
		case 2: printf("The price you should pay: %f\n", command(&Processor, quantity) );
			break;			
		case 3: printf("The price you should pay: %f\n", command(&Hard_disk, quantity) );
			break;		
		case 4: printf("The price you should pay: %f\n", command(&Graphic, quantity) );
			break;		
		default: printf("Enter smth available\n"); break;	
	}	

	return 0;
}

void getProduct(Product *A)
{
	printf("The code: ");
	scanf(" %c", &(*A).code);

	printf("The reference: ");
	scanf(" %d", &(*A).ref);

	printf("The price: ");
	scanf(" %f", &(*A).price);

	printf("The stock quantity: ");
	scanf("%d", &(*A).stock);
}

void showProduct(Product *A)
{
	printf("The code: %c\n", (*A).code);

	printf("The reference: %d\n", (*A).ref);

	printf("The price: %f\n", (*A).price);

	printf("The stock quantity: %d\n", (*A).stock);
}

float command(Product *A, int quantity)
{	
	printf("The code: %c\n", (*A).code);

	printf("The reference: %d\n", (*A).ref);

	printf("The price: %f\n", (*A).price);

	printf("The stock quantity: %d\n", (*A).stock);

	return quantity * (*A).price ;
}
