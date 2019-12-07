#include <stdio.h>
#include <stdlib.h>

int main(){
	int l = 11, h = 13;
	int arr[] = {11,12,11,13,11};
	int n = 5;
	//Distribution Sort
	int D[h-l+1];
	for(int i = 0; i<h-l+1; i++)
		D[i] = 0;
	for(int i = 0; i<n; i++)
		D[arr[i]-l]++;
	for(int i = 1; i<h-l+1; i++)
		D[i]+=D[i-1];

	int S[n];

	for(int i = 0; i<n; i++){
		int j = arr[i]-l;
		S[D[j] - 1] = arr[i];
		D[j]--;
	}

	for(int i = 0; i<n; i++)
		printf("%d ", S[i]);
	printf("\n");
}