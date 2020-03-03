#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	switch(argv[2][0]){
		case '+': printf("%.3f\n", atof(argv[1])+atof(argv[3])); break;
		case '-': printf("%.3f\n", atof(argv[1])-atof(argv[3])); break;
		case 'x': printf("%.3f\n", atof(argv[1])*atof(argv[3])); break;
		case '/': printf("%.3f\n", atof(argv[1])/atof(argv[3])); break;
	}

	return 0;
}
