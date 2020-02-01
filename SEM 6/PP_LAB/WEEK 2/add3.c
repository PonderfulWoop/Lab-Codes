#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, n;
	int temp;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank == 0){
		printf("Enter n in master\n");
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i<size; i++){
			MPI_Recv(&temp, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &status);
			sum+=temp;
		}
		fprintf(stdout, "Sum of values returned from all Processes: %d\n", sum);
		fflush(stdout);
	}
	else{
		if(rank%2 != 0){
			int ret = 1;
			for(int i = 1; i<=rank; i++)
				ret *= i;
			MPI_Send(&ret, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		}
		else{
			int ret = 0;
			for(int i = 0; i<=rank; i++)
				ret += i;
			MPI_Send(&ret, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		}
	}

	MPI_Finalize();
	return 0;

}