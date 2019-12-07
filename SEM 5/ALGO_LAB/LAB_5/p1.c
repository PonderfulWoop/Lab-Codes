#include <stdio.h>
#include <stdlib.h>

int visited[20], n, matrix[20][20], stack[20], k = 0;

void dfs(int v){
    visited[v] = 1;
    for(int i = 0; i<n; i++){
        if(matrix[v][i] && !visited[i]){
            dfs(i);
        }
    }
    stack[k++] = v;
}

void printStack(){
    for(int i = n-1; i>=0; i--){
        printf("%d ", stack[i]);
    }
}
int main(){
    printf("Enter number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the adj matrix: \n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &matrix[i][j]);
    for(int i = 0; i<=n; i++){
        if(!visited[i])
            dfs(i);
    }
    printf("Topological Sort:\n");
    printStack();
}