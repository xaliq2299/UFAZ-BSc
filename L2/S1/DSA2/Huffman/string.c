#include "string.h"
//--------------------------------------------
char* str_append(char *str, char c){
	int i;
	for(i=0;str[i] != '\0';i++);
	str[i] = c;
	str[++i] = '\0';
	return str;
}
//---------------------------------------------
char* str_remove(char *str){
	int i;
	for(i=0;str[i] != '\0';i++);
	str[--i] = '\0';
	return str;
}