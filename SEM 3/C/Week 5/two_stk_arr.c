#include <stdio.h>
#include "stack_op.c"

void stkMove(Stack *ps1, Stack *ps2){
	while(ps1->top != -1){
		push(ps2, pop(ps1));
	}
}

int main(){
	Stack s1, s2;
	s1.top = -1;
	s2.top = -1;
    
    int n, in;

	printf("Enter number of elements: \n");
	scanf("%d", &n);
    printf("Enter %d elements: \n", n);

	for(int i = 0; i<n; i++){

		scanf("%d", &in);
		push(&s1, in);
	}

	stkMove(&s1, &s2);

	int arr[100];

	for(int k = 0; k<n; k++){
		arr[k] = pop(&s2);
	}

	printf("Elements in the array are: \n");
	for(int j = 0; j<n; j++){
		printf("%d\t", arr[j]);
	}
	printf("\n");
}