#include <stdio.h>
#include "queue_fun.c"

void revQ(Queue *q){
	int var = deleteQ(q);
	if(q->front != -1 && q->front != -1){
		revQ(q);
	}
	insertQ(q, var);
}


int main(){
	Queue que1;
	que1.front = -1;
	que1.rear = -1;
	
	int x;
	printf("Enter number of elements:\n");
	scanf("%d", &x);
	int in;
	printf("Enter elements:\n");
	for(int i = 0; i<x; i++){

		scanf("%d", &in);
		insertQ(&que1, in);

	}
	revQ(&que1);
	displayQ(que1);
	return 0;
}