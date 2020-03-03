#include <stdio.h>

int main()
{
void WeekDay(int wDay);
int wDay;

printf("Enter weekday number (0-6): ");
scanf("%d", &wDay);
WeekDay(wDay);
printf("\n");

return 0;
}

void WeekDay(int wDay)
{
	switch (wDay)
	{
	case 0:  printf("Sunday");break;
	case 1:  printf("Monday");break;
	case 2:  printf("Tuesday");break;
       	case 3:  printf("Wednesday");break;
 	case 4:  printf("Thursday");break;
	case 5:  printf("Friday");break;
	case 6:  printf("Saturday");break;
	default: printf("There is no such day\n");
	}
}
