#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque_fun.c"

int main(){
	Deque dq;
	init(&dq);
	int ch = 0;
	char s[20], *t;
	while(ch!=5){

		printf("Enter Choice:\n");
		printf("1. InsertL\n");
		printf("2. InsertR\n");
		printf("3. Delete\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		scanf("%d", &ch);

		switch(ch){
			case 1:
			printf("Enter string->\t");
			scanf("%s", s);
			if(isFull(&dq)){
				printf("Full Queue\n");
				exit(0);
			}
			insertL(&dq, s);
			break;

			case 2:
			printf("Enter string->\t");
			scanf("%s", s);
			if(isFull(&dq)){
				printf("Full Queue\n");
			}
			else{
				insertR(&dq, s);
			}
			break;

			case 3:
			if(isEmp(&dq)){
				printf("Empty Queue\n");
			}
			else{
				t = deleteL(&dq);
				strcpy(s, t);
				printf("Deleted string: %s\n", s);
			}
			break;

			case 4:
			printf("Queue: \n");
			print(&dq);
			break;
		}
	}

	return 0;
}