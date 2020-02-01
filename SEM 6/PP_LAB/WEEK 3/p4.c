#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size, n, cnt;
	char str1[10], str2[10], slave_str1[10], slave_str2[10];
	char mid_arr[10];
	char recv_arr[10][10];
	int vals[10];
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter string1\n");
		fflush(stdout);
		scanf("%s", str1);
		fprintf(stdout, "Enter string2\n");
		fflush(stdout);
		scanf("%s", str2);

		cnt = strlen(str1);
		cnt = cnt/n;
	}

	MPI_Bcast(&cnt, 1, MPI_INT, 0, MPI_COMM_WORLD);

	MPI_Scatter(str1, cnt, MPI_CHAR, &slave_str1, cnt, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Scatter(str2, cnt, MPI_CHAR, &slave_str2, cnt, MPI_CHAR, 0, MPI_COMM_WORLD);

	int p_str1 = 0, p_str2 = 0;
	for(int k = 0; k<cnt*2; k++){
		if(k%2 == 0){
			mid_arr[k] = slave_str1[p_str1];
			p_str1++;
		}
		else{
			mid_arr[k] = slave_str2[p_str2];
			p_str2++;
		}
	}

	cnt = cnt*2;

	MPI_Bcast(&cnt, 1, MPI_INT, 0, MPI_COMM_WORLD);

	MPI_Gather(mid_arr, cnt, MPI_CHAR, recv_arr, cnt, MPI_CHAR, 0, MPI_COMM_WORLD);
	if(rank == 0){
		fprintf(stdout, "String: %s\n", recv_arr[0]);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}