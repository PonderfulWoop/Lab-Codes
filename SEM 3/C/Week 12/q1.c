#include <stdio.h>


void mergeSort(int a[], int smin, int n, int c[]){
	int k = 0;
	int i, j;
	for(i = 0, j = smin; i<smin && j<n;){
		if(a[i]<a[j]){
			c[k] = a[i];
			k++;
			i++;
		}
		else{
			c[k] = a[j];
			k++;
			j++;
		}
	}

	while(i<smin){
		c[k] = a[i];
			k++;
			i++;
	}
	while(j<n){
		c[k] = a[j];
		k++;
		j++;
	}
}

int main(){
	int a[] = {2,5,32,1,3,4};
	int c[6];
	int n = 6;
	mergeSort(a, 3, 6, c);
	for(int i = 0; i<6; i++){
		printf("%d ", c[i]);
	}
}