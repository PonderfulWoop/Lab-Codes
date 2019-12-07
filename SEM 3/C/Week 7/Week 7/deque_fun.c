#include <stdio.h>
#include <string.h>

#define MAX 30
#define MAX_STR 20

typedef struct{
	char data[MAX][MAX_STR];
	int rear, front;
}Deque;

void init(Deque *q);
int isEmp(Deque *q);
int isFull(Deque *q);
void insertR(Deque *q, char *x);
void insertL(Deque *q, char *x);
char* deleteR(Deque *q);
char* deleteL(Deque *q);

void init(Deque *q){
	q->rear = q->front = -1;
}

int isEmp(Deque *q){
	if(q->rear == -1)
		return 1;
	else
		return 0;
}

int isFull(Deque *q){
	if((q->rear + 1)%MAX == q->front)
		return 1;
	else
		return 0;
}

void insertR(Deque *q, char *x){
	if(isEmp(q)){
		q->front = q->rear = 0;
		strcpy(q->data[0], x);
	}
	else{
		q->rear = (q->rear+1)%MAX;
		strcpy(q->data[q->rear], x);
	}

}

void insertL(Deque *q, char *x){
	if(isEmp(q)){
		q->front = q->rear = 0;
		strcpy(q->data[0], x);
	}
	else{
		q->front = (q->front-1+MAX)%MAX;
		strcpy(q->data[q->front], x);
	}
}

char* deleteL(Deque *q){
	char *temp;
	strcpy(temp, q->data[q->front]);
	
	if(q->front == q->rear)
		init(q);
	else
	    q->front = (q->front+1)%MAX;

	printf("%d\n", q->front);
	return temp;
}
void print(Deque *q){
	if(isEmp(q)){
		printf("Empty!!!!!\n");
		return;
	}
	int i = q->front;
	printf("%d\n", i);
	while(i!=q->rear){
		printf("%s\t", q->data[i]);
		i = (i+1)%MAX;
	}
	printf("%s\n", q->data[q->rear]);
}