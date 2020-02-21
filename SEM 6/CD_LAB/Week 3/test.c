#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This is to check a number is
	prime or not */

int prime (int k){
	int i;
	//This uses math function
	for (i = 0;i <= sqrt(n); i++)
		if(n%i == 0 && i<=n)
			return 0;	
		return 1 ;
}

int main(){
	int n;
	int i;
	int x[10];
	printf("Enter");
	scanf ("%d", &n);
/*
call and display prime
*/
	for(i = 0;i < n; i++)
		if(prime(x[i]))
			printf ( "prime" );
		else
			printf("notprime");
	
	return 0;
}