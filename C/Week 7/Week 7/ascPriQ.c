#include <stdio.h>
#include "pqueue_fun.c"

int main(){
	int ch = 0;
	Queue q;
	q.front = q.rear = -1;
	int in;
	while(ch!=4){

		printf("Enter Choice:\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		scanf("%d", &ch);

		switch(ch){
			case 1:
			printf("Enter Element\n");
			scanf("%d", &in);
			insertQ(&q, in);
			break;

			case 2:
			deleteQ(&q);
			break;

			case 3:
			displayQ(q);
			break;
		}

	}
}