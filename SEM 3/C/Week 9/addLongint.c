#include <stdio.h>
#include <stdlib.h>
#define getNode (Node*)malloc(sizeof(Node))

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node Node;

void insertF(Node **first, int elem){
	Node *t = getNode;
	t->data = elem;
	if(*first == NULL){
		t->next = t;
		t->prev = t;
		*first = t;
		return;
	}
	Node *last = (*first)->prev;
	t->next = *first;
	t->prev = last;
	last->next = t;
	(*first)->prev = t;
	(*first) = t;
}

void add(Node *a, Node *b, Node **c){
	Node *t1 = a;
	Node *t2 = b;
	int flag_t1 = 0;
	int flag_t2 = 0;
	int sum = 0;
	int carry = 0;
	do{
		sum = sum + t1->data + t2->data;
		carry = sum/10;
		sum = sum%10;
		insertF(c, sum);
		sum = carry;
		t1 = t1->prev;
		t2 = t2->prev;
	}while(t1->prev != a && t2->prev != b);

	if(t1->prev == a && t2->prev == b){
		sum = sum + t1->data + t2->data;
		carry = sum/10;
		sum = sum%10;
		insertF(c, sum);
		sum = carry;
		return;
	}

	if(t1->prev == a)
		sum = sum + t1->data;
	else
		sum = sum + t2->data;

	while(t1->prev != a){
		sum = sum + t1->data;
		carry = sum/10;
		sum = sum%10;
		insertF(c, sum);
		sum = carry;
		t1 = t1->prev;
		flag_t1 = 1;
	}
	if(flag_t1)
		sum = sum + t1->data;
	while(t2->prev != b){
		sum = sum + t2->data;
		carry = sum/10;
		sum = sum%10;
		insertF(c, sum);
		sum = carry;
		t2 = t2->prev;
		flag_t2 = 1;
	}
	if(flag_t2)
		sum = sum + t2->data;
	if(sum>0){
		insertF(c, sum);
	}
}
void display(Node *c){
	Node *t = c;
	while(t->next != c){
		printf("%d", t->data);
		t = t->next;
	}
	printf("%d\n", t->data);
}
int main(){
	Node *A = NULL;
	Node *B = NULL;
	Node *C = NULL;
	long int d;

	printf("Enter first number: \n");
	scanf("%ld", &d);
	while(d != 0){
		insertF(&A, d%10);
		d = d/10;
	}

	printf("Enter second number: \n");
	scanf("%ld", &d);
	while(d != 0){
		insertF(&B, d%10);
		d = d/10;
	}

	Node *t11 = A;
	Node *t22 = B;

	t11 = t11->prev;
	t22 = t22->prev;
	add(t11, t22, &C);
	display(C);
}