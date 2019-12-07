#include <stdio.h>
#include <stdlib.h>
int count = 0;
int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int temp;
    int i = l+1, j = r;
    count+=(j-i+1);
    do{
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }while(i<j);
    //undo last swap
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    // put pivot in its position
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;


    return j;
}

void Quicksort(int arr[], int l, int r){
    if(l<r){
        int s = partition(arr, l, r);
        Quicksort(arr, l, s-1);
        Quicksort(arr, s+1, r);
    }
}

int main(){
    int n;
    printf("Enter Number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    Quicksort(arr, 0, n-1);
    printf("Sorted Elements:\n");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Count = %d\n", count);
    exit(0);
}