#include <stdio.h>
#include "stack_op_char.c"
#include <string.h>


int isOperand(char ch){

	return (ch >= 'A' && ch <= 'Z');

}

int isOperator(char ch){

	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char stackTop(Stack s){
	return s.item[s.top];
}

int prece(char ch){
	switch(ch){
		case '#':
		return -1;
		break;

		case ')':
		return 0;
		break;

		case '+':
		return 1;
		break;

		case '-':
		return 1;
		break;

		case '*':
		return 2;
		break;

		case '/':
		return 2;
		break;

		case '^':
		return 3;
		break;

		default:
		printf("Invalid Character\n");
	}
}

void inf_pre(char inf[], char pre[], Stack *s){
	push(s, '#');
	char ch; int i, j = 0;
	for(int i = strlen(inf) - 1; i>=0; i--){
		
		if(isOperand(ch)){
			pre[j++] = ch;
		}
		else if(ch == ')'){
			push(s, ch);
		}
		else if(ch == '('){
			while(1){

				if(stackTop(*s) != ')'){
					pre[j++] = pop(s);
				}
				else{
					pop(s);
					break;
				}
			}
		}
		else if(isOperator(ch)){
			if(prece(ch) >= prece(stackTop(*s)))
				push(s, ch);
			else{
				while(1){
					pre[j++] = pop(s);
					if(prece(ch) >= prece(stackTop(*s))){
						push(s, ch);
						break;
					}
				}
			}
		}
	}

	while((*s).top != 0){
		pre[j++] = pop(s);
	}
	pre[j] = '\0';
}

int main(){
    Stack st;
    st.top = -1;
	char exp[100], exp_pre[100];
	printf("Enter the expression: \n");
	scanf("%s", exp);
    
	inf_pre(exp, exp_pre, &st);

	printf("%s\n", exp_pre);
}