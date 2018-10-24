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

void ancestors(Node *root,int x,int *flag)
{
	if(root==NULL)
		return;
	ancestors(root->left,x,flag);
	if(root->data==x)
	{
		*flag=1;
		return;
	}
	if(*flag==1)
	{
		printf("%d ",root->data);
		return;
	}
	ancestors(root->right,x,flag);
	if(*flag==1)
		printf("%d ",root->data);
	if(root->data==x)
		*flag=1;
}

int main(){
	int found = 0;
	Node *root = getNode(3);
	root->left = getNode(1);
	root->right = getNode(4);
	root->right->right = getNode(6);
	root->left->right = getNode(2);
	ancestors(root, 2, &found);
	printf("\n");
}