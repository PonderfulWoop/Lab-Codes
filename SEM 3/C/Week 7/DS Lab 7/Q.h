#define MAX 20
struct Q
{
	int x[MAX];
	int front,rear;
}q;
void insertq(int x)
{
	if(q.rear==MAX)
		printf("Overflow\n");
	else
	{
		q.x[++q.rear]=x;
		if(q.front=-1)
		{
			q.front=0;
		}
	}
}
int deleteq()
{
	int x;
	if(q.front==-1)
		printf("Underflow\n");
	else if(q.front==q.rear)
	{
		x=q.x[q.front];
		q.front=q.rear=-1;
		return x;
	}
	else
		return q.x[q.front++];
}
void display()
{
	if(q.front==-1&&q.rear==-1)
	{
		printf("EMPTY\n");
		return;
	}
	for(int i=q.front;i<=q.rear;i++)
		printf("%d ",q.x[i]);
	return;
}
int empty()
{
	return (q.front==-1);
}