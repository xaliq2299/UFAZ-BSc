#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define ERROR   1.e-20 // Acceptable precision
#define MAX_VAL 5      // Random values are [0, MAX_VAL]
// Matrix and vector sizes (5120: UHD TV)
#define N 51200000

// Reference computation kernel (do not touch)
void stencil1D_reference(double a[N], double b[N]) {
  for (size_t i = 1; i < N; i++) {
    a[i] = (a[i] + a[i - 1]) / 2;
    b[i] = (b[i] + b[i - 1]) / 2;
  }
}

// Computation kernel (to parallelize)
void stencil1D_kernel(double a[N], double b[N]) {
  #pragma omp sections
  {
    #pragma omp section
  for (size_t i = 1; i < N; i++) {
    a[i] = (a[i] + a[i - 1]) / 2;
  }
    #pragma omp section

  for (size_t i = 1; i < N; i++) {
    b[i] = (b[i] + b[i - 1]) / 2;
  }
}
}

int main() {
  double* a     = malloc(N * sizeof(double));
  double* b     = malloc(N * sizeof(double));
  double* ref_a = malloc(N * sizeof(double));
  double* ref_b = malloc(N * sizeof(double));
  double time_reference, time_kernel;

  // Initialization by random values
  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < N; i++) {
    a[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
    b[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
    ref_a[i] = a[i];
    ref_b[i] = b[i];
  }

  time_reference = omp_get_wtime();
  stencil1D_kernel(ref_a, ref_b);
  time_reference = omp_get_wtime() - time_reference;
  printf("Reference time : %3.5lf s\n", time_reference);

  time_kernel = omp_get_wtime();
  stencil1D_reference(a, b);
  time_kernel = omp_get_wtime() - time_kernel;
  printf("Kernel time    : %3.5lf s\n", time_kernel);

  // Check if the result differs from the reference
  for (size_t i = 0; i < N; i++) {
    //if ((abs(ref_a[i] - a[i]) > ERROR) || (abs(ref_b[i] - b[i]) > ERROR) {
    if ((ref_a[i] != a[i]) || (ref_b[i] != b[i])) {
      printf("Bad results :-(((\n");
      exit(1);
    }
  }
  printf("OK results :-)\n");

  free(a);
  free(b);
  free(ref_a);
  free(ref_b);
  return 0;
}