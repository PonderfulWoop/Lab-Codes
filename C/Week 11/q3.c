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

void printInordSucc(Node *root, int key, int* found){
	if(root!=NULL){
		printInordSucc(root->left, key, found);
		if(*found){
			printf("%d ", root->data);
			*found = 0;
		}
		if(root->data == key){
			*found = 1;
		}
		printInordSucc(root->right, key, found);
	}
}

int main(){
	int found = 0;
	Node *root = getNode(3);
	root->left = getNode(1);
	root->right = getNode(4);
	root->right->right = getNode(6);
	root->left->right = getNode(2);
	printInordSucc(root, 3, &found);
}