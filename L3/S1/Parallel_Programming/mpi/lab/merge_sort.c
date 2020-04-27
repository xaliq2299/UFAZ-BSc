#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define N 16777216

// Prototypes of checking functions 
void check_init(int*);
int check(int*);
int check_is_power_of_two(int);
  
// compare function: compare two integer values (pointed by parameters
// p1 and p2), in a way compatible with C's library qsort function
int compare(const void* p1, const void* p2) {
  int v1 = *(int*)p1;
  int v2 = *(int*)p2;

  if (v1 < v2)
    return -1;
  else if (v2 < v1)
    return 1;
  else
    return 0;
}

// merge function: merge two sorted arrays (array1 of size1 and
// array2 of size2) merged sorted array of size1 + size2
void merge(int* merged, int* array1, int size1, int* array2, int size2) {
  int i1 = 0, i2 = 0, ir = 0;

  while (i1 < size1 && i2 < size2) {
    if (array2[i2] < array1[i1])
      merged[ir++] = array2[i2++];
    else
      merged[ir++] = array1[i1++];
  }

  while (i1 < size1)
    merged[ir++] = array1[i1++];

  while (i2 < size2)
    merged[ir++] = array2[i2++];
}

// Global variables to avoid stack overflow
int array[N], sorted[N];

int main(int argc, char* argv[]) {
  // Initialization
  srand(time(0) + getpid());
  for (int i = 0; i < N; i++) {
    array[i] = rand() % N;
  }
  check_init(array);

  // -------------------------------------------------------------------------
  // Sorting starts here, "array" is the non-sorted array
  // -------------------------------------------------------------------------
  qsort(&array[0],   N/2, sizeof(int), compare);
  qsort(&array[N/2], N/2, sizeof(int), compare);
  merge(sorted, array, N/2, array + N/2, N/2);
  // -------------------------------------------------------------------------
  // Sorting finishes there, "merged" is the sorted array
  // -------------------------------------------------------------------------

  // Check that the output array has been adequatly sorted
  if (check(sorted)) {
    fprintf(stderr, "Error: the output array is not sorted\n");
    return 1;
  }

  return 0;
}

// ---------------------------------------------------------------------------
// Checking mechanism part (no need to read it)
// ---------------------------------------------------------------------------

int count[N];

// Print "sample_length" elements at the beginning and the end of the array
// "t" of "size" elements, starting with string "msg"
void check_print_sample(int* t, int size, int sample_length, char* msg) {
  if (msg != NULL) {
    fprintf(stderr, "%s", msg);
  }
  if (size <= 2 * sample_length) {
    for (int i = 0; i < size; i++)
      fprintf(stderr, "%d ", t[i]);
  } else {
    for (int i = 0; (i < size) && (i < sample_length); i++)
      fprintf(stderr, "%d ", t[i]);
    fprintf(stderr, "... ");
    for (int i = size - sample_length; i < size; i++)
      fprintf(stderr, "%d ", t[i]);
  }
  fprintf(stderr, "\n");
}

// Checking mechanism initialization function: this function puts in the i^th
// entry of array "count" the number of values "i" in the array "t"
void check_init(int* t) {
  // Print few values of the array for visual feedback
  check_print_sample(t, N, 5, "Input array:  ");
  for (int i = 0; i < N; i++)
    count[i] = 0;
  for (int i = 0; i < N; i++)
    count[t[i]]++;
}

// Checking function: return 0 if the array "t" is sorted, 1 otherwise. For
// this function to work, the user must call the check_init function with
// the non-sorted array as argument before calling this function
int check(int* t) {
  // Print few values of the array for visual feedback
  check_print_sample(t, N, 5, "output array: ");

  // Check that the entries of "t" are ordered and that the number of
  // occurences of each entry corresponds to the content of "count"
  int nb = 1;
  for (int i = 1; i < N; i++) {
    if (t[i-1] == t[i]) {
      nb++;
    }
    else if (t[i-1] > t[i]) {
      fprintf(stderr, "Error (%d > %d at index %d-%d)\n", t[i-1], t[i], i-1, i);
      return 1;
    } else {
      // Check the number of occurences of the previous value
      if (count[t[i-1]] != nb) {
        fprintf(stderr, "Error (bad count for %d: %d, should be %d)\n",
            t[i-1], nb, count[t[i-1]]);
        return 1;
      }
      nb = 1;
    }
  }
  // Check the number of occurences of the last value
  if(count[t[N-1]] != nb) {
    fprintf(stderr, "Error (bad count for %d: %d, should be %d)\n",
        t[N-1], nb, count[t[N-1]]);
    return 1;
  }
  fprintf(stderr, "Output array is sorted :)\n");
  return 0;
}

// Return 1 if a number "n" is a power of two, 0 otherwise.
int check_is_power_of_two(int n) {
  if (n == 0)
    return 0; 
  while (n != 1) { 
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}