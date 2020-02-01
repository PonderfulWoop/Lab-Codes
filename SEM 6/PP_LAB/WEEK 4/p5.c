#include "mpi.h"
#include <stdio.h>

int main (int argc, char* argv[]) {

        int rank, size;
        int i = 0, j;
        int k = 0, fac = 1, ans[1000], sum = 0;
        int n, a[100][100], b[100];

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if (rank == 0)
                for (i = 0; i < 4; i++)
                        for (j = 0; j < 4; j++)
                                scanf("%d", &a[i][j]);

        MPI_Scatter(a, 100, MPI_INT, b, 100, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scan(b, ans, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

        printf("%d\t%d\t%d\t%d\n", ans[0], ans[1], ans[2], ans[3]);

        MPI_Finalize();
        return 0;
}
