/*a program of Fibonacci series using recursion*/

#include <stdio.h>

long fibonacci();

int main()
{
	int n, counter;
	printf("enter the number of the term in Fibonacci Series:\n");
	scanf("%d", &n);
	for(counter=0;counter<=n;counter++)	


/*Actually the n variable that we use here does not affect to the function process.
It means that it can be any other variable and not the same
with the variable n that we use inside the function*/

//why it also works correctly when the variable n (which is above in code) is smth different (for ex, b, j etc.)

	printf("The term number %d in this series is %ld\n", counter, fibonacci(counter));
	return 0;
}

long fibonacci(int counter)
{
	if (counter==1) //is it important to use condition in this case?
	return 0;
	else {
	for(int a=1;a<=counter;counter++){
	return (fibonacci(counter-1)+fibonacci(counter-2));
	}
	}
}
