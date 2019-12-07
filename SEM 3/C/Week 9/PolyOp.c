#include <stdio.h>
#include <stdlib.h>
#define getNode (Node*)malloc(sizeof(Node))

struct Node{
	int exp;
	int coeff;
	struct Node *next;
};

typedef struct Node Node;

void insert(Node **first, int coeff, int exp){
	Node *t = getNode;
	t->coeff = coeff;
	t->exp = exp;

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

void disp(Node *t){
	Node *s = t;
	while(s->next != t){
		printf("%dx^%d + ", s->coeff, s->exp);
		s = s->next;
	}
	printf("%dx^%d\n", s->coeff, s->exp);
}

void sub(Node *a, Node *b){
	Node *t1 = a;
	Node *t2 = b;
	Node *result = NULL;
	
	do{
		if(t1->exp == t2->exp){
			insert(&result, t1->coeff - t2->coeff, t1->exp);
			t1 = t1->next;
			t2 = t2->next;
		}
		else if(t1->exp > t2->exp){
			insert(&result, t1->coeff, t1->exp);
			t1 = t1->next;
		}
		else{
			insert(&result, -1*(t2->coeff), t2->exp);
			t2 = t2->next;
		}
	}while(t1 != a && t2 != b);
	
	while(t2 != b){
		insert(&result, -1*(t2->coeff), t2->exp);
		t2 = t2->next;
	}

	while(t1 != a){
		insert(&result, t1->coeff, t1->exp);
		t1 = t1->next;
	}


	disp(result);
}
void mult(Node *a, Node *b){
	Node *t1 = a;
	Node *t2;
	Node *result = NULL;
	do{
		t2 = b;
		do{
			insert(&result, (t1->coeff)*(t2->coeff), t1->exp + t2->exp);
			t2 = t2 ->next;

		}while(t2!=b);
		t1 = t1->next;
	}while(t1!=a);
	disp(result);
}
int main(){
	Node *A = NULL;
	Node *B = NULL;

	int in_coeff = 0;
	int in_exp = 0;
	printf("Enter coeff and exp in A and enter -1 to end\n");
	while(in_coeff != -1 && in_exp != -1){

		scanf("%d", &in_coeff);
		scanf("%d", &in_exp);
		if(in_exp != -1 && in_coeff != -1)
			insert(&A, in_coeff, in_exp);
	}
	in_exp = 0;
	in_coeff = 0;
	printf("Enter coeff and exp in B and enter -1 to end\n");
	while(in_coeff != -1 && in_exp != -1){

		scanf("%d", &in_coeff);
		scanf("%d", &in_exp);
		if(in_exp != -1 && in_coeff != -1)
			insert(&B, in_coeff, in_exp);
	}
	printf("Subtraction: \n");
	sub(A, B);
	printf("Multiplication: \n");
	mult(A, B);
}