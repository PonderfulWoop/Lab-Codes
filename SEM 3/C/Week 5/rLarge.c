#include <stdio.h>

int rLarge(int arr[], int * ptr, int n){
   

   if(n == 1)
   	  return *ptr;

   
   	if(*ptr<arr[1])
   		ptr = &arr[1];
   
   rLarge(++arr, ptr,  n-1);
}

int main(){
	int n;
	int a[100];
	printf("Enter the number of elements\n");
	scanf("%d", &n);

	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}

	int largest = rLarge(a, &a[0], n);

	printf("Largest = %d", largest);
}