#include <stdio.h>

int main()
{
	int check=0, size1, size2;

	printf("Enter size for the first table: ");
	scanf("%d", &size1);
	int tab1[size1];
	printf("Enter the numbers for the 1st table: ");
	for(int a=0;a<size1;a++)
		scanf("%d", &tab1[a] );

	printf("Enter size for the second table: ");
	scanf("%d", &size2);
	int tab2[size2];
	printf("Enter the numbers for the 2nd table: ");
	for(int b=0;b<size2;b++)
		scanf("%d", &tab2[b] );

	for(int a=0;a<size1;a++)
	{
		for(int b=0;b<size2;b++)
		{	
			if(tab1[a]==tab2[b])
				check++;
		}
	}

	if(check==size1 || check==size2)
	printf("One of these tables is totally included inside another one\n");
	else
	printf("None of these tables is included one to the other\n");

return 0;
}
