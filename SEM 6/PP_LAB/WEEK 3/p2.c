#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, size, m, n, A[20], Slave[10];
	float B[10];
	float avg = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter m\n");
		fflush(stdout);
		scanf("%d", &m);

		fprintf(stdout, "Enter %d values\n", n*m);
		fflush(stdout);

		for(int i = 0; i<n*m; i++){
			scanf("%d", &A[i]);
		}
	}

	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);

	MPI_Scatter(A, m, MPI_INT, Slave, m, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i = 0; i<m; i++){
		avg += Slave[i];
	}
	avg = avg / m;



	MPI_Gather(&avg, 1, MPI_FLOAT, B, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

	if(rank == 0){
		float tot_avg = 0;
		for(int i = 0; i<n; i++)
			tot_avg += B[i];
		tot_avg = tot_avg/n;

		fprintf(stdout, "Total Average: %f\n", tot_avg);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}