#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

typedef struct Node Node;

Node* getNode(int data){
	Node *t = (Node*)malloc(sizeof(Node));
	t->data = data;
	t->link = NULL;

	return t;
}

Node* insert(Node* head, int data){
	Node *t = getNode(data);
	Node *temp = head;
	if(head == NULL)
		return t;
	else{
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = t;
		return head;
	}
}

int main(){
	int n;
	printf("Enter number of nodes\n");
	scanf("%d", &n);

	Node *nodes[n];
	int k;
	printf("Enter Nodes:\n");
	for(int i = 0; i<n; i++){
		scanf("%d", &k);
		nodes[i] = getNode(k);
	}
	for(int i = 0; i<n; i++){
		int p;
		printf("For: %d\n", nodes[i]->data);
		printf("Enter number of adj nodes: \n");
		scanf("%d", &p);
		printf("Enter adjacent nodes:\n");
		for(int q = 0; q<p; q++){
			int h;
			scanf("%d", &h);
			nodes[i] = insert(nodes[i], h);
		}

	}

	//print the adj list
	printf("\nAdjacency List:\n\n");
	for(int i=0; i<n; i++){
		Node *temp = nodes[i];
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}

	//For Adj Matrix

	int matrix[n][n];
	for(int i = 0; i<n; i++)
		for(int l = 0; l<n; l++)
			matrix[i][l] = 0;

	for(int i = 0; i<n; i++){
		while(nodes[i] != NULL){
			matrix[i][nodes[i]->data - 1] = 1;
			nodes[i] = nodes[i]->link;
		}
	}
	printf("\nAdj MATRIX:\n\n");
	for(int i = 0; i<n; i++){
		for(int l = 0; l<n; l++){
			printf("%d ", matrix[i][l]);
		}
		printf("\n");
	}

}