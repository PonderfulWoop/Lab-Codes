#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 20
#define INF 99999

int mat[N][N];
int res[N][N];

void printres(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(res[i][j] == INF){
                printf("INF ");
            }
            else{
                printf("%d ", res[i][j]);
            }
        }
        printf("\n");
    }
}

void shortestPair(int n){
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(mat[i][j] != -1)
                res[i][j] = mat[i][j];
            else
                res[i][j] = INF;
    
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                res[i][j] = (res[i][j] > (res[i][k]+res[k][j])) ? (res[i][k]+res[k][j]):res[i][j];
            }
        }
    }
    printres(n);
}

int main(){
    int n;
    printf("Enter vertices: \n");
    scanf("%d", &n);
    printf("Enter Cost Matrix: (Enter -1 if not connected)\n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &mat[i][j]);
    
    shortestPair(n);
}