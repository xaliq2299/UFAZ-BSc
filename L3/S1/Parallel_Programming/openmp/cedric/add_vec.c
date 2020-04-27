#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define ERROR   1.e-20 // Acceptable precision
#define MAX_VAL 5      // Random values are [0, MAX_VAL]

// Matrix and vector sizes (5120: UHD TV)
#define N 5120000

// Reference computation kernel (do not touch)
void addvec_reference(double c[N], double a[N], double b[N]) {

  for (size_t i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }
}

// Computation kernel (to parallelize)
void addvec_kernel(double c[N], double a[N], double b[N]) {
  
  for (size_t i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }
}

int main() {
  double* a   = malloc(N * sizeof(double));
  double* b   = malloc(N * sizeof(double));
  double* c   = malloc(N * sizeof(double));
  double* ref = malloc(N * sizeof(double));
  double time_reference, time_kernel;

  // Initialization by random values
  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < N; i++) {
    a[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
    b[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
  }

  time_reference = omp_get_wtime();
  addvec_reference(ref, a, b);
  time_reference = omp_get_wtime() - time_reference;
  printf("Reference time : %3.5lf s\n", time_reference);

  time_kernel = omp_get_wtime();
  addvec_kernel(c, a, b);
  time_kernel = omp_get_wtime() - time_kernel;
  printf("Kernel time    : %3.5lf s\n", time_kernel);

  // Check if the result differs from the reference
  for (size_t i = 0; i < N; i++) {
    //printf("ref[%2d] = %f, c[%d] = %f\n", i, ref[i], i, c[i]);
    //if (abs(ref[i] - c[i]) > ERROR) {
    if (ref[i] != c[i]) {
      printf("Bad results :-(((\n");
      exit(1);
    }
  }
  printf("OK results :-)\n");

  free(a);
  free(b);
  free(c);
  free(ref);
  return 0;
}