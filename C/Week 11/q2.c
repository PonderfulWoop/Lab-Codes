#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

typedef struct{
	int top;
	Node* a[40];
}Stack;

Node* pop(Stack *s){
	if(s->top == -1)
		return NULL;
	else
		return s->a[s->top--];
}

void push(Stack *s, Node *node){
	if(s->top == 39){
		printf("Overflow\n");
		return;
	}
	s->a[++(s->top)] = node;
}

int isDigit(char x){
	if(x>='0' && x<='9')
		return 1;

	return 0;
}

Node* getNode(char data){
	Node *t = (Node*)malloc(sizeof(Node));
	t->data = data;
	t->right = t->left = NULL;
	return t;
}

Node *create_tree(char t[]){
	Stack s;
	s.top = -1;
	int i; 
	for(i = 0; i<strlen(t); i++){
		Node* temp = getNode(t[i]);
		if(isDigit(t[i]))
			push(&s, temp);
		else{
			temp->right = pop(&s);
			temp->left = pop(&s);
			push(&s, temp);
		}
	}

	return pop(&s);
}

float eval(Node *root){
	switch(root->data){
		case '+':
			return (eval(root->left) + eval(root->right));
		case '-':
			return (eval(root->left) - eval(root->right));
		case '*':
			return (eval(root->left) * eval(root->right));
		case '/':
			return (eval(root->left) / eval(root->right));
		default :
			return root->data - '0';
	}
}

int main(){
	char str[] = "98+4*21-/";
	Node *root = create_tree(str);
	printf("%f\n", eval(root));
}