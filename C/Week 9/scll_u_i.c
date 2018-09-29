#include <stdio.h>
#include <stdlib.h>
#define getNode (Node*)malloc(sizeof(Node))

struct Node{
	int data;
	struct Node *next;
};

typedef struct Node Node;

void insert(Node **first, int elem){
	Node *t = getNode;
	t->data = elem;

	if((*first) == NULL)
	{
		t->next = t;
		*first = t;
		return;
	}

	Node *temp = *first;
	while(temp->next != *first){
		temp = temp->next;
	}
	temp->next = t;
	t->next = *first;
}
int Contains(Node *k, int n){
	if(k == NULL)
		return 0;
	Node *t = k;
	while(t->next != k){
		if(t->data == n)
			return 1;
		t = t->next;
	}
	if(t->data == n)
		return 1;

	return 0;
}
void intersection(Node *a, Node *b, Node **c){
	Node *temp = a;
	Node *temp2 = b;
	while(temp2->next != b){
		if(Contains(temp, temp2->data)){
			temp2 = temp2->next;
		}
		else{
			if(Contains(*c, temp2->data) == 0){
				insert(c, temp2->data);
			}
			temp2 = temp2->next;
		}
	}
	if(Contains(temp, temp2->data) == 0){
		insert(c, temp2->data);
	}
	temp2 = b;
	while(temp->next != a){
		if(Contains(temp2, temp->data)){
			temp = temp->next;
		}
		else{
			if(Contains(*c, temp->data) == 0){
				insert(c, temp->data);
			}
			temp = temp->next;
		}
	}
	if(Contains(temp2, temp->data) == 0){
		insert(c, temp->data);
	}
}

void Union(Node *a, Node *b, Node **c){
	Node *t1 = a;
	Node *t2 = b;
	while(t1->next != a && t2->next != b){
		if(Contains(*c, t1->data) == 0){
			insert(c, t1->data);
			t1 = t1->next;
		}
		else
		{
			t1 = t1->next;
		}

		if(Contains(*c, t2->data) == 0){
			insert(c, t2->data);
			t2 = t2->next;
		}
		else
		{
			t2 = t2->next;
		}
	}

	if(t1->next == a){
		if(Contains(*c, t1->data) == 0){
			insert(c, t1->data);
		}
		while(t2->next != b){
		if(Contains(*c, t2->data) == 0){
			insert(c, t2->data);
			t2 = t2->next;
		}
		else
		{
			t2 = t2->next;
		}
		}
	}
	else{
		if(Contains(*c, t2->data) == 0){
			insert(c, t2->data);
		}
		if(Contains(*c, t1->data) == 0){
			insert(c, t1->data);
			t1 = t1->next;
		}
		else
		{
			t1 = t1->next;
		}
	}
}

void disp(Node *lol){
	Node *l = lol;
	while(l->next != lol){
		printf("%d\t", l->data);
		l = l->next;
	}
	printf("%d\n", l->data);
}

int main(){
	Node *A = NULL;
	Node *B = NULL;
	Node *C = NULL;
	Node *D = NULL;
	int in = 0;
	printf("Enter elements in A and enter -1 to end\n");
	while(in!=-1){

		scanf("%d", &in);
		if(in != -1)
			insert(&A, in);
	}
	in = 0;
	printf("Enter elements in B and enter -1 to end\n");
	while(in!=-1){

		scanf("%d", &in);
		if(in != -1)
			insert(&B, in);
	}

	intersection(A, B, &C);
	Union(A,B, &D);
	disp(C);
	disp(D);
}