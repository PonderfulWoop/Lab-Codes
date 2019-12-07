#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getNode (Node*)malloc(sizeof(Node))

struct Node
{
	char data;
	struct Node *next;	
};

typedef struct Node Node;

Node* insert(Node *first, char data){
	Node *t = getNode;
	t->data = data;
	t->next = first->next;
	if(first == NULL){
		first = t;
		return first;
	}
	first->next = t;
	return t;
}

void disp(Node *first){
	if(first == NULL){
		printf("Empty\n");
		return;
	}
	while(first != NULL){
		printf("%c ", first->data);
		first = first->next;
	}
	printf("\n");
}

int main(){
	Node *first_1 = getNode;
	Node *first_2 = getNode;
	Node *first_3 = getNode;
	Node *last_1 = getNode;
	Node *last_2 = getNode;
	Node *last_3 = getNode;
	last_1->next = first_1;
	last_2->next = first_2;
	last_3->next = first_3;
	int flag = 0;
	int in;
	char *input;
	
	printf("Enter number of elements in list 1\n");
	scanf("%d", &in);
	printf("Enter Elements\n");
	for(int i = 0; i<in; i++){
		scanf("%s", input);
		last_1 = insert(last_1, input[0]);
		if(flag == 0){
			first_1 = last_1;
			flag = 1;
		}
	}
	flag = 0;
	printf("Enter number of elements in list 2\n");
	scanf("%d", &in);
	printf("Enter Elements\n");
	for(int i = 0; i<in; i++){
		scanf("%s", input);
		last_2 = insert(last_2, input[0]);
		if(flag == 0){
			first_2 = last_2;
			flag = 1;
		}
	}
    flag = 0;
	while(first_1!=NULL && first_2!=NULL){
		if(first_1->data>first_2->data){
			last_3 = insert(last_3, first_2->data);
		    if(flag == 0){
			    first_3 = last_3;
			    flag = 1;
		   }
		   first_2 = first_2->next;
		}
		else{
			last_3 = insert(last_3, first_1->data);
		    if(flag == 0){
			    first_3 = last_3;
			    flag = 1;
		   }
		   first_1 = first_1->next;
		}
	}

	if(first_1 == NULL){
		while(first_2 != NULL){
			last_3 = insert(last_3, first_2->data);
			first_2 = first_2->next;
		}
	}

		if(first_2 == NULL){
		while(first_1 != NULL){
			last_3 = insert(last_3, first_1->data);
			first_1 = first_1->next;
		}
	}

	printf("Merged List: \n");
	disp(first_3);
}