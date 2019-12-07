#include <stdio.h>
#include "stack_op_char.c"

void addToStack(Stack *st, char s[]){
	for(int i = 0; s[i] != '\0'; i++){
		push(st, s[i]);
	}
}

int chk(Stack *st, char s[]){
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] != pop(st))
			return 0;
	}

	return 1;
}

int main(){
	char str[100];
	Stack st;
    st.top = -1;
	printf("Enter the String: \n");
	scanf("%s", str);

	addToStack(&st, str);

	if(chk(&st, str))
		printf("\nPalindrome \n");
	else
		printf("\nNot Palindrom \n");
}