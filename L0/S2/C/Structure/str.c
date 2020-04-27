#include <stdio.h>

int main()
{
struct student{
char FirstName[10];
char SurName[10];
int age;
char size;
int height;
};

struct student S1, S2[3], *S3;

typedef struct student Student;//it is about naming, we changed the name 

printf("Give the age PLEASE:\n");
scanf("%d", &S1.age);

scanf("%s", S1.FirstName);//we can not compare two structures, but the elements of them one by one are comparable

for(int i=0;i<10;i++)
printf("%c", S1.FirstName[i]);
//We can assign 2 structures, make them equal
puts("");
/*for pointer like S3 in our code to 
point exactly to some variable inside the structure we can use:
a) S3->age
b) (*S3).age
*/
return 0;
}//we pass the elements of values (not references) of structure to functions
//bur=t pointers and arrays by references
