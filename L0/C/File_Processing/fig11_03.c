#include <stdio.h> //in standard input output library we have also function that work with files: they all start with f which indicates to 
		   // the word "file".

int main()
{
	int account;
	char name[ 30 ];
	double balance;
	
	FILE *cfPtr; //Pointer to the file with its name, cfPtr

	if( (cfPtr=fopen("clients.dat", "w")) == NULL )	//if this file doesn't exist the program will create a file of this name
	{						//here we use write mode("w"). 
							//If we were using read("r"), as it will only read the file,
	  printf("File could ot be opened");		//it wil not create a file of this name 
	}						//aftereachcompilaion,thefilewillcreate						
							


							//if we use mode a(????), 
	else
	{ 							
	printf("Enter the account, name, balance\n");	
	printf("Enter EOF to end input\n");
        printf("?");//ask do you want more data
	scanf("%d%s%lf", &account, name, &balance);// to save the data first of all program should open and see themandthensave		
		while( !feof(stdin) )
		{
	//we will do the some stuff
	//how to use function fprintf
        	fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );//this is called "record", very similar to STRUCTURE!!!
		printf("?");//ask do you want more data
		scanf("%d%s%lf", &account, name, &balance);// to save the data first of all program should open and see them and then save
	
		fclose( cfPtr ); // it is important to close the file		
		}	
	}

	return 0;
}

