#include <stdio.h>
#include <stdlib.h>

int n_v;
int a[50][50], edge_c = 0;

struct E{
    int weight;
    int from, to;
};
typedef struct E E;

E Edges[50], Edges2[50];

void read_cost(){
    printf("Enter number of Vertices: \n");
    scanf("%d", &n_v);
    printf("Enter Cost Adj. Matrix: \n");
    for(int i = 0; i<n_v; i++){
        for(int j = 0; j<n_v; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0){
                if(i<j){
                    Edges[edge_c].weight = a[i][j];
                    Edges[edge_c].from = i;
                    Edges[edge_c].to = j;
                    edge_c++;
                }
            }
        }
    }
    for(int i = 0; i<edge_c; i++){
        for(int j = 0; j<edge_c - i - 1;j++){
            E temp;
            if(Edges[j].weight > Edges[j+1].weight){
                temp = Edges[j];
                Edges[j] = Edges[j+1];
                Edges[j+1] = temp;
            }
        }
    }
}
int find(int belongs[], int vertex){
    return belongs[vertex];
}
void union1(int belongs[], int c1, int c2){
    int i;
    for(i = 0; i<n_v; i++)
        if(belongs[i] == c2)
            belongs[i] = c1;
}

void kruskals(){
    printf("Minimum Spanning Tree: \n\n");
    int belongs[50], cno1, cno2;
    read_cost();
    for(int i = 0; i<n_v; i++)
        belongs[i] = i;
    int k = 0;
    for(int i =0; i<edge_c; i++){
        cno1 = find(belongs, Edges[i].from);
        cno2 = find(belongs, Edges[i].to);
        if(cno1 != cno2){
            Edges2[k] = Edges[i];
            k++;
            union1(belongs, cno1, cno2);
        }
    }

    for(int i = 0; i<k; i++){
        printf("Edge - W: %d, From: %d, To: %d\n", Edges2[i].weight, Edges2[i].from, Edges[i].to);
    }
}

int main(){
    kruskals();
}