#include <stdio.h>
#include "stack_op.c"
#include <string.h>

void isBal(char exp[], Stack *s){
	for(int i = 0; exp[i] != '\0'; i++){

		if(exp[i] == '('){
			push(s, exp[i]);
		}
		else if(exp[i] == ')'){
			if(isEmpty(s)){
				printf("No Left Parenthesis\n");
				return;
			}
			pop(s);
		}

	}

	if(isEmpty(s)){
		printf("Balanced Expression\n");
		return;
	}
	else
	{
		printf("No Right Parenthesis\n");
		return;
	}
}

int main(){
	Stack s;
	s.top = -1;

    char x[100];

	printf("Enter the Expression: \n");
	scanf("%s", x);

	isBal(x, &s);
}