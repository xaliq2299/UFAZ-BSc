#include <stdio.h>

int main () {
int grade, total=0, counter=0, average;

while(counter<=10) {
printf ("Enter grade:");
scanf("%d", &grade);
total=total+grade;
counter=counter+1;
}

average=total/10;
printf("Class average is %d\n", average);
return 0;
}
