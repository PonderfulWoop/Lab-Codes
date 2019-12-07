#include <stdio.h>

#define MAXCHAR 10
#define MAXSTR 20

typedef struct{
	int rear, front;
	char str[20][10];
}StringQueue;

void insertcq(StringQueue *q, char value[]){
	if ((q->front == 0 && q->rear == MAXSTR-1) ||
            (q->rear == (q->front-1)%(MAXSTR-1)))
    {
        printf("\nQueue is Full");
        return;
    }
    else if (q->front == -1) /* Insert First Element */
    {
        q->front = q->rear = 0;
        q->str[q->rear] = value;
    }
 
    else if (q->rear == MAXSTR-1 && q->front != 0)
    {
        q->rear = 0;
        q->str[q->rear] = value;
    }
 
    else
    {
        q->rear++;
        q->str[q->rear] = value;
    }
}

void deletecq(StringQueue *q){
	if (q->front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
 
    char data[] = q->str[q->front];
    q->str[q->front] = -1;
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->front == MAXSTR-1)
        q->front = 0;
    else
        (q->front)++;
 
    return;
}

void displaycq(StringQueue q){
	if (q.front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (q.rear >= q.front)
    {
        for (int i = q.front; i <= q.rear; i++)
            printf("%s ",q.str[i]);
    }
    else
    {
        for (int i = q.front; i < MAXSTR; i++)
            printf("%s ", q.str[i]);
 
        for (int i = 0; i <= q.rear; i++)
            printf("%s ", q.str[i]);
    }
}

int main()
{
    
 
    // Inserting elements in Circular Queue
    
    return 0;
}
