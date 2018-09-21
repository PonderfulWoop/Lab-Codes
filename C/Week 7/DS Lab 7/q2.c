#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25
#define UNDERFLOW_CHAR '\0'
/// Boolean type, just for readability
typedef enum { NO, YES } BOOL;

typedef struct DoubleEndedQueue
{
	char ** arr;
	int front;
	int rear;
	int capacity;
} DQ_t, *DQ_p;
// Queue methods
void initQueue (DQ_p queue)
{
	queue->arr = (char **)calloc(SIZE, sizeof(char *));
	queue->front = queue->rear = -1;
	queue->capacity = 0;
}
BOOL isFullQueue (DQ_t queue)
{
	if (queue.capacity == SIZE)
		return YES;
	return NO;
}
BOOL isEmpty (DQ_t queue)
{
	if (queue.capacity == 0)
		return YES;
	return NO;
}
void insertRight (DQ_p queue, char * item) 
{
	if (queue->rear == SIZE - 1) 
	{
		printf("\n\tQUEUE RIGHT OVERFLOW\n\n");
		return;
	}
	if (isEmpty(*queue))
		queue->front = queue->rear = 0;
	else
		queue->rear += 1;
	queue->capacity += 1;
	*(queue->arr + queue->rear) = item;
}

void insertLeft (DQ_p queue, char * item) 
{
	if (!isEmpty(*queue) && queue->front == 0) 
	{
		printf("\n\tQUEUE LEFT OVERFLOW!\n\n");
		return;
	}
	if (isEmpty(*queue))
		queue->front = queue->rear = 0;
	else
		queue->front -= 1;
	
	queue->capacity += 1;
	*(queue->arr + queue->front) = item;
}

char * deleteLeft (DQ_p queue) 
{
	if (isEmpty(*queue)) 
	{
		printf("\n\tQUEUE EMPTY!\n\n");
		return UNDERFLOW_CHAR;
	}
	char * item = *(queue->arr + queue->front);
	queue->front += 1;
	queue->capacity -= 1;
	
	if (isEmpty(*queue))
		queue->front = queue->rear = -1;
	return item;
}
char * deleteRight (DQ_p queue) 
{
	if (isEmpty(*queue)) 
	{
		printf("\n\tQUEUE EMPTY!\n\n");
		return UNDERFLOW_CHAR;
	}
	char * item = *(queue->arr + queue->front);
	queue->rear -= 1;
	queue->capacity -= 1;
	if (isEmpty(*queue))
		queue->front = queue->rear = -1;
	
	return item;
}
BOOL palindrome(DQ_t queue)
{
	while(queue.capacity>1)
		if(strcmp(deleteLeft(&queue),deleteRight(&queue)))
			return NO;
	return YES;
}

void display (DQ_t queue) 
{
	if (!isEmpty(queue)) 
	{
		printf("\n | Current Queue (f = %d, r = %d, c = %d) : \n", queue.front, queue.rear, queue.capacity);
		for (int i = queue.front; i <= queue.rear; i++)
			printf("\t\t%d) %s", i,  *(queue.arr + i));
		printf("\n\n");
	}
}
int main() 
{
	DQ_p queue = (DQ_p)calloc(SIZE, sizeof(DQ_t));
	initQueue (queue);
	char choice;
	do
	{
		printf("1. Insert Left\n2. Insert Right\n3. Delete Left\n4. Delete Right\n5. Display Queue.\n6)Palindrome\nQ. Quit:\n");
		choice = getchar();
		getchar();
		char *item = (char *)malloc(SIZE * sizeof(char));
		
		if (choice == '1') 
		{
			printf("\nEnter item to be inserted: ");
			scanf("%s",item);
			getchar();
			insertLeft(queue, item);
		}
		else if (choice == '2') 
		{
			printf("\nEnter item to be inserted: ");
			scanf("%s",item);
			getchar();
			insertRight(queue, item);
		}
		else if (choice == '3') 
		{
			item = deleteLeft(queue);
			if (item != UNDERFLOW_CHAR)
				printf("\nDeleted item: %s\n", item);
		}
		else if (choice == '4') 
		{
			item = deleteRight(queue);
			if (item != UNDERFLOW_CHAR)
				printf("\nDeleted item: %s\n", item);
		}
		else if(choice == '6')
		{
			if(palindrome(*queue))
				printf("YES!");
			else
				printf("NO!\n");
		}
		display(*queue);
	} while (choice >= '1' && choice <= '6');
	return 0;
}