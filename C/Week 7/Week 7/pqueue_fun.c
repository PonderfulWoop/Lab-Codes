#include <stdio.h>

#define MAX 100

typedef struct{
	int elem[MAX];
	int front;
	int rear;
}Queue;

void insertQ(Queue *q, int e){
	if(q->rear == MAX){
		printf("Overflow\n");
	}
	else{
		q->elem[++q->rear] = e;
		if(q->front == -1)
			q->front = 0;
	}
}

int deleteQ(Queue *q){
	int x;
	if(q->front == -1)
		printf("Underflow\n");
	else if(q->front == q->rear){
		x = q->elem[q->front];
		q->front = q->rear = -1;
		return x;
	}
	else{
		int smallest = q->elem[q->front];
		int pos = q->front;
		for(int i = q->front+1; i<=q->rear; i++){

			if(smallest>q->elem[i]){
				smallest = q->elem[i];
				pos = i;
			}
		}
		printf("%d\t", smallest);
		printf("%d\n", pos);
		int del = q->elem[pos];
		for(int i = pos; i>0; i--){
			q->elem[i] = q->elem[i-1];
		}
		q->front++;
		return del;
	}
}

void displayQ(Queue q){
	
	if(q.front == -1 && q.rear == -1){
		printf("Queue is Empty\n");
	}
	else{
		printf("Queue is: \n");
		for(int i = q.front; i <=q.rear; i++){
			printf("%d\t", q.elem[i]);
		}
	}
}