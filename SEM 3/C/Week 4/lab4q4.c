#include <stdio.h>
#include "stack_op.c"

void stackMove(Stack *s1, Stack *s2){

	while(s1->top != -1){
		push(s2, pop(s1));
	}

}

void operations(Stack *s, int no){
	Stack temp;
	temp.top = -1;

	stackMove(s, &temp);

	int temp1, temp2;

	while(1){
		temp1 = pop(&temp);
		temp2 = pop(&temp);

		if(temp1 > temp2){
		    push(s, temp1);
		    push(&temp, temp2);
	    }
	    else{
	    	push(s, temp2);
	    	no--;
	    	stackMove(&temp, s);
	    	stackMove(s, &temp);
	    }

	    if(no == 0 || temp1 == 666 || temp2 == 666){
	    	stackMove(&temp, s);
	    	return;
	    }
	}
}

int main(){
	Stack st, res;
	st.top = -1;
	res.top = -1;
    int n, j, k;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	printf("Enter number of deletions\n");
	scanf("%d", &k);
	printf("Enter the Elements\n");
	for(int i = 0; i<n; i++){
		scanf("%d", &j);

		push(&st, j);
	}

	operations(&st, k);

    stackMove(&st, &res);
    printf("Resultant List: \n");
	while(res.top != -1){
		printf("%d\t", pop(&res));
	}
	printf("\n");
}
