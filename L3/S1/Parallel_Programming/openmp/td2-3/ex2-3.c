#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define max(x,y) ((x) > (y)? (x) : (y))
#define min(x,y) ((x) < (y)? (x) : (y))
#define ERROR    1.e-20 // Acceptable precision
#define MAX_VAL  5      // Random values are [0, MAX_VAL]
// Matrix and vector sizes (5120: UHD TV)
#define N 5120

// Reference computation kernel (do not touch)
/**
 * polynomial_multiply function:
 * this function computes the polynomial multiply c = a * b,
 * each polynomial is represented using an array, the value stored
 * in the n^th cell corresponds to the coefficient of x^n. E.g.:
 * a = (3.x^2 + 2.x + 1) is represented by [3, 2, 1],
 * b = (2.x^2 + 3.x) is represented by [2, 3, 0] and the result of
 * a * b = 6.x^4 + 13.x^3 + 6.x^2 + 3.x is [6, 13, 6, 3, 0].
 * \param c is the target polynomial, must be initialized to 0
 * \param a is the first polynomial
 * \param b is the second polynomial
 */
void polynomial_multiply_reference(double c[2*N-1], double a[N], double b[N]) {
  for (size_t i = 0; i < N; i++)
    for (size_t j = 0; j < N; j++)
      c[i+j] += a[i] * b[j];
}

// Computation kernel (to parallelize)
void polynomial_multiply_kernel(double c[2*N-1], double a[N], double b[N]) {
  for (size_t i = 0; i < N; i++)
    for (size_t j = 0; j < N; j++)
      c[i+j] += a[i] * b[j];  
}

int main() {
  double* a     = malloc(N * sizeof(double));
  double* b     = malloc(N * sizeof(double));
  double* c_ref = malloc((2*N - 1) * sizeof(double));
  double* c_ker = malloc((2*N - 1) * sizeof(double));
  double time_reference, time_kernel;

  // Initialization of a and b by random values, and c by 0
  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < N; i++) {
    a[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
    b[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
  }
  for (size_t i = 0; i < 2*N - 1; i++) {
    c_ref[i] = c_ker[i] = 0.;
  }

  time_reference = omp_get_wtime();
  polynomial_multiply_reference(c_ref, a, b);
  time_reference = omp_get_wtime() - time_reference;
  printf("Reference time : %3.5lf s\n", time_reference);

  time_kernel = omp_get_wtime();
  polynomial_multiply_kernel(c_ker, a, b);
  time_kernel = omp_get_wtime() - time_kernel;
  printf("Kernel time    : %3.5lf s\n", time_kernel);

  // Check if the result differs from the reference
  for (size_t i = 0; i < 2*N - 1; i++) {
    //if (abs(c_ref[i] - c_ker[i]) > ERROR) {
    if (c_ref[i] != c_ker[i]) {
      printf("Bad results :-(((\n");
      exit(1);
    }
  }
  printf("OK results :-)\n");

  free(a);
  free(b);
  free(c_ref);
  free(c_ker);
  return 0;
}