#include <stdio.h>
#include <stdlib.h>
#define getNode (Node*)malloc(sizeof(Node))

struct Node{
	int num;
	struct Node *next;
};

typedef struct Node Node;

Node* ins_rear(Node *first, int n){
	Node *t = getNode;
	t->num = n;
	t->next = NULL;
	if(first == NULL){
		first = t;
		return first;
	}
	Node *last = first;
	while(last->next != NULL){
		last = last->next;
	}

	last->next = t;
	return t;

}

Node* del_front(Node *first){
	if(first == NULL){
		printf("Empty\n");
		return NULL;
	}
	else{
		Node *t = first;
		first = first->next;
		printf("Deleted: %d\n", t->num);
		free(t);
		return first;
	}
}

void disp(Node *first){
	if(first == NULL){
		printf("Empty\n");
		return;
	}
	while(first != NULL){
		printf("%d\n", first->num);
		first = first->next;
	}
}

int main(){
	Node *first = NULL;
	Node *last = NULL;
	int ch = 0;
	int flag = 0;
	int in;
	
	while(ch != 4){
		printf("Enter\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	    scanf("%d", &ch);
		switch(ch){
		case 1:
		printf("Enter Elem\n");
		scanf("%d", &in);
		last = ins_rear(last, in);
		if(flag == 0){
			first = last;
			flag = 1;
		}
		break;

		case 2:
		first = del_front(first);
		break;

		case 3:
		disp(first);
		break;
	}
	}
}
