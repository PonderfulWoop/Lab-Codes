#include <stdio.h>

int Sum(int *num1, int *num2)
{
	int sum = *num1 + *num2;

	return sum;
}

int main()
{
	int n1, n2;
	printf("Enter two numbers\n");
	scanf("%d%d", &n1, &n2);

	printf("Sum = %d\n", Sum(&n1, &n2));

}