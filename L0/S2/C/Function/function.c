#include <stdio.h>
#include <math.h>

float square(float a) { /*prototype function, means declaration of a function;
if we have any function in any library, calling it will be enough, but if
and only if this function exists in our library.*/
//here we created our own function

return sqrt(a);
}
int main () {
int x;
for (x=1; x<=10; x++) {
printf("\t\tsquare root of %d is %f\n", x, square(x));
}
return 0;
}
