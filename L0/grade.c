#include <stdio.h>

int main()
{
	int nbs; //# of subjects
	int nbe; //# of exams
	float coef, ECTS=0.0; //# of credits ECTS is the sum of all coefficients

	float average, aver_sub, ects_sub, sum=0.0, grade;
	char subject[10];
	
	printf("How many subjects?\n");
	scanf("%d", &nbs);
	
	for(int a=1;a<=nbs;a++)
	{
		aver_sub=0.0;
		ects_sub=0.0;
		printf("\nSubject %d: ", a); 
		scanf("%s", subject);
		printf("How many exams from %s: ", subject);
		scanf("%d", &nbe);
		printf("\n");
		for ( int i=1;i<=nbe;i++ )
		{
			printf("Enter grade of exam %d from %s: ", i, subject);
			scanf("%f", &grade);	
			printf("Enter the coef of this exam: "); 				
			scanf("%f", &coef);
			
			ECTS+=coef;
			ects_sub+=coef;
			printf("ECTS: %f\n", ECTS);
			printf("ects_%s: %f\n", subject, ects_sub);
			aver_sub+=(coef*grade);
		
		}
		aver_sub/=ects_sub;
		printf("Aver_%s: %f\n", subject, aver_sub); 
		sum+=(aver_sub*ects_sub);
	}
	
	average=(float)sum/ECTS;
	printf("\nAverage: %f\n", average);

	return 0;
}
