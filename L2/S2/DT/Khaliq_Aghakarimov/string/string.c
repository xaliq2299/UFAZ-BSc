#include "string.h"

int length(char *str){
	int counter=0;
	for(int i=0;str[i] != '\0';i++)
		counter++;
	return counter;
}

int compare(char *str1, char *str2){
	int i, j, l1, l2, limit;
	l1=length(str1);
	l2=length(str2);
	if(l1!=l2) return 1;
	for(i=0, j=0;i<l1;i++, j++){
		if(str1[i] != str2[j])
			return 1;
	}
	return 0;
}

int palindrome(char *str){
	int l = 0;
    int h = length(str) - 1;
  
    while (h > l) { 
        if (str[l++] != str[h--])
            return 0;
    } 
	return 1;
}