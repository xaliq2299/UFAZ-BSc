// Example of a simple point to point communication: process with
// rank 0 sends a message to the process with rank 1

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]) {
  int rank, size;

  if (MPI_Init(&argc, &argv)) {
    fprintf(stderr, "Error MPI_Init\n");
    exit(1);
  }

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0) {
    char msg[BUF_SIZE];
    sprintf(msg, "Hello, receiver!");
    printf("Process %d, sending...\n", rank);
    MPI_Send(msg, BUF_SIZE, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
    printf("Process %d, finishing\n", rank); 
  }
  
  if (rank == 1) {
    char buf[BUF_SIZE];
    printf("Process %d, receiving...\n", rank);
    MPI_Recv(buf, BUF_SIZE, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d, received: %s\n", rank, buf);
    printf("Process %d, finishing\n", rank); 
  }

  MPI_Finalize();
  return 0;
}
