#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, size, m, n, A[20], Slave[10];
	int B[20];
	const int per_pro = 4;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		n = size;

		fprintf(stdout, "Enter 16 values\n");
		fflush(stdout);

		for(int i = 0; i<16; i++){
			scanf("%d", &A[i]);
		}
	}

	MPI_Scatter(A, per_pro, MPI_INT, Slave, per_pro, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i = 1; i<per_pro; i++){
		Slave[i] = Slave[i] + Slave[i-1];
	}

	MPI_Gather(Slave, per_pro, MPI_INT, B, per_pro, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0){
		for(int i = 0; i<16; i++){
			fprintf(stdout, "%d ", B[i]);
			fflush(stdout);
		}
		fprintf(stdout, "\n");
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}