// Example of a point-to-point broadcast : the process with rank 0
// sends a value to all other processes with rank > 0

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
  int rank, size;

  if (MPI_Init(&argc, &argv)) {
    fprintf(stderr, "Error MPI_Init\n");
    exit(1);
  }

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0) {
    int val = 42;
    for (int i = 1; i < size; i++) {
      printf("Process %d, sending %d to process %d...\n", rank, val, i);
      MPI_Send(&val, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
  } else {
    int x;
    printf("Process %d, receiving...\n", rank);
    MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d, received: %d\n", rank, x);
  }

  MPI_Finalize();
  return 0;
}
