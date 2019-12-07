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
void printTopLeft(Node *root){
	if(root -> left != NULL)
		printTopLeft(root->left);
	printf("%d ", root->data);
}
void printTopRight(Node *root){
	printf("%d ", root->data);
	if(root->right != NULL)
		printTopLeft(root->right);
}
void printTop(Node *root){
	printTopLeft(root->left);
	printf("%d ", root->data);
	printTopRight(root->right);
}

int main(){
	Node *root = getNode(5);
	root->left = getNode(3);
	root->left->left = getNode(4);
	root->left->left->left = getNode(1);
	root->right = getNode(8);
	root->right->right = getNode(9);
	root->right->left = getNode(7);
	

	printTop(root);
}