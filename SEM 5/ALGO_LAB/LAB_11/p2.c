#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int V;
int mat[20][20];

int minDist(int dist[], int sp[]){
    int min = INT_MAX, minIndex;

    for(int v = 0; v<V; v++)
        if(sp[v] == 0 && dist[v]<=min)
            min = dist[v], minIndex = v;
    
    return minIndex;
}

void Djikstra(int start){
    int dist[V];
    int sp[V];

    for(int i = 0; i<V; i++){
        dist[i] = INT_MAX;
        sp[i] = 0;
    }
    dist[start] = 0;

    for(int count = 0; count<V-1; count++){
        int u = minDist(dist, sp);
        sp[u] = 1;

        for(int v = 0; v<V; v++){
            if(sp[v] == 0 && mat[u][v] && dist[u] != INT_MAX
                && dist[u] + mat[u][v] < dist[v])
                dist[v] = dist[u] + mat[u][v];
        }
    }

    //Print
    for(int i = 0; i<V; i++){
        printf("From Source to Vertex %d -> %d\n", i, dist[i]);
    }
}

int main(){
    printf("Enter number of vertices: \n");
    scanf("%d", &V);
    printf("Enter cost matrix:\n");
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int start;
    printf("Enter starting node: \n");
    scanf("%d", &start);

    Djikstra(start);
}

