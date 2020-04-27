#include	<stdio.h>
#include	<mpi.h>

#define proc_A 0
#define proc_B 1
#define ping 101
#define pong 101

float buffer[10001];

void processor_A (void);
void processor_B (void);

void main ( int argc, char *argv[] )
{
     int ierror, rank, size;

   /*----------------*/
  /* Initialize MPI */
 /*----------------*/

     MPI_Init(&argc, &argv);

   /*--------------------------*/
  /* Get my process ID number */
 /*--------------------------*/

     MPI_Comm_rank(MPI_COMM_WORLD, &rank);

     if (rank == proc_A) processor_A();
     else if (rank == proc_B) processor_B();

   /*--------------*/
  /* Finalize MPI */
 /*--------------*/

     MPI_Finalize();

}

void processor_A( void )
{

    int i, ierror;
    int sfloat;
    MPI_Status status;

    double start, finish, time;

    extern float buffer[10001];

    int length;

    sfloat = sizeof(float);

    printf("length   time/message (sec)    transfer rate (byte/sec)\n");

   /*---------------------------------*/
  /* Process A sets the message size */
 /*---------------------------------*/

     for (length = 1; length <=  10001; length += 1000){ 

   /*-----------------------------------------------------*/
  /* Get the start time for the pingpong message passing */
 /*-----------------------------------------------------*/

        start = MPI_Wtime();

   /*--------------------------------------------------------------*/
  /* Process A sends and then receives the message back 100 times */
 /*--------------------------------------------------------------*/

        for (i = 1; i <= 100; i++){

            MPI_Ssend(buffer, length, MPI_FLOAT, proc_B, ping,
                      MPI_COMM_WORLD);

            MPI_Recv(buffer, length, MPI_FLOAT, proc_B, pong,
                     MPI_COMM_WORLD, &status);

        }

   /*------------------------------------------------------*/
  /* Get the finish time for the pingpong message passing */
 /*------------------------------------------------------*/

        finish = MPI_Wtime();

        time = finish - start;

        printf("%d\t      %f               %f\n", length, time/200.,
               (float)(2 * sfloat * 100 * length)/time);

    }

}

void processor_B( void )
{
    int i, ierror;
    MPI_Status status;

    extern float buffer[10001];

    int length;

   /*---------------------------------*/
  /* Process B sets the message size */
 /*---------------------------------*/

    for (length = 1; length <= 10001; length += 1000) { 

   /*--------------------------------------------------------------*/
  /* Process B receives and then sends the message back 100 times */
 /*--------------------------------------------------------------*/

            for (i = 1; i <= 100; i++) {

                MPI_Recv(buffer, length, MPI_FLOAT, proc_A, ping,
                         MPI_COMM_WORLD, &status);

                MPI_Ssend(buffer, length, MPI_FLOAT, proc_A, pong,
                         MPI_COMM_WORLD);

            }

    }

}

