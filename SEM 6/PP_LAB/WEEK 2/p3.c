#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, x, MAX = 256;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	int arr[MAX];
	MPI_Buffer_attach(arr, MAX);

	if(rank == 0){
		int a[size-1];
		printf("Enter %d values in master\n", size-1);
		for(int i = 0; i<size-1; i++)
			scanf("%d", &a[i]);
		
		for(int i = 1; i<size; i++){
			MPI_Bsend(&a[i-1], 1, MPI_INT, i, 1, MPI_COMM_WORLD);
			fprintf(stdout, "sending %d from process 0\n", x);
			fflush(stdout);
		}
	}
	else{
		MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Received %d in process %d\n", x, rank);
		fflush(stdout);
		if(rank%2 == 0){
			fprintf(stdout, "Square of %d: %d\n", x, x*x);
			fflush(stdout);
		}
		else{
			fprintf(stdout, "Cube of %d: %d\n", x, x*x*x);
			fflush(stdout);
		}
	}
	MPI_Buffer_detach(arr, &size);
	MPI_Finalize();
	return 0;

}