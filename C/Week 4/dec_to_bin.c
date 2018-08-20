#include <stdio.h>
#include "stack_op.c"



int DecToBin(int x, Stack *st){
    int rem;
	while(x > 0){
		rem = x%2;
		push(st, rem);
		x = x/2;
	}
}

void displayRes(Stack *st){
	int bin = 0;
	while(!isEmpty(st)){
		bin = bin*10 + pop(st);
	}
	printf("Binary Conversion: \n");
	printf("%d\n", bin);
}

int main(){
	int a;
	Stack st;
    st.top = -1;
	printf("Enter the Number to convert: \n");
	scanf("%d", &a);
	DecToBin(a, &st);
	displayRes(&st);
}