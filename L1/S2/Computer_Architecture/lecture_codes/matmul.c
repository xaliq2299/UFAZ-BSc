#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VAL 5  // Random values are [0, MAX_VAL]

// Matrix size
#define N 1000

// Reference computation kernel (do not touch)
void matmul_reference(double C[N][N], double A[N][N], double B[N][N]) {
  size_t i, j, k;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      C[i][j] = 0.;
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// Computation kernel (try to optimize it)
void matmul_kernel(double C[N][N], double A[N][N], double B[N][N]) {
  size_t i, j, k;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      C[i][j] = 0.;
    }
  }
  for (i = 0; i < N; i++) {
    for (k = 0; k < N; k++) {
      for (j = 0; j < N; j++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  double* A   = malloc(N * N * sizeof(double));
  double* B   = malloc(N * N * sizeof(double));
  double* C   = malloc(N * N * sizeof(double));
  double* ref = malloc(N * N * sizeof(double));
  clock_t time_reference, time_kernel;

  // Initialization by random values
  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < N * N; i++) {
    A[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
    B[i] = (float)rand()/(float)(RAND_MAX/MAX_VAL);
  }

  time_reference = clock();
  matmul_reference((double (*)[N])ref, (double (*)[N])A, (double (*)[N])B);
  time_reference = clock() - time_reference;
  printf("Reference time : %3.5lf s\n", ((double)time_reference) / CLOCKS_PER_SEC);

  time_kernel = clock();
  matmul_kernel((double (*)[N])C, (double (*)[N])A, (double (*)[N])B);
  time_kernel = clock() - time_kernel;
  printf("Kernel time    : %3.5lf s\n", ((double)time_kernel) / CLOCKS_PER_SEC);

  // Check if the result differs from the reference
  for (size_t i = 0; i < N*N; i++) {
    if (ref[i] != C[i]) {
      printf("Bad results :-(((\n");
      exit(1);
    }
  }
  printf("Results are the same :-)\n");

  free(A);
  free(B);
  free(C);
  free(ref);
  return 0;
}
