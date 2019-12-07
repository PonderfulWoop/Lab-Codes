#include <stdio.h>
#include <stdlib.h>

void example(int *p1,int *p2, int *result)
{
	
  *result=(*p1)*(*p2);
	
}

void main()
{
	int n1,n2; int* result; int** pp;
    
    result=(int *) malloc(sizeof(int));
	printf("Enter the two numbers to multiply:\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	

	example(&n1,&n2,result);
	
	

	printf("\nThe answer is : %d\n",*result);

	pp=&result;
	
	printf("\nThe pp :%p, the value at pp: %d\n", *pp, **pp);
}