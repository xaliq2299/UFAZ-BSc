#include <stdio.h>

int main() {
  int fin = 0;

  #pragma omp parallel sections
  {   
      #pragma omp section
      {
        while (!fin){
         #pragma omp critical
        {
          if(!fin)
           printf("Pas fini\n");
         }
        }
      }
    
    
    #pragma omp section
    {
      #pragma omp critical
      {
      fin = 1;
      printf("Fini\n");
      }
    }
  }
  return 0;
}