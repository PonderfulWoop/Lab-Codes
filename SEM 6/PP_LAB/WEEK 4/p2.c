#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	int rank, size;
	float x, y, pi, area;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	x = (float)(rank+1)/size;
	y = (float)4/(1 + x*x);

	area = 0.01*y;

	MPI_Reduce(&area, &pi, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0){
		fprintf(stdout, "Pi: %f\n", pi);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}