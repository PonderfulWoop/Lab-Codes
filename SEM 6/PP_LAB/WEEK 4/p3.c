#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, size;
	int arr[3][3], search, recv_arr[3], count = 0, recv_count;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if(rank == 0){
		fprintf(stdout, "Enter 3x3 matrix: \n");
		fflush(stdout);
		for(int i = 0; i<3; i++)
			for(int j = 0; j<3; j++)
				scanf("%d", &arr[i][j]);

		fprintf(stdout, "Enter search element\n");
		fflush(stdout);
		scanf("%d", &search);
	}

	MPI_Bcast(&search, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(arr, 3, MPI_INT, recv_arr, 3, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i = 0; i<3; i++)
		if(recv_arr[i] == search)
			count++;

	MPI_Reduce(&count, &recv_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0){
		fprintf(stdout, "No. of occurence: %d\n", recv_count);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}