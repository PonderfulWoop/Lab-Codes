#include <stdlib.h>
#include <stdio.h>

int queue[20], k_1 = 0, k = 0, matrix[20][20], visited[20], n, indegree[20];

void calcInDeg(){
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(matrix[j][i] && i!=j)
                indegree[i]++;
}

void initQueue(){
    for(int i = 0; i<n; i++)
        queue[i] = -1;
}

void decInDeg(int v){
    for(int i = 0; i<n; i++){
        if(matrix[v][i]){
            indegree[i]--;
            if(indegree[i] == 0)
                queue[k++] = i;
        }
    }
}
int queueEmpty(){
    for(int i = 0; i<n; i++)
        if(queue[i] != -1)
            return 0;
    
    return 1;
}
int main(){
    printf("Enter number of nodes:\n");
    scanf("%d", &n);
    printf("Enter adj. matrix: \n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &matrix[i][j]);
    
    initQueue();
    calcInDeg();
    for(int i = 0; i<n; i++)
        if(indegree[i] == 0)
            queue[k++] = i;
    
    printf("Topological sort: \n");
    while(!queueEmpty()){
    int vertex = queue[k_1++];
    queue[k_1-1] = -1;
    decInDeg(vertex);
    printf("%d ", vertex);
    }
    printf("\n");
}