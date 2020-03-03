#include <stdio.h>

int main(){
	char string[20], stringNew[25];
	printf("Enter a string: ");
	fgets(string, 20, stdin);
	//printf("The previous string: %s\n", string);
	
	int iNewString=0;
	for(int i=0;string[i] != '\0';i++){
		if(string[i]>32 && string[i]<=126)
			stringNew[iNewString++]=string[i];
		else{
			switch(string[i]){
				case '\n': stringNew[iNewString++]='\\';
				           stringNew[iNewString++]='n';
						   break;
				case '\r': stringNew[iNewString++]='\\';
				           stringNew[iNewString++]='r';
						   break;
				case '\t': stringNew[iNewString++]='\\';
				           stringNew[iNewString++]='t';
						   break;
				case '\b': stringNew[iNewString++]='\\';
				           stringNew[iNewString++]='b';
						   break;
				case '\\': stringNew[iNewString++]='\\';
				           stringNew[iNewString++]='\\';
						   break;
				case '\"': stringNew[iNewString++]='\\';
				           stringNew[iNewString++]='"';
						   break;
				default:   
						   printf("Octal code: %o\n", string[i]); 
				           break;
			}
		}
	}
//	stringNew[iNewString]='\0';
	printf("A new string: %s\n", stringNew);
	return 0;
}