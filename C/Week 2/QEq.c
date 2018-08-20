#include <stdio.h>
#include <math.h>

void getData(int *x, int *y, int *z)
{
	
	printf("Enter the coefficients: \n");
	scanf("%d%d%d", x, y, z);
	
}

void quadratic(int a, int b, int c, double *r1, double *r2)
{
	int D = (b*b)-(4*a*c);
	int flag;

	if(D>0)
		flag=1;
	else 
	  {if(D==0)
		flag=2;
	     else flag=3;}

	switch(flag)
	{
		case 1: *r1=(-b-sqrt(D))/(2*a);
		        *r2=(-b+sqrt(D))/(2*a);
		        break;

		case 2: *r1=(-b)/(2*a);
		        *r2=*r1;
		        break;

		case 3: *r1=99999;
		        *r2=*r1;
		        break;
       
	} 
}	



void print_roots(int r1, int r2)
{
	if(r1==99999)
		{printf("\nRoots are imaginary.\n");}
	else
		{printf("\nRoots are: %d & %d\n",r1,r2);}

}

void main()
{
	int x,y,z; double r1,r2;

	
	getData(&x,&y,&z);

	quadratic(x,y,z,&r1,&r2);

	print_roots(r1,r2);


}



