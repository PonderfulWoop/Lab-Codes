#include <stdlib.h>
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size;
	int fact = 1, ans;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	for(int i = rank + 1; i>=1; i--)
		fact = fact*i;

	MPI_Scan(&fact, &ans, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	
	if(rank == size-1){
		fprintf(stdout, "Sum of factorials: %d\n", ans);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}