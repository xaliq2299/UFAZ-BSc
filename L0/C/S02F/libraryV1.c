#include <stdio.h>
#include <string.h>
#define NBMAX 100

typedef struct {
	int number; // reference
	char author[30]; // name of the author
	char editor[30]; // name of the editor
	char title[100]; // Title of the book
	int stock; // quantity available in the stock
	}Typebook;

	Typebook data[NBMAX];//initialize, very important!!

void createData(FILE *fp); 
void printData(FILE *fp, FILE *fptr);
void newBook(FILE *fp);
void deleteBook(FILE *fp);
void commandBook(FILE *fp);
void updateBook(FILE *fp);

int main()
{
	int choice1, choice2;	
	FILE *fp, *fptr;
	printf("1-Create a new database for the library under the name \"UFAZLib.dat\"\n"
	       "2-Use existing database\n"
	       "3-Exit the program\n");

	printf("Which one do you want? ");
	scanf("%d", &choice1);

	switch(choice1)
	{
		case 1: createData(fp); break;   
		case 2: printf("1)Enter a new book to the database\n"
			       "2)Delete a book from the database\n"
			       "3)Order a book from the database\n"
			       "4)Update information of a book in the database\n"
			       "5)Print all database in a readable file\n"
			       "6)End options (leave)\n");
		 	printf("Enter one of these options: ");
			scanf("%d", &choice2);
			switch(choice2)
			{
				case 1: newBook(fp); break; 				
				case 2: deleteBook(fp); break;				
				case 3: commandBook(fp); break;				
				case 4: updateBook(fp); break;				
				case 5: printData(fp, fptr); break;			
				case 6: return 1;
			}	
		case 3: return 1;
	}

return 0;
}


void createData(FILE *fp)
{
	fp=fopen("UFAZLib.dat", "w");	
	if(fp!=NULL)	
	fclose(fp);
}


void printData(FILE *fp, FILE *fptr)
{
	int a=0, check=0;	

	fp=fopen("UFAZLib.dat", "r");	
	
	while(!feof(fp))
	{	
			fscanf(fp, "%d%s%s%s%d\n", &data[a].number, data[a].author, data[a].editor, data[a].title, &data[a].stock);  	
			check++;	
			a++;	
	}	
	fclose(fp);	

	fptr=fopen("UFAZbooks.txt", "w");
	
	fprintf(fptr, "%s%20s%20s%20s%20s\n", "RefNum", "Author", "Editor", "Title", "Stock"); 	
	for(a=0;a<check;a++)
		fprintf(fptr, "%6d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock);	
	
	fclose(fptr);
}


void newBook(FILE *fp)
{
	int a=0, check=0;

	fp=fopen("UFAZLib.dat", "r+");
	if(fp == NULL)
	{
		printf("File does not exist\n");
		return;	
	}
	else	
	{
	while(!feof(fp))
	{	
			fscanf(fp, "%d%s%s%s%d\n", &data[a].number, data[a].author, data[a].editor, data[a].title, &data[a].stock);  	
			check++;	
			a++;	
	}	
	printf("Enter the reference number: ");
	scanf("%d", &data[check].number);
	printf("Author: ");
	scanf("%s", data[check].author);
	printf("Editor: ");
	scanf("%s", data[check].editor);
	printf("Title: ");
	scanf("%s", data[check].title);
	printf("Stock: ");
	scanf("%d", &data[check].stock);
	
	fprintf(fp, "%d%20s%20s%20s%20d\n", data[check].number, data[check].author, data[check].editor, data[check].title, data[check].stock);
	}
	
	fclose(fp);
}

void deleteBook(FILE *fp)
{
	int a=0, ref, check=0;

	printf("Enter the reference number: ");
	scanf("%d", &ref);
	
	fp=fopen("UFAZLib.dat", "r");

	while(!feof(fp))
	{
		fscanf(fp, "%d%s%s%s%d\n", &data[a].number, data[a].author, data[a].editor, data[a].title, &data[a].stock);
		a++;
		check++;
	}	
			
	fclose(fp);	

	fp=fopen("UFAZLib.dat", "w");
	
	for(a=0;a<check;a++)
	{
		if(ref==data[a].number)		
		continue;
		fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock);
	}

	fclose(fp);
}

void commandBook(FILE *fp)
{	
	int a=0, ref, check=0;	
	
	printf("Enter the reference number: ");
	scanf("%d", &ref);
	
	fp=fopen("UFAZLib.dat", "r");
	
	while(!feof(fp))
	{
		fscanf(fp, "%d%s%s%s%d\n", &data[a].number, data[a].author, data[a].editor, data[a].title, &data[a].stock);
		a++;
		check++;
	}	
	fclose(fp);

	for(a=0;a<check;a++)
	{
		if(ref==data[a].number)	
		{
			if(data[a].stock!=0)		
			{
				printf("Author: %s\nEditor: %s\nTitle: %s\n", data[a].author, data[a].editor, data[a].title );
				fp=fopen("UFAZLib.dat", "w");
				for(a=0;a<check;a++)
				{
					if(ref==data[a].number)		
					fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock-1);
					else
					fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title,  data[a].stock);
				}
				fclose(fp);		
			}		
			else
			{
				printf("There is no stock quantity of this book\n"); 
				break;		
			}	
		}
	}
}

void updateBook(FILE *fp)
{
	int ref, choice, a=0, check=0, stock, try=0;//variable try was intitialized just to manage to say there is no book of this
						    //reference number
	char author[15], editor[15], title[20];

	printf("Enter the reference number: ");
	scanf("%d", &ref);
	
	printf("1- change the author name\n"
	       "2- change the editor\n"
	       "3- change the title (without space in the title)\n"
	       "4- change the stock value\n"
	       "5- finish updating\n");
	scanf("%d", &choice);

	fp=fopen("UFAZLib.dat", "r");

	while(!feof(fp))
	{
		fscanf(fp, "%d%s%s%s%d\n", &data[a].number, data[a].author, data[a].editor, data[a].title, &data[a].stock);
		a++;
		check++;
	}	
	
	fclose(fp);	
	
	for(int b=0;b<check;b++)
	{
		if(data[b].number==ref)
		{
			try++;		
			switch(choice)
			{
			case 1: printf("New author name: ");
				scanf("%s", author);
				strcpy(data[b].author, author);
			 	fp=fopen("UFAZLib.dat", "w");
				for(a=0;a<check;a++)				
				fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock);	
				break;			
			case 2: printf("New editor: ");	
				scanf("%s", editor); 
				strcpy(data[b].editor, editor);
				fp=fopen("UFAZLib.dat", "w");
				for(a=0;a<check;a++)				
				fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock);	
				break;			
			case 3: printf("New title: ");
				scanf("%s", title); 
				strcpy(data[b].title, title);
				fp=fopen("UFAZLib.dat", "w");
				for(a=0;a<check;a++)				
				fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock);	
				break;			
			case 4: printf("New stock value: ");		
				scanf("%d", &stock); 	
				data[b].stock=stock;		
				fp=fopen("UFAZLib.dat", "w");
				for(a=0;a<check;a++)				
				fprintf(fp, "%d%20s%20s%20s%20d\n", data[a].number, data[a].author, data[a].editor, data[a].title, data[a].stock);			
				break;
			case 5: return;
			default: return;
			}		
		}
	}
	if(try==0)
	printf("There is no book of this reference number\n");
}
