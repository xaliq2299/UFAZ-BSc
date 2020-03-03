#include <stdio.h>

typedef struct {
	float real;
	float imagn;
}Number;
	
	Number Complex1, Complex2, answer, Answer;
	
Number add(Number A, Number B);

int main()
{
	printf("Complex number 1 --> ");
	printf("Enter the real and imaginary parts: ");
	scanf("%f%f", &Complex1.real, &Complex1.imagn);

	printf("Complex number 2 --> ");
	printf("Enter the real and imaginary parts: ");
	scanf("%f%f", &Complex2.real, &Complex2.imagn);
	
	answer = add(Complex1, Complex2);
	
	printf("After adding these complex numbers: %.1f+%.1fi\n", answer.real, answer.imagn);

return 0;
}

Number add(Number A, Number B)
{
	Answer.real=A.real+B.real;
	Answer.imagn=A.imagn+B.imagn;
	
return Answer;
}
