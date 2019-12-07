#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char *str;
	struct Node *rLink;
	struct Node *lLink;

};

typedef struct Node Node;

Node* getNode(){
	Node *t = (Node*)malloc(sizeof(int));
	t->str = (char*)malloc(sizeof(char));
	t->lLink = t;
	t->rLink = t;
	return t;
}

void insert_elem(Node **first, char *s){
	Node *t = getNode();
	Node *p;
	strcpy(t->str,s);

	t->rLink = *first;
	(*first)->lLink = t;

	if((*first)->rLink == (*first)){
		t->lLink = *first;
		(*first)->rLink = t;
	}
	else{
		p = (*first)->rLink;
		while(p->rLink != (*first)){
			p = p->rLink;
		}
		t->lLink = p;
		p->rLink = t;

	}
}

void display(Node *last){
	Node *t = last;
	while(t->lLink != last){
		printf("%s\t", t->str);
		t = t->lLink;
	}
	printf("\n");
}

int main(){
	Node *first = getNode();
	char *str;
	Node *t = first;
	int ch = 0;
	while(ch!=3){
		printf("Enter: 1. Insert\t2. Display\t3. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
			printf("Enter string\n");
			scanf("%s", str);
			insert_elem(&first, str);
			break;

			case 2:
			while(t->rLink != first)
				t = t->rLink;
			display(t);
			break;
		}
	}
}