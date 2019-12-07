#include <stdio.h>

void InsertionSort(int arr[], int n){
	for(int i = 1; i<n; i++){
		int key = arr[i];
		int j = i-1;

		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	int arr[] = {3,5,4,2,1};
	InsertionSort(arr, 5);
	for(int k = 0; k<5; k++)
		printf("%d ", arr[k]);
	printf("\n");
}