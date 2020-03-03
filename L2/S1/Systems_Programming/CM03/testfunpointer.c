#include <stdio.h>
int sum(int num1, int num2){ return num1+num2;}
int mult(int num1, int num2){return num1*num2;}

int main(){
/* The following two lines can also be written in a single 
 * statement like this: void (*fun_ptr)(int) = &fun;
 */
 int (*f2p)(int, int);
 f2p = sum;
 //Calling function using function pointer
 int op1 = f2p(10,13);
 printf("Output1: Call using function pointer: %d\n", op1);
 //Calling function in normal way using function name
 int op2 = sum(10,13);
 printf("Output2: Call using function name: %d\n", op2);
 
 f2p = mult;
 int op3 = f2p(10,13);
 printf("Output3: Call using function name: %d\n", op3);
 
 return 0;
}
