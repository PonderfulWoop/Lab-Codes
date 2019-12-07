#include <stdlib.h>
#include <stdio.h>

typedef struct E{
	int weight, from, to;
}E;

E Edges[20], Edges[20];
int a[20][20];
int V;

int edge_c = 0;

int find(int belongs[], int vertex){
	return belongs[vertex];
}

void union1(int belongs[], int c1, int c2){
	for(int i = 0; i<V; i++){
		if(belongs[i] == c2)
			belongs[i] = c1;
	}
}

void MaxST(){
	for(int i = 0; i<V; i++){
		for(int j = 0; j<V; j++){
			if(a[i][j] != 0 && i<j){
				Edges[edge_c].weight = a[i][j];
				Edges[edge_c].from = i;
				Edges[edge_c].to = j;
				edge_c++;
			}
		}
	}

	//Sort
	for(int i = 0; i<edge_c; i++){
		for(int j = 0; j<edge_c-i-1; j++){
			if(Edges[j].weight < Edges[j+1].weight){
				E temp = Edges[j];
				Edges[j] = Edges[j+1];
				Edges[j+1] = temp;
			}
		}
	}

	int belongs[V];
	for(int i = 0; i<V; i++)
		belongs[i] = i;

	int k = 0;
	for(int i = 0; i<edge_c; i++){
		int c1 = find(belongs, Edges[i].from);
		int c2 = find(belongs, Edges[i].to);
		if(c1 != c2){
			Edges2[k] = Edges[i];
			k++;
			union1(belongs, c1, c2);
		}
	}

	//print Edges2
}

int main(){
	printf("Enter number of V\n");
	scanf("%d", &V);
	printf("Enter cost matrix\n");
	for(int i = 0; i<V; i++)
		for(int j = 0; j<V; j++)
			scanf("%d", &a[i][j]);

	MaxST();
}