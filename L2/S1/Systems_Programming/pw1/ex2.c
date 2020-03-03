	#include <stdio.h>
#include <string.h>

struct month {
	char name[9+1]; /* name */
	int days; /* number of days in the month */
};

int main(){
	char request[10];
	struct month Months[12];
	strcpy(Months[0].name,"January");	Months[0].days = 31; 	
	strcpy(Months[1].name, "February");	Months[1].days = 28; 
	strcpy(Months[2].name,"March");	Months[2].days = 31; 
	strcpy(Months[3].name, "April");	Months[3].days = 30;
	strcpy(Months[4].name, "May");	Months[4].days = 31; 
	strcpy(Months[5].name, "June");	Months[5].days = 30; 
	strcpy(Months[6].name, "July");	Months[6].days = 31; 
	strcpy(Months[7].name, "August");	Months[7].days = 31; 
	strcpy(Months[8].name, "September");	Months[8].days = 30; 
	strcpy(Months[9].name, "October");	Months[9].days = 31; 
	strcpy(Months[10].name, "November");	Months[10].days = 30; 
	strcpy(Months[11].name, "December");	Months[11].days = 31;

	int flag=0;
	fgets(request, 20, stdin);
	request[strlen(request)-1]='\0'; //did this because fgets
									 //automatically puts \n as the last character for the string
	for(int i=0;i<12;i++){
		if(strcmp(request, Months[i].name) == 0){
			printf("Month %d: %d days\n", i+1, Months[i].days);
			flag=1; break;
		}
	}
	if(flag == 0)
		printf("This is not an existing month\n");

	return 0;
}