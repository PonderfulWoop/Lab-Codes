#include <stdio.h>
#include <string.h>
#include "stack_op.c"

int isDigit(char x){
	if(x>='0' && x<='9')
		return 1;

	return 0;
}

int evaluate(char ch, int op1, int op2){
	
	if(ch == '+')
		return op1 + op2;
	else if(ch == '-')
		return op1 - op2;
	else if(ch == '*')
		return op1*op2;
	else if(ch == '/')
		return op1/op2;
	else if(ch == '%')
		return op1%op2;
}

int main(){
	Stack s;
	s.top = -1;
	char x[100];
	int op1, op2, val;

	printf("Enter the Expression: \n");
	scanf("%s", x);

	for(int i = strlen(x) - 1; i>=0; i--){
		if(isDigit(x[i])){
			push(&s, x[i] - '0');
		}
		else{
			op1 = pop(&s);
			op2 = pop(&s);

			val = evaluate(x[i], op1, op2);

			push(&s, val);
		}
	}

	val = pop(&s);

	printf("Value of the Expression is: %d\n", val);

}