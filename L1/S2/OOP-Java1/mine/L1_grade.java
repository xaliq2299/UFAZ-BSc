import java.util.Scanner;

class Calc_Average{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		int nbs; //# of subjects
		int nbe; //# of exams
		float coef, ECTS=0; //# of credits ECTS is the sum of all coefficients
	
		float average, aver_sub, ects_sub, sum=0, grade;
		//String subject;//char subject[10];
		
		System.out.println("How many subjects?");
		nbs=in.nextInt(); //scanf("%d", &nbs);
		
		for(int a=1;a<=nbs;a++)
		{
			aver_sub=0;
			ects_sub=0;
			System.out.printf("\nSubject %d: ", a); 
			String subject = in.next();	//scanf("%s", subject);
			System.out.printf("How many exams from %s: ", subject);
			nbe=in.nextInt(); //scanf("%d", &nbe);
			System.out.print("\n"); //printf("\n");
			for ( int i=1;i<=nbe;i++ )
			{
				System.out.printf("Enter grade of exam %d from %s: ", i, subject);
				grade=in.nextFloat();  //scanf("%f", &grade);
				System.out.print("Enter the coef of this exam: "); 				
				coef=in.nextFloat(); //scanf("%f", &coef);
				
				ECTS+=coef;
				ects_sub+=coef;
				System.out.println("ECTS: " +ECTS);
				System.out.printf("ects_%s: %f\n", subject, ects_sub);
				aver_sub+=(coef*grade);
			
			}
			aver_sub/=ects_sub;
			//System.out.println("Aver_"+subject ": "+aver_sub);
			sum+=(aver_sub*ects_sub);
		}
		
		average=(float)sum/ECTS;
		System.out.println("\nAverage: " +average);
	}	
}
