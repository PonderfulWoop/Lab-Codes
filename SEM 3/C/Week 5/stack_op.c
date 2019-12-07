#include <stdio.h>

#define MAX 100
#define true 1
#define false 0

typedef struct{
	int item[MAX];
	int top;
}Stack;

void push(Stack *ps, int elem){
	if((*ps).top != MAX-1){
		ps->top++;
		ps->item[ps->top] = elem;
	}
	else{
		printf("Stack Overflow\n");
	}
}

int isEmpty(Stack *ps){
	if(ps->top == -1){
		return true;
	}
	else
		return false;
}

int pop(Stack *ps){
	if(!isEmpty(ps)){
		return (ps->item[ps->top--]);
	}
}
