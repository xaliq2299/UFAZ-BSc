#include <stdio.h>
	int main() 
	  {
	    #if __STDC__ == 0 && !defined(__cplusplus)
	         printf("cc is not ANSI C compliant\n");
	     #else
	     printf(" %s compiled at %s:%s. This statement is at   line    %d\n", __FILE__, __DATE__, __TIME__, __LINE__);
	     #endif
			return 0;
	 }
