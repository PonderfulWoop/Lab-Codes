#include <stdio.h>

void tower(int n, char src, char aux, char dest){
	
	if(n == 1){
		printf("move disc 1 from %c to %c \n", src, dest);
		return;
	}
	tower(n-1, src, dest, aux);

	printf("move disc %d from %c to %c \n", n, src, dest);

	tower(n-1, aux, src, dest);
}

int main(){
	printf("Enter number of discs: \n");
	int i, moves = 1;
	scanf("%d", &i);
	tower(i, 'A', 'B', 'C');
	for(int n = 1; n<=i; n++){
		moves = moves*2;
	}
	moves--;
	printf("Number of moves = %d \n", moves);
}