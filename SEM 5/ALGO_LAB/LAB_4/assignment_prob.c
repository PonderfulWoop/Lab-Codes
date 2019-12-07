#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int permutations[1000][1000];
int arr[20];
int count = 0;
int lmao = 0;
int n;
void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
void genPerm(int arr[], int l, int r){
    if(l == r){
        lmao++;
        for(int p = 0; p<n; p++){
            permutations[count][p] = arr[p];
        }
        count++;
    }
    else{
        for(int i = l; i<=r; i++){
            lmao++;
            swap((arr+l), (arr+i));
            genPerm(arr, l+1, r);
            swap((arr+l), (arr+i));
        }
    }
}

void genNumArr(int n){
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
}

int main(){
    printf("Enter number of persons: \n");
    scanf("%d", &n);
    int costMatrix[n][n];
    printf("Enter the costMatrix for the Jobs: \n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &costMatrix[i][j]);
        }
    }
    genNumArr(n);
    genPerm(arr, 0, n-1);
    int minCost = (int)INFINITY;
    int bestPerm = 0;
    for(int i = 0; i<count; i++){
        int temp = 0;
        for(int k = 0; k<n; k++){
            temp += costMatrix[k][permutations[i][k]];
        }
        if(temp < minCost){
            minCost = temp;
            bestPerm = i;
        }
    }
    printf("lmao = %d", lmao);
    printf("The min. cost = %d\n", minCost);
    printf("Best permutation: %d\n", bestPerm);
    printf("Job assignment vector: \n");
    for(int i = 0; i < n; i++){
        printf("Person: %d should be given job: %d\n", i+1, permutations[bestPerm][i]+1);
    }
}