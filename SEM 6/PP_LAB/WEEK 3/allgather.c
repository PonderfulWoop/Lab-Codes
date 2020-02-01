#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	int rank, size;
	int a[6], r[6];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	for(int i = 0; i<6; i++)
		a[i] = rank + i;

	MPI_Allgather(a, 2, MPI_INT, r, 2, MPI_INT, MPI_COMM_WORLD);

	if(rank == 0){
		for(int i = 0; i<6; i++){
			fprintf(stdout, "%d ", r[i]);
			fflush(stdout);
		}
		fprintf(stdout, "\n");
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}