#include <mpi.h>
#include <stdio.h>

int isPrime(int x){
	for(int i = 2; i<x; i++)
		if(x%i == 0)
			return 0;
	return 1;
}

int main(int argc, char * argv[]){
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0){
		for(int i = 3; i<=50; i++)
			if(isPrime(i))
				printf("Rank-%d: %d\n", rank, i);
	}
	else if(rank == 1){
		for(int i = 51; i<=100; i++){
			if(isPrime(i))
				printf("Rank-%d: %d\n", rank, i);
		}
	}
	MPI_Finalize();
	return 0;
}
