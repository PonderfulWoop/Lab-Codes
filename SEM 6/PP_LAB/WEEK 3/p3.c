#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size, n, cnt, nonvowel_cnt = 0;
	char str[10], slave_str[10];
	int vals[10];
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		n = size;
		fprintf(stdout, "Enter string\n");
		fflush(stdout);
		scanf("%s", str);
		cnt = strlen(str);
		cnt = cnt/n;
	}

	MPI_Bcast(&cnt, 1, MPI_INT, 0, MPI_COMM_WORLD);

	MPI_Scatter(str, cnt, MPI_CHAR, &slave_str, cnt, MPI_CHAR, 0, MPI_COMM_WORLD);
	for(int k = 0; k<cnt; k++){
		if(slave_str[k] != 'a' && slave_str[k] != 'e' && slave_str[k] != 'i' && slave_str[k] != 'o' && slave_str[k] != 'u')
			nonvowel_cnt++;
	}

	MPI_Gather(&nonvowel_cnt, 1, MPI_INT, vals, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if(rank == 0){
		fprintf(stdout, "No. of Non-Vowels:\n");
		fflush(stdout);
		int sum = 0;
		for(int l = 0; l<n; l++){
			fprintf(stdout, "in %d, found: %d non-vowels\n", l, vals[l]);
			fflush(stdout);
			sum += vals[l];
		}
		fprintf(stdout, "Total non-vowels: %d\n", sum);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}
