#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

Node* getNode(int data){
	Node *t = (Node*)malloc(sizeof(Node));
	t->data = data;
	t->right = t->left = NULL;
	return t;
}

void inOrdTrav(Node *root, int arr[]){
	static int i = 0;
	if(root != NULL){
		inOrdTrav(root->left, arr);
		arr[i++] = root->data;
		inOrdTrav(root->right, arr);
	}
}

int isBST(Node *root){
	int arr[100];
	inOrdTrav(root, arr);
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i<(size-1); i++){
		if(arr[i] > arr[i+1])
			return 0;
	}
	return 1;
}

int main(){
	Node *root = getNode(5);
	root->left = getNode(3);
	root->right = getNode(8);
	root->right->right = getNode(9);
	root->right->left = getNode(7);
	

	printf("%d\n", isBST(root));
}