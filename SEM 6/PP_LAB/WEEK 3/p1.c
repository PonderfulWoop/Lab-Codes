#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, n, A[10], B[10], slave, fact = 1;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter %d values\n", n);
		fflush(stdout);
		for(int i = 0; i<n; i++){
			scanf("%d", &A[i]);
		}
	}

	MPI_Scatter(A, 1, MPI_INT, &slave, 1, MPI_INT, 0, MPI_COMM_WORLD);
	for(int k = slave; k>=1; k--)
		fact = fact * k;

	MPI_Gather(&fact, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0){
		fprintf(stdout, "Sum of the Factorials:\n");
		fflush(stdout);
		int sum = 0;
		for(int l = 0; l<n; l++)
			sum += B[l];
		fprintf(stdout, "%d\n", sum);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}