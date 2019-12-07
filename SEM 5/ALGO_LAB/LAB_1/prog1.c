#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;

Node* getNode(int data){
	Node* t = (Node*)malloc(sizeof(Node));
	t->data = data;
	t->right = t->left = NULL;
	return t;
}

void insertNode(Node** head, int data){
	if(*head == NULL)
		*head = getNode(data);
	if((*head)->data > data)
		insertNode(&((*head)->left), data);
	else if((*head)->data < data)
		insertNode(&((*head)->right), data);
}

void Search(Node** head, int data){
	if(*head == NULL){
		printf("Inserting Element\n");
		insertNode(head, data);
	}
	else if((*head)->data == data)
		printf("Element Found\n");
	else{
		if((*head)->data<data)
			Search(&((*head)->right), data);
		else if((*head)->data>data)
			Search(&((*head)->left), data);
	}
}

void inorder(Node* head){
	if(head != NULL){
		inorder(head->left);
		printf("%d ", head->data);
		inorder(head->right);
	}
}

void preorder(Node* head){
	if(head != NULL){
		printf("%d ", head->data);
		preorder(head->left);
		preorder(head->right);
	}
}

void postorder(Node* head){
	if(head != NULL){
		postorder(head->left);
		postorder(head->right);
		printf("%d ", head->data);
	}
}

int main(){
	Node* head = getNode(10);
	head->left = getNode(6);
	head->right = getNode(15);
	head->left->right = getNode(8);
	head->left->left = getNode(3);
	head->right->left = getNode(12);
	head->right->right = getNode(16);

	inorder(head);
	printf("\nSearching for 18\n");
	Search(&head, 18);
	preorder(head);
	printf("\nSearching for 12\n");
	Search(&head, 12);
	postorder(head);
	printf("\n");

	return 0;
}