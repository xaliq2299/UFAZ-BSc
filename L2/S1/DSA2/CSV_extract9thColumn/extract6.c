#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract6AndPrint(char *filename){
	FILE *fp;  char str[200], *token;

	fp = fopen(filename,"r");
	if(!fp){
		printf("%s\n", "File couldn't be opened");
		exit(1);
	}
/*	//while(!feof(fp)){
		int i=2;
		fscanf(fp, "%s", str);
		printf("%s\n", str);
		token = strtok(str,";");
		printf("%s\n", token);
		while(token){
			token = strtok(NULL, ";");
			i++;
			if(i == 5){
				printf("%s\n", token);
//				break;
			}
			else
				printf("%s\n", token);
		}*/
/*	col=1; bFirstTokenIsTaken=0
	go through the string (not i=0, but simple i)
		if(col == 3){
			if(next character == ';')
				return " ";
			else
				strtok;
			break;
		}
		else
			if current character == ';'
				return " ";
				col++;
			else	
				col++;
				strtok
				for loop until getting to the next ';' delimiter
			    if(next != ';') i++;
*/
/*	while(!feof(fp)){
		fscanf(fp, "%s", str);
		int col=1, bFirstTokenIsTaken=0, i=0;
		for(int i;str[i]!='\n';i++){
			if(col == 6){
				if(str[i+1] == ';')
					printf("\n"); //empty column
				else{
					if(bFirstTokenIsTaken)
						token=strtok(NULL,";");
					else{
						token=strtok(str,";");
						bFirstTokenIsTaken=1;
					}
					printf("%s\n", token);
				}
			}
			else{
				if(str[i] == ';'){
					col++;
				}
				else{
					col++;
					if(bFirstTokenIsTaken)
						token=strtok(NULL,";");
					else{
						token=strtok(str,";");
						bFirstTokenIsTaken=1;
					}
					while(str[i] != ';')
						i++;
					if(str[i+1] != ';') i++;	
				}
			}
		}
	}
/*
*/
/*	fscanf(fp, "%s", str);
	printf("str=%s\n", str);
	token = strtok(str,";");
	printf("token=%s\n", token);
	token = strtok(NULL,";");
	printf("token=%s\n", token);	
	token = strtok(NULL,";");
	printf("token=%s\n", token);
	fclose(fp);
	}*/
	int count=1, nNbOfTokens=0, i;
	fscanf(fp, "%s", str);
//	printf("%c\n", str[125]);
	for(int i;str[i]!='\0';i++){
		if(count == 5) break;
		if(str[i] == ';' || str[i] == '\n')
			count++;
		else{
			nNbOfTokens++;
			for(int i;str[i] != ';';i++);
		}
	}
	if(str[i+1] == ';') printf("\n");
	else {
		token = strtok(str,";"); nNbOfTokens--;
		while(nNbOfTokens){
			token = strtok(NULL, ";");
			nNbOfTokens--;
		}
		printf("%s\n", token);
	}
	for(i;str[i] != '\0';i++);
}
//}

int main(){
	extract6AndPrint("Mn_Runs_GP.csv");
	return 0;
}
