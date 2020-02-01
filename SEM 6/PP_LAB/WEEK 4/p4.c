#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, error;

	MPI_Init(&argc, &argv);

	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	error = MPI_Comm_rank(&rank, MPI_COMM_WORLD);
	if(error != MPI_SUCCESS){
		char err_str[256];
		int len, err_class;

		MPI_Error_class(error, &err_class);
		MPI_Error_string(error, err_str, &len);
		fprintf(stdout, "Error String: %s\n", err_str);
		fflush(stdout);
		fprintf(stdout, "Error class: %d\n", err_class);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}