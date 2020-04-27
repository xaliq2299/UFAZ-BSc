#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <mpi.h>

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
int *array_global[N], *sorted_global[N];


int main(int argc, char *argv[]){
  int rank, size, counter = 1; // counter needed for sorting process
  int *array = array_global, *sorted = sorted_global;

  // MPI initialization
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(!check_is_power_of_two(size)){
    if(rank == 0)
      fprintf(stderr, "Size must be a power of 2 !!!\n");
    MPI_Finalize();
    return 1;
  }

  // Initialization
  if(rank == 0){
    srand(time(0) + getpid());
      for(int i = 0; i < N; i++)
        array[i] = rand() % N;
  }
  double time1 = MPI_Wtime();
  check_init(array);

  MPI_Scatter(array, N / size, MPI_INT, array, N / size, MPI_INT, 0, MPI_COMM_WORLD);
  qsort(array, N / size, sizeof(int), compare);

  // merge process starts here
  while(counter < size){
    if(rank % (2 * counter) == counter)
      MPI_Ssend(array, counter * N / size, MPI_INT, rank - counter, 0, MPI_COMM_WORLD);
    else if(rank % (2 * counter) == 0){
      MPI_Recv(array + N / 2, counter * N / size, MPI_INT, rank + counter, 0, MPI_COMM_WORLD, NULL);
      merge(sorted, array, counter * N / size, array + N / 2, counter * N / size);
            
      int* tmp;
      tmp = sorted;
      sorted = array;
      array = tmp;
    }
    counter *= 2;
  }
  sorted = array;

  // check whether everyting went ok or not
  if(rank == 0){
    double time2 = MPI_Wtime();
      if(check(sorted))
        printf("Bad results: array is not sorted :-(((\n");
      else
        printf("Good results: array is sorted :-)\nTime: %lf s\n", time2 - time1);
    }

    MPI_Finalize();
    return 0;
}


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


// ---------------------------------------------------------------------------
// Checking mechanism part (no need to read it)
// ---------------------------------------------------------------------------

int count[N];


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