#include <stdio.h>
#include "stack_op.c"

int main(){
	int num;
	printf("Enter the numbers of elements in the stack\n");
	scanf("%d", &num);
    Stack ps;
    ps.top = -1;
    int input;
    int ch = 0;
	while(ch!=4){
		printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			
			case 1:
			if(ps.top<num-1){
				printf("Enter the element:\n");
			    scanf("%d", &input);
		        push(&ps, input);
			}
			else
			{
				printf("Stack Overflow\n");
			}
		    break;

		    case 2:
		    if(ps.top == -1)
		    	printf("Stack Underflow.\n");
		    else
		        pop(&ps);

		    break;

		    case 3:
		    printf("Elements:\n");
		    if(ps.top == -1){
		    	printf("Empty Stack\n");
		    }
		    else{
		    	for(int i = 0; i<=ps.top; i++){
		    	printf("%d\t", ps.item[i]);
		    }
		    printf("\n");
		    }
		    break;
		}
	}

}