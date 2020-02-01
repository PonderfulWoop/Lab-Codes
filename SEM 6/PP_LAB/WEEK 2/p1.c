#include <mpi.h>
#include <stdio.h>
#include <string.h>
#define MAX 256

int main(int argc, char *argv[]){
	int n, rank;
	char str[MAX];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;
	if(rank == 0){
		printf("Enter a word in master\n");
		scanf("%s", str);
		n = strlen(str);
		MPI_Ssend(&n, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		MPI_Ssend(str, n, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
		fprintf(stdout, "sending %s from process 0\n", str);
		fflush(stdout);
		MPI_Recv(str, n, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Received from process 1: %s\n", str);

	}
	else{
		MPI_Recv(&n, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(str, n, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);
		fprintf(stdout, "Received %s in process 1\n", str);
		fflush(stdout);
		for(int i = 0; i<n; i++)
			str[i] = str[i]^32;
		fprintf(stdout, "sending %s from process 1\n", str);
		fflush(stdout);
		MPI_Ssend(str, n, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;

}