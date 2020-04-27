#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

// -------------------------------------------------------
// Reference computation part (do not touch)

int fibor(int n) {
  if (n < 2)
    return n;

  return fibor(n-1) + fibor(n-2);
}

void fibonacci_reference(int n, int* fibo) {
  *fibo = fibor(n);
}

// -------------------------------------------------------
// Computation kernel (to parallelize)

int fibok(int n) {
  int n_minus_one, n_minus_two;

  if (n < 2)
    return n;

  if(n<20) // dont create tasks it n is too small
    return fibok(n-1)+fibok(n-2);
  /*#pragma omp parallel sections if (n>20)
  {
    #pragma omp section
      n_minus_one=fibok(n-1);
    #pragma omp section
      n_minus_two=fibok(n-2);
  }*/

 
      #pragma omp task shared(n_minus_one) // thread executing tasks must communicate the result (hence shared clauses)
      n_minus_one=fibok(n-1);
      #pragma omp task shared(n_minus_two)
      n_minus_two=fibok(n-2);

      #pragma omp taskwait // make sure that single thread get the result before returning the addition (hence taskwait)
  /*
  Problems:
  a) since function calls itself recursively, we create many many threads. Creating and killing them is costly.
  b) In addition, fibo(3) like small things is not worth anythin', which means there's no need to create thread for it which is costly again.
  */
  //return fibok(n-1) + fibok(n-2);
  return n_minus_one+n_minus_two;
}

void fibonacci_kernel(int n, int* fibo) {
  #pragma omp parallel // only one parallel region
  {
    #pragma omp single
      *fibo = fibok(n);
  }
}

// -------------------------------------------------------

int main(int argc, char* argv[]) {
  double time_reference, time_kernel;
  int n, fibo_ref, fibo_ker;
  
  if (argc != 2) { 
    fprintf(stderr, "usage: %s number\n", argv[0]);
    exit(1);
  }
  n = atoi(argv[1]);

  time_reference = omp_get_wtime();
  fibonacci_reference(n, &fibo_ref);
  time_reference = omp_get_wtime() - time_reference;
  printf("Reference time : %3.5lf s\n", time_reference);
  
  time_kernel = omp_get_wtime();
  fibonacci_kernel(n, &fibo_ker);
  time_kernel = omp_get_wtime() - time_kernel;
  printf("Kernel time    : %3.5lf s\n", time_kernel);

  // Check if the result differs from the reference
  if (fibo_ref != fibo_ker) {
    printf("Bad results :-(((\n");
    printf("Reference: fibo(%d) = %d\n", n, fibo_ref);
    printf("Kernel:    fibo(%d) = %d\n", n, fibo_ker);
    exit(1);
  }
  printf("fibo(%d) = %d\n", n, fibo_ref);
  printf("OK results :-)\n");

  return 0;
}