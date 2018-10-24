#include <stdio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for(int j = low; j<=high-1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void qS(int arr[], int low, int high){
	if(low<high){
		int p = partition(arr, low, high);

		qS(arr, low, p-1);
		qS(arr, p+1, high);
	}
}

int main(){
	int arr[] = {2,5,3,1,9,77};
	qS(arr, 0, 5);
	for(int i = 0; i<6; i++){
		printf("%d ", arr[i]);
	}
}