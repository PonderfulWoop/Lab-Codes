#include <stdio.h>
#include <stdlib.h>

static int sub_count = 0;
int n;
void subset_sum(int list[], int sum, int start, int target){
	if(target == sum){
		sub_count++;
		if(start<n)
			subset_sum(list, sum - list[start - 1], start, target);
	}
	else{
		for(int i = start; i<n; i++){
			subset_sum(list, sum+list[i], i+1, target);
		}
	}
}

int main(){
	printf("Enter number of elems\n");
	scanf("%d", &n);
	int list[n], d;
	printf("Enter numbers:\n");
	for(int i = 0; i<n;i++)
		scanf("%d", &list[i]);
	printf("Enter sum:\n");
	scanf("%d", &d);

	subset_sum(list, 0, 0, d);
	printf("No. such subsets: %d\n", sub_count);

	exit(0);
}