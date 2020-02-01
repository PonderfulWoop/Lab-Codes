#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, x;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank == 0){
		printf("Enter a value in master\n");
		scanf("%d", &x);
		fprintf(stdout, "Sending %d from process 0 to process 1\n", x);
		fflush(stdout);
		MPI_Ssend(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		MPI_Recv(&x, 1, MPI_INT, size-1, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Received %d in process 0 from process %d\n", x, size-1);
		fflush(stdout);
	}
	else{
		MPI_Recv(&x, 1, MPI_INT, rank-1, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Received %d in process %d from process %d\n", x, rank, rank - 1);
		fflush(stdout);
		x++;
		fprintf(stdout, "Sending %d from process %d to process %d\n", x, rank, (rank+1)%size);
		fflush(stdout);
		MPI_Ssend(&x, 1, MPI_INT, (rank+1)%size, 1, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;

}