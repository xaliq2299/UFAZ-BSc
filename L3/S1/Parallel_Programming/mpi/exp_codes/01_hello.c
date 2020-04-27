// MPI hello world example: each process write its rank and its hostname

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#define NAME_MAX_LENGTH 128

int main(int argc, char* argv[]) {
  int rank, size;
  char hostname[NAME_MAX_LENGTH];
  
  if (gethostname(hostname, NAME_MAX_LENGTH)) {
    fprintf(stderr, "Error: cannot get the hostname\n");
    exit(1);
  }

  if (MPI_Init(&argc, &argv)) {
    fprintf(stderr, "Error: MPI_Init failed\n");
    exit(1);
  }

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf("I'm process %d of %d on machine %s\n", rank, size, hostname);

  MPI_Finalize();
  return 0;
}
