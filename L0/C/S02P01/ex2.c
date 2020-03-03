#include <stdio.h>

int main()
{
	int C[4], a; 
	float F[4];
	printf("Enter the temperatures in Celsius (only 4): ");	
	for(a=0;a<4;a++)	
		scanf("%d", &C[a]); 	
	for(a=0;a<4;a++)	
		F[a]=9*C[a]/5+32;		
	printf("%c\t%c\n", 'C', 'F');
	for(int a=0;a<4;a++)
		printf("%d\t%.0f.0\n", C[a], F[a]);

return 0;
}
				
