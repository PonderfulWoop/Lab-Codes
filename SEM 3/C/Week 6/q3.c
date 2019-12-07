#include <stdio.h>
#include "queue_fun.c"

int checkElem(Queue q, int el){
	for(int i = q.front; i < q.rear; i++){

		if(q.elem[i] == el)
			return 1;
	}
}

int main(){
	Queue que;
	que.front = -1;
	que.rear = -1;
	
	int x;
	printf("Enter number of elements:\n");
	scanf("%d", &x);
	int in;
	printf("Enter elements:\n");
	for(int i = 0; i<x; i++){

		scanf("%d", &in);
		insertQ(&que, in);

	}
	printf("Enter element to find:\n");
	int k;
	scanf("%d", &k);

	if(checkElem(que, k))
		printf("The element is present\n");
	else
		printf("The element is not present\n");
}