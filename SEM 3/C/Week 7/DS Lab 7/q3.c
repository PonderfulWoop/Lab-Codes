#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25
typedef struct{
	char *arr; int front,rear,capacity;
}DQ;
void init(DQ *q){
	q->arr=(char*)calloc(SIZE,sizeof(char));
	q->front=q->rear=-1;
	q->capacity=0;
}
int isFull(DQ q){
	return (q.capacity==SIZE);
}
int isEmpty(Q q){
	return (q.capacity==0);
}
void insertRight (DQ *q, char item) 
{
	if (q->rear == SIZE - 1) 
	{
		printf("OVERFLOW\n");
		return;
	}
	if (isEmpty(*q))
		q->front = q->rear = 0;
	else
		q->rear += 1;
	q->capacity += 1;
	*(q->arr + q->rear) = item;
}

char deleteLeft (DQ *q) 
{
	if (isEmpty(*q)) 
	{
		printf("EMPTY!\n");
		return UNDERFLOW_CHAR;
	}
	char item = *(q->arr + q->front);
	q->front += 1;
	q->capacity -= 1;
	
	if (isEmpty(*q))
		q->front = q->rear = -1;
	return item;
}
char deleteRight (DQ *q) 
{
	if (isEmpty(*q)) 
	{
		printf("EMPTY\n");
		return UNDERFLOW_CHAR;
	}
	char item = *(q->arr + q->rear);
	q->rear -= 1;
	q->capacity -= 1;
	if (isEmpty(*q))
		q->front = q->rear = -1;
	
	return item;
}
int palin(DQ q){
	while(q.capacity>1)
		if(strcmp(deleteLeft(&q),deleteRight(&q)))
			return 0;
	return 1;	
}
int main(){
	DQ *queue = (DQ*)calloc(SIZE, sizeof(DQ));
	init(queue);
	int i=0;
	char *str;
	scanf("%s",str);
	while(str[i]!='\0'){
		insertRight(queue,str[i]);
	}
	if(palin(*queue)==1) printf("PALINDROME");
	else printf("NOT");
	
}
