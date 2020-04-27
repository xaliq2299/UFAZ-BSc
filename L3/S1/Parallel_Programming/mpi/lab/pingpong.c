#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char **argv) {
  int rank, size;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (argc != 3) {
    if (rank == 0)
      fprintf(stderr, "Usage: %s <number-of-messages> <length>!\n", argv[0]);
    MPI_Finalize();
    return 1;
  }
  int number_of_messages = atoi(argv[1]);
  int length = atoi(argv[2]);


  if (size != 2 || number_of_messages <= 0 || length <= 0) {
    if (rank == 0)
      fprintf(stderr, "Error: need two processes and valid parameters!\n");
    MPI_Finalize();
    return 1;
  }

  char* message = malloc(length);
  double t1 = MPI_Wtime();

  if (rank == 0)
    MPI_Recv(message, length, MPI_CHAR, !rank, 0, MPI_COMM_WORLD, NULL);
  for (int i = 0; i < number_of_messages - 1; i++) {
    MPI_Ssend(message, length, MPI_CHAR, !rank, 0, MPI_COMM_WORLD);
    MPI_Recv(message, length, MPI_CHAR, !rank, 0, MPI_COMM_WORLD, NULL);
  }
  if (rank == 1)
    MPI_Ssend(message, length, MPI_CHAR, !rank, 0, MPI_COMM_WORLD);

  double t2 = MPI_Wtime();

  if (rank == 0) {
    printf("Total time: %lg s\n", t2-t1);
    printf("Throughput: %lg MB/s\n",
        (2. * length * number_of_messages + 1) / (1024. * 1024. * (t2 - t1)));
  }

  free(message);
  MPI_Finalize();

  return 0;
}