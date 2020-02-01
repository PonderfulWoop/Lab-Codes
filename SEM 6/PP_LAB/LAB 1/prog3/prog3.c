#include <mpi.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	int rank;
	int NUM1 = 10;
	int NUM2 = 5;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	switch(rank){
		case 0:
			printf("rank is %d => +:%d \n", rank, NUM1+NUM2);
			break;
		case 1:
			printf("rank is %d => -:%d \n", rank, NUM1-NUM2);
			break;
		case 2:
			printf("rank is %d => *:%d \n", rank, NUM1*NUM2);
			break;
		case 3:
			printf("rank is %d => /:%d \n", rank, NUM1/NUM2);
			break;
	}
	MPI_Finalize();
	return 0;
}
