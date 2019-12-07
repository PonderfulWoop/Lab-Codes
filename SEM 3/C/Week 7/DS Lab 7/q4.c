#include <stdio.h>
#include <stdlib.h>
#include "Q.h"
void reverseq()
{
	int var=deleteq();
	if(!empty())
	{
		reverseq();
	}
	insertq(var);
}

int main()
{
	int n,c;
	q.rear=q.front=-1;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter values\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c);
		insertq(c);
	}
	reverseq();
	display();
	printf("\n");
}