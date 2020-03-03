#include <stdio.h>
#include <math.h>

int main()
{
	int numb, num, number, n=0, armst=0;
	
	printf("Enter the number: ");
	scanf("%d", &numb);
	
	num=numb; //num --> to find the number of digits
	number=numb; //number --> to display the number at the end

	while(num!=0)
	{
		n++;
		num/=10;
	}	
	
	while(numb!=0)
	{
		armst=armst+pow(numb%10, n);
		numb/=10;
	}

	if(number == armst)
	printf("%d is an armstrong number\n", number);
	else
	printf("%d is not an armstrong number\n", number);

return 0;
}
