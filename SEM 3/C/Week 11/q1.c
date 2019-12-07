#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

typedef struct{
	int r, f;
	Node* a[40];
}Queue;

Node* getNode(int data){
	Node *t = (Node*)malloc(sizeof(Node));
	t->data = data;
	t->right = t->left = NULL;
	return t;
}

void enQueue(Queue *q, Node *node){
	if(q->r == 39)
		printf("Overflow\n");
	else
	{
		q->a[++(q->r)] = node;
	}
}

Node* deQueue(Queue *q){
	if(q->r == -1)
		return NULL;
	else{
		return q->a[++(q->f)];
	}
}

Node *create(Node *root, int data){
	Node *t = getNode(data);
	if(root == NULL)
		return t;

	Node *p = NULL;
	Node *c = root;

	while(c != NULL){
		p = c;
		if(c->data < data){
			c = c -> right;
		}
		else if(c->data > data){
			c = c -> left;
		}
		else{
			printf("Not Possible. All distinct elements needed.\n");
			return root;
		}
	}
	if(p->data < data)
		p->right = t;
	else
		p->left = t;

	return root;
}
int isEmpty(Queue q){
	if(q.r == q.f)
		return 1;
	return 0;
}

void levelOrdDisp(Node *root){
	Queue q;
	q.r = -1;
	q.f = -1;
	if(root == NULL)
		return;
	enQueue(&q, root);
	while(!isEmpty(q)){
		root = deQueue(&q);
		printf("%d ", root->data);
		if(root->left) enQueue(&q, root->left);
		if(root->right) enQueue(&q, root->right);
	}
}

Node* succ(Node *node){
	while(node->left != NULL)
		node = node->left;

	return node;
}

void delete(Node** root, int key){
	if(*root == NULL)
		return;
	Node *parent = NULL;
	Node *curr = *root;
	while(curr!=NULL && curr->data != key){
		parent = curr;
		if(curr -> data > key)
			curr = curr -> left;
		else
			curr = curr -> right;
	}
	if(curr == NULL)
		return;

	if(!curr->left && !curr->right){
		if(curr == *root){
			free(curr);
			return;
		}
		if(parent->left == curr)
			parent->left = NULL;
		else
			parent->right = NULL;

		free(curr);
	}
	else if(curr->left && curr->right){
		Node* s = succ(curr->right);
		int val = s->data;
		delete(root, s->data);

		curr->data = val;
	}
	else{
		Node* child = (curr->left)? curr->left : curr->right;
		if(curr == *root){
			*root = child;
		}
		else{
			if(parent->left == curr){
				parent->left = child;
			}
			else{
				parent->right = child;
			}
		}

		free(curr);
	}
}

int main(){
	Node *root = NULL;
	int in, e;
	int ch = 0;
	while(ch != 4){
		printf("Enter:\t1. Create\t2. Delete a Node\t3. Display\t4. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
			if(root != NULL){printf("Tree Exists\n"); continue;}
			printf("Enter number of elements\n");
			scanf("%d", &in);
			printf("Enter elements\n");
			for(int i = 0; i < in; i++){
				scanf("%d", &e);
				root = create(root, e);
			}
			break;

			case 2:
			printf("Enter element to delete:\n");
			scanf("%d", &e);
			delete(&root, e);
			break;

			case 3:
			levelOrdDisp(root);
			printf("\n");
			break;
		}
	}
}