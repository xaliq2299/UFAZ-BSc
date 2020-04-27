#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N                      10000 // Size of the triangular array.
#define NB_FIRST_ROWS_TO_PRINT 5     // Number of rows to print

/* ------------------------------------------------------------------------ *
 *      UTILITY FUNCTIONS NOT USEFUL FOR YOUR PURPOSE - DO NOT TOUCH        *
 * ------------------------------------------------------------------------ */

/**
 * triangle_alloc function:
 * this function allocates the memory for a 2-dimensional triangular array
 * of a given size. The entries of the triangle are initialized to 0.
 * \param[in] size Size of the 2-dimensional triangle aray.
 * \return A pointer to an allocated 2-dimensional triangular array.
 */
double** triangle_alloc(size_t size) {
  size_t i;
  double* storage;
  double** triangle;

  // Allocate a storage for the triangle (consecutively in memory).
  storage = calloc((size * (size + 1)) / 2, sizeof(double));
  // Allocate and set the pointers to the beginning of each line.
  triangle = malloc(size * sizeof(double*));
  for (i = 0; i < size; i++) {
    triangle[i] = storage;
    storage += i + 1;
  }

  return triangle;
}

/**
 * triangle_free function:
 * this function frees the allocated memory space for a 2-dimensional
 * triangular array.
 * \param[in] triangle Pointer to the 2-dimensional triangular array.
 */
void triangle_free(double** triangle) {

  // Free the storage.
  free(triangle[0]);
  // Free the array of pointer to triangle lines.
  free(triangle);
}

/**
 * triangle_print function:
 * this function pretty-prints the content of a 2-dimensional triangle
 * array.
 * \param[in] size Size of the 2-dimensional triangular array.
 * \param[in] A    Pointer to the 2-dimensional triangular array.
 */
void triangle_print(size_t size, double** triangle) {
  size_t i, j;

  for (i = 0; i < size; i++) {
    for (j = 0; j <= i; j++)
      printf(" %6.3lf ", triangle[i][j]);
    printf("\n");
  }
}

/**
 * triangle_equal function:
 * this function returns 1 if the two triangular arrays t1 and t2
 * have similar content, 0 otherwise.
 * \param[in] size Size of the 2-dimensional triangular arrays.
 * \param[in] t1   Triangular array to be checked equal to t2.
 * \param[in] t2   Triangular array to be checked equal to t1.
 * \return 1 if t1 and t2 are equal (content-wise), 0 otherwise.
 */
int triangle_equal(size_t size, double** t1, double** t2) {
  size_t i, j;

  for (i = 0; i < size; i++)
    for (j = 0; j <= i; j++)
      if (t1[i][j] != t2[i][j])
        return 0;
  return 1;
}

/**
 * pascal function:
 * this function puts a Pascal triangle inside a triangular array.
 * \param[in] size     The size of the triangular array.
 * \param[in] triangle The triangular array to use.
 */
void pascal_reference(size_t size, double** triangle) { 
  size_t i, j;

  for (i = 0; i < size; i++) {
    triangle[i][0] = 1;
    triangle[i][i] = 1;
  }
  
  for (i = 1; i < size; i++) {
    for (j = 1; j < i; j++) {
        triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
    }
  }
}

/* ------------------------------------------------------------------------ *
 *       FUNCTIONS YOU HAVE TO PARALLELIZE USING OpenMP - DO TOUCH !        *
 * ------------------------------------------------------------------------ */

/**
 * pascal function:
 * this function puts a Pascal triangle inside a triangular array.
 * \param[in] size     The size of the triangular array.
 * \param[in] triangle The triangular array to use.
 */
void pascal(size_t size, double** triangle) { 
  size_t i, j;

  #pragma omp parallel for // We can see that the following loop is parallel, so the parallelization is achieved through 'for' directive
  for (i = 0; i < size; i++) {
    triangle[i][0] = 1;
    triangle[i][i] = 1;
  }

  for (i = 1; i < size; i++) {
    #pragma omp parallel for // The similar scenario here, since after fixing the 'i' iteration variable we can parallelize the for loop of iteration variable 'j'
    for (j = 1; j < i; j++) {
      triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
    }
  }
  // As a result I have a speeedup > 1 ))).
}

/* ------------------------------------------------------------------------ *
 *                      MAIN FUNCTION - DO NOT TOUCH                        *
 * ------------------------------------------------------------------------ */

int main() {
  double** reference = triangle_alloc(N);
  double** triangle1 = triangle_alloc(N);
  double t1, t2;

  // Reference computation
  t1 = omp_get_wtime();
  pascal_reference(N, reference);
  t2 = omp_get_wtime();
  printf("Reference time: %lfs\n", t2 - t1);
  
  // Parallel computation
  t1 = omp_get_wtime();
  pascal(N, triangle1);
  t2 = omp_get_wtime();
  printf("Kernel time   : %lfs\n", t2 - t1);

  if (!triangle_equal(N, reference, triangle1))
    fprintf(stderr, "Bad results :-(((\n");
  else
    fprintf(stderr, "OK results :-)\n");

  printf("First rows of the reference triangle: \n");
  triangle_print(NB_FIRST_ROWS_TO_PRINT, reference);
  printf("First rows of your triangle: \n");
  triangle_print(NB_FIRST_ROWS_TO_PRINT, triangle1);
  triangle_free(reference);
  triangle_free(triangle1);
  return 0;
}