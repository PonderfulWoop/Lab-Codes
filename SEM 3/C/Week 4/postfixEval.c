#include <stdio.h>
#include "stack_op.c"


double oper(char ch, double op1, double op2){
	if(ch == '+')
		return op1+op2;
	else if(ch == '-')
		return op1 - op2;
	else if(ch == '*')
		return op1*op2;
	else if(ch == '/')
		return op1/op2;
	else if(ch == '^')
		{
			double num = 1;
			for(int i = 1; i<= op2; i++){
				num*=op1;
			}
		    return num;
		}
}

int isDigit(char ch){
	return (ch>='0' && ch>='9' ? 1:0);
}

double eval_postfix(char exp[]){
	Stack st;
	st.top = -1;
    
    char ch;
	double op1, op2, res;

	for(int i = 0; (ch = exp[i]) != '\0'; i++){
		if(isDigit(ch)){
			push(&st, (int)(ch - '0'));
		}
		else{
			op2 = (double) pop(&st);
			op1 = (double) pop(&st);
			res = oper(ch, op1, op2);
			push(&st, (int) res);
		}
	}

	if(st.top == 0)
		return (double) pop(&st);
	else
		printf("Bad Expression\n");
}

int main(){
	char str[100];
	printf("Enter Expression: \n");
	scanf("%s", str);

	printf("Result: \n");
	printf("%d\n", eval_postfix(str));

}