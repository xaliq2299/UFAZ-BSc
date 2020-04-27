#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

// Matrix size
#define N 2500

// Random values are in [0, MAX_VAL]
#define MAX_VAL 5

// Number of checks
#define NBCHECKS 10

// Acceptable error (in check)
#define ERROR   1.e-20

#define TIMEDIFF(a, b) (((b).tv_sec  - (a).tv_sec) + \
                        ((b).tv_usec - (a).tv_usec) / 1000000.)

// Global variables to avoid stack overflow
double a[N][N], b[N][N], c[N][N];

int main() {
  struct timeval tv_init, tv_begin, tv_end;
  gettimeofday(&tv_init, NULL);

  //---------------------------------------------------------------------------
  // Initialization
  srand((unsigned int)time(NULL));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      b[i][j] = (double)rand() / (double)(RAND_MAX / MAX_VAL);
      a[i][j] = (double)rand() / (double)(RAND_MAX / MAX_VAL);
    }
  }

  //---------------------------------------------------------------------------
  // Compute
  gettimeofday(&tv_begin, NULL);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i][j] = 0.;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < N; k++) {
      for (int j = 0; j < N; j++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  gettimeofday(&tv_end, NULL);

  //---------------------------------------------------------------------------
  // Check some values randomly
  int check_ok = 1;
  for (int checks = 0; checks < NBCHECKS; checks++) {
    int i = rand() % N;
    int j = rand() % N;
    double val = 0.;
    for (int k = 0; k < N; k++) {
      val += a[i][k] * b[k][j];
    }
    if (fabs(val - c[i][j]) > ERROR) {
      fprintf(stderr, "BAD RESULTS ! ");
      fprintf(stderr, "Value[%d][%d] = %g should be %g\n", i, j, c[i][j], val);
      check_ok = 0;
    }
  }
  if (check_ok) {
    fprintf(stderr, "OK results :)\n");
  }

  //---------------------------------------------------------------------------
  // Execution times
  printf("Init : %lfs, Compute : %lfs\n",
      TIMEDIFF(tv_init, tv_begin),
      TIMEDIFF(tv_begin, tv_end));

  return 0;
}