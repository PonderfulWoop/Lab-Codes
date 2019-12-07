#include <stdio.h>

int fibo(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return (fibo(n-1) + fibo(n-2));
}

int main(){
	int in;
	printf("Enter no. of terms in the fibonacci series\n");
	scanf("%d", &in);
	int i = 0;
	for(int c = 1; c<=in; c++){
		printf("%d\t", fibo(i));
		i++;
	}
	printf("\n");
	return 0;
}