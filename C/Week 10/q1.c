#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

typedef struct{
	int top;
	Node * a[40];
}Stack;

Node* getNode(int data){
	Node *t = (Node*)malloc(sizeof(Node));
	t->data = data;
	t->right = t->left = NULL;
	return t;
}
void push(Stack *s, Node *node){
	if(s->top == 40)
		printf("Overflow\n");
	else{
		s->a[++(s->top)] = node;
	}
}

Node* pop(Stack *s){
	if(s->top == -1)
		return NULL;
	return s->a[(s->top)--];
}

Node *create(Node *root)
{
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    
    if(x==-1)
        return NULL;
    
    root = getNode(x);
    
    printf("Enter left child of %d:\n",x);
    root->left=create(root->left);
 
    printf("Enter right child of %d:\n",x);
    root->right=create(root->right);
    
    return root;
}
void search(Node *root, int x, int* found){
	if(root == NULL)
		return;
	if(root->data == x){
		*found = 1;
		return;
	}
	search(root->left, x, found);
	search(root->right, x, found);

}
void recurPre(Node *root){
	if(root != NULL){
		printf("%d ", root->data);
		recurPre(root->left);
		recurPre(root->right);
	}
}

void recurPost(Node *root){
	if(root != NULL){
		recurPost(root->left);
		recurPost(root->right);
		printf("%d ", root->data);
	}
}

void iteIn(Node *root){
	Stack s;
	s.top = -1;
	for(;;){
		for(;root!= NULL; root = root->left){
			push(&s, root);
		}
		root = pop(&s);
		if(root == NULL)
			return;
		printf("%d ", root->data);

		root = root -> right;

	}
}

int main(){
	Node *root = NULL;
	int s;
	int found = 0;
	printf("Enter details for the tree: \n");
	root = create(root);
	printf("Enter Element to find: \n");
	scanf("%d", &s);
	search(root, s, &found);
	if(found == 0)
		printf("Not present\n");
	else
		printf("Present\n");

	printf("PostOrder traversal tree:\n");
	recurPost(root);
	printf("PreOrder traversal tree:\n");
	recurPre(root);
	printf("InOrder traversal tree:\n");
	iteIn(root);
	printf("\n");
}