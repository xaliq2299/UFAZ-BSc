//a program of statistics for a data of integers
#include <stdio.h>
#include <math.h>
#define SIZE 17


void quantitative();
void qualitative();
void sort(int n, int array[n]);	
void sort_rev(int n, int array[n]);
int find_max(int n, int array[n] );
int find_min(int n, int array[n] );
float find_mean(int n, int array[n]);
float find_median(int n, int array[n]);
void find_mode(int big, int freq[big+1] );
float std_dev(int n, int array[n], float mean );
float variance(int n, int array[n], float mean );
void skewness(float, float);
void find_outliers(int n, int array[n], float, float, float);
void frequency(int n, int array[n], int, int);


void main(int choice)
{
	CHOICE:	printf("1)quantitative data\n2)qualitative data\n");
		
		scanf("%d", &choice);
		switch(choice)
		{		
			case 1: quantitative();		
			case 2: break;
			default: goto CHOICE; 
		}
}


void quantitative()
{
	int N, a, b, big, small, flag=0;
	float mean, median, Q1, Q3, IQR;
	
	printf("The number of elements in the data: ");
	scanf("%d", &N);
	
	int data[N];
			
	printf("Enter the numbers of your data:\n");
	for(a=0;a<N;a++)
		scanf("%d", &data[a] );
		
	//sorting of our data using function
	sort(N, data);
	printf("\nThis is our sorted data:\n");
	for(a=0;a<N;a++)
		printf("%4d", data[a] ); 	
	puts("");
		
	//determining the biggest element (also important for finding mode)
	big=find_max(N, data);	
	//determining the smallest element
	small=find_min(N, data);
	printf("Smallest element in the data: %d\nBiggest element in the data: %d\n\n", small, big);
					
	printf("Measures of (central) location\n");
	//Mean	
	mean=find_mean(N, data);
	printf("Mean: %.2f\n", mean);	
	//Median
	median=find_median(N, data);
	printf("Median: %.2f\n", median );
	//Mode
	int freq[big+1];//we did this cause it will help us to find mode
			
	for(a=0;a<big+1;a++)
		freq[a]=0;
				
	for(a=0;a<N;a++)
		freq[data[a]]+=1;
				
	printf("Histogram\n");
	for(a=0;a<=big;a++)
	{		
		if(freq[a]!=0)
		{		
		 	printf("%4d ", a );
			for(int counter=0;counter<freq[a];counter++)
				printf("%c", '*');
			puts("");	
		}
	}	
			
	for(a=0;a<big+1;a++)
	{
		if(freq[a]!=1 && freq[a]!=0)
		{		
			find_mode(big, freq);
			flag++;			
			break;
		}
	}
		
	if(flag==0)
		printf("There is no mode\n\n");
				
	//Quartiles (actually they are the medians of the 25% and 75% percents of our array, 50% is the original median)		
	printf("Measures of non-central location\n");	
	printf("Quartiles - ");
	Q1=find_median(N/2, data);
	printf("Q1: %.2f, Q2: %.2f, ", Q1, median ); 
					
	sort_rev(N, data);//it was important, i mean a very good idea
	Q3=find_median(N/2, data);	
	printf("Q3: %.2f\n\n", Q3 );
		
	sort(N, data);	
		
	printf("Measures of dispersion\n");
	//Range
	printf("Range: %d\n", big-small );
	//IQR
	IQR=Q3-Q1;
	printf("Interquartile range (IQR): %.2f\n", IQR);
	//Standard deviation
	printf("Standard deviation: %.3f\n", std_dev( N, data, mean ) );
	//Variance
	printf("Variance: %.3f\n\n", variance( N, data, mean ) );

	//Boxplot (yet can not draw)
	printf("Five number summary:\n");
	printf("min=%d|Q1=%.2f|Q2=%.2f|Q3=%.2f|max=%d\n", small, Q1, median, Q3, big);
	skewness(mean, median);
	find_outliers(N, data, Q1, Q3, IQR);
			
	//Frequency Distribution
	frequency(N, data, big, small);
}


void sort(int n, int array[n]) //bubble sorting
{
	int pass, a, hold;	
	
	for(pass=1;pass<n;pass++)
	{
		for(a=0;a<n-1;a++)
			{
				if(array[a]>array[a+1])
					{
						hold=array[a];
						array[a]=array[a+1];
						array[a+1]=hold;
					}
			}
	}
}


void sort_rev(int n, int array[n] )
{
	int pass, a, hold;	
	
	for(pass=1;pass<n;pass++)
	{
		for(a=0;a<n-1;a++)
			{
				if(array[a]<array[a+1])
					{
						hold=array[a];
						array[a]=array[a+1];
						array[a+1]=hold;
					}
			}
	}
}


int find_max(int n, int array[n] )
{
	int big;

	big=array[0];
	
	for(int a=1;a<n;a++)
	{
		if(array[a]>big)
			big=array[a];	
	}
	
	return big;
}


int find_min(int n, int array[n] )
{
	int small;	

	small=array[0];

	for(int a=1;a<n;a++)
	{
		if(array[a]<small)
			small=array[a];
	}

	return small;									
}


float find_mean(int n, int array[n])
{
	int sum=0;
	
	for(int a=0;a<n;a++)
		sum+=array[a];
	
	return ( (float)sum/n );	
}


float find_median(int n, int array[n] )
{
	float median;

	if(n%2!=0)		
		return ( array[(n+1)/2-1] );
	else
	{
		median=(float)( array[n/2-1]+array[n/2] ) / 2;
		return median;
	}
}


void find_mode(int big, int freq[big+1] )
{	
	int a, big1;

	big1=freq[0];
	for(a=1;a<big+1;a++)
	{
		if(freq[a]>big1)
			big1=freq[a];
	}
	
	printf("Mode:");
	for(a=0;a<big+1;a++)
	{
		if(big1==freq[a])	
			printf("%4d", a);	
	}
	
	printf("\n\n");
}


float std_dev(int n, int array[n], float mean )
{
	int sum=0, a; 	

	for(a=0;a<n;a++)	
		sum=(float)sum + (float)pow( (array[a]-mean), 2);

	return sqrt(sum/(float)(n-1));
}


float variance(int n, int array[n], float mean )
{
	int sum=0, a; 	

	for(a=0;a<n;a++)	
		sum=(float)sum + (float)pow( (array[a]-mean), 2);

	return (sum/(float)(n-1));
}


void skewness(float mean, float median)
{
	if (mean>median)
		printf("This data has positive or right skewness\n");
	else if (mean<median)
		printf("This data has negative or left skewness\n");
	else
		printf("Our data is symmetric (zero-skewness)\n");
}


void find_outliers(int n, int array[n], float Q1, float Q3, float IQR)
{
	int outlier=0;

	printf("Outliers: ");

	for(int a=0;a<n;a++)
	{
		if(array[a]<(Q1-1.5*IQR) || array[a]>(Q3+1.5*IQR) )
		{
			printf("%3d", array[a] );
			outlier++;
		}		
	}
	
	if(outlier==0)
		printf("No outliers\n");
	else 
		puts("");
}


void frequency(int n, int array[n], int big, int small)
{
	int classes, width, a, b, counter, upper, lower;
	char string[SIZE];

	printf("\nFrequency Distribution\n");

	printf("The number of classes or class size (should be between 5 and 20): ");
	scanf("%d", &classes);

	width=(float)(big-small)/classes;

	int freq[classes];

	for(a=0;a<classes;a++)
		freq[a]=0;
	
	//main part
	printf("%10s%15s%25s%20s\n", "Classes", "Frequency", "Relative_Frequency", "Histogram");
	for(a=0;a<classes;a++)
	{
		//Frequency Table
		lower=small+(width+1)*a;
		upper=small+width+(width+1)*a;
		
		sprintf(string, "%d-%d", lower, upper);//a function to assign numbers to a string
		printf("%10s", string);
 
		for(b=0;b<n;b++)
		{
			if(array[b]>=lower && array[b]<=upper)
				freq[a]++;
		}
		printf("%15d", freq[a] );		
		
		//Relative Frequency
		printf("%25.3f", (float)freq[a]/n );

		//Histogram
		for(counter=1;counter<=11;counter++)
			printf(" ");
		for(counter=1;counter<=freq[a];counter++)
			printf("%c", '*');
		
		puts("");
	}
}
