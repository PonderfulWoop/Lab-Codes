#include <stdio.h>
#include "stack_op.c"

void stkMove(Stack *ps1, Stack *ps2){
	while(ps1->top != -1){
		push(ps2, pop(ps1));
	}
}

void Display(Stack s){
	for(int i = s.top; i>=0; i--){
		printf("%d\t", s.item[i]);
	}
	printf("\n");
}

int main(){
	Stack s1, s2;
	s1.top = -1;
	s2.top = -1;

	int flag = 1;
	int showFl = 0;
	int ch, a;

	while(flag){
		printf("Enter your choice: \n");
		printf("1. EnQueue \n");
		printf("2. DeQueue \n");
		printf("3. Display \n");
		printf("4. Exit \n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
			printf("Enter Element:\n");
			scanf("%d", &a);
			push(&s1, a);
			break;

			case 2:
			if(isEmpty(&s2)){
				stkMove(&s1, &s2);
			}
			pop(&s2);
			printf("Deletion complete\n");
			break;

			case 3:
			if(isEmpty(&s2)){
				stkMove(&s1, &s2);
			}
			//if(isEmpty(&s1) == 0)
			printf("Queue: \n");
			Display(s2);
			break;

			case 4:
			flag = 0;
			break;
		}
	}

}