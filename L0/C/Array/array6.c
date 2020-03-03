#include <stdio.h>
#define RESPONSE_SIZE 30

int main()
{
int a, frequency;

int responses[RESPONSE_SIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 5, 6, 6, 5, 3, 4, 5};

printf("%s%17s%10s\n", "Rating", "Frequency", "Histogram");

for(a=1;a<=10;a++)
{
frequency=0;
printf("%d", a);

for(int i=0;i<RESPONSE_SIZE;i++)
{
if(responses[i]=a)
frequency=frequency+1;
} 
printf("%17d", frequency);
printf("\n");
}
return 0;
}
