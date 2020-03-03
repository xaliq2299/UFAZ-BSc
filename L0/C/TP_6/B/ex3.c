#include <stdio.h>

int main()
{
	int a=0, size=0, data[20], numb;	
	FILE *fp;

	fp=fopen("numbers.txt", "r+");

	if(fp==NULL)
	printf("File doesn't exist\n");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp, "%d ", &data[a] );
			a++;	
			size++;
		}
	}
	
	printf("Number to charge: ");
	scanf("%d", &numb);
	fprintf(fp, "%d", numb);
	
	fclose(fp);
	
	for(a=0;a<size;a++)
		printf("%4d", data[a]);
		printf("%4d", numb);

	puts("");	
				
return 0;
}
