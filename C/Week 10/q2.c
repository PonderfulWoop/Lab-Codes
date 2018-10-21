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

Node *create(Node *root, int z)
{
	Node* t = getNode(z);
    if(root == NULL){
    	return t;
    }
    Node* p = NULL;
    Node* c = root;
    char dir[10];
    printf("Enter path:\n");
    scanf("%s", dir);
    for(int i = 0; i!=strlen(dir); i++){
    	p = c;
    	if(dir[i] == 'L')
    		c = c->left;
    	else
    		c = c->right;
    }
    if(c != NULL){
    	printf("Not Possible\n");
    	return root;
    }
    if(dir[strlen(dir) - 1] == 'L')
    	p->left = t;
    else
    	p->right = t;
    return root;
}
void recurIn(Node *root){
	if(root != NULL){
		recurIn(root->left);
		printf("%d ", root->data);
		recurIn(root->right);
	}
}

void itePre(Node *root){
	Stack s;
	s.top = -1;
	for(;;){
		for(;root!= NULL; root = root->left){
			printf("%d ", root->data);
			push(&s, root);
		}
		root = pop(&s);
		if(root == NULL)
			return;
		
		root = root -> right;

	}
}
void itePost(Node* root) 
{  
    if (root == NULL) 
        return; 
      
    Stack stack;
    stack.top = -1;
    do
    { 
        while (root) 
        {  
            if (root->right) 
                push(&stack, root->right); 
            push(&stack, root); 
  
            root = root->left; 
        } 
  
            
        root = pop(&stack); 
  
        if (root->right && stack.a[stack.top] == root->right)
        { 
            pop(&stack);  
            push(&stack, root); 
            root = root->right;
        } 
        else 
        { 
            printf("%d ", root->data); 
            root = NULL; 
        } 
    } while (stack.top != -1); 
}
int main(){
	Node *root = NULL;
	int s;
	int found = 0;
	printf("Enter details for the tree: \n");
	while(1){
		printf("Enter number(-1 to exit)\n");
		scanf("%d", &s);
		if(s == -1)
			break;
		root = create(root, s);
	}
	printf("PostOrder traversal tree:\n");
	itePost(root);
	printf("PreOrder traversal tree:\n");
	itePre(root);
	printf("InOrder traversal tree:\n");
	recurIn(root);
	printf("\n");
}