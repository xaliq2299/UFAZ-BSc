#include <stdio.h>

int main()
{
	int a=0, size=0, data[20], numb;	
	FILE *fp;

	fp=fopen("numbers.txt", "r");

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
	
	fclose(fp);
	
	for(a=0;a<size;a++)
		printf("%4d", data[a]);
	
	puts("");
				
return 0;
}
