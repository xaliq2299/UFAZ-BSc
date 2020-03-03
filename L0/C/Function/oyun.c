#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int towin, sans, eded;

	srand(time ( NULL ) );
	towin=rand()%100+1;

	printf("Her vaxtiniz xeyir\n"
		"Oyunumuza xos gelmissiniz!\n"
		"Oyunumuz 1 ve 100 arasinda olan bir ededi tapmaqdan ibaretdir.\n"
		"Bu muddet erzinde ise sizin 5 defe cavab vere bilme sansiniz olacaq.\n"
		"Ugurlar!!!\n");
	
	//Game starts	
		for(sans=5;sans>=1;sans--)
		{
			printf("Ededi daxil edin: ");
			scanf("%d", &eded);
			if(eded == towin)
			{
				printf("Siz qalibsiniz!!! Tebrikler!\n");
				break;			
			}
			else if(towin>eded)
			{
				printf("Yuxari\n");					
				if(sans!=1)				
				printf("%d defe cavab verme huququnuz qalib\n", sans-1);
				if(sans==1)
				printf("Game over\n");			
			}
			else
			{
				printf("Asagi\n");
				if(sans!=1)				
				printf("%d defe cavab verme huququnuz qalib\n", sans-1);		
				if(sans==1)
				printf("Game over\n");				
			}
		}	
						
	return 0;
}
