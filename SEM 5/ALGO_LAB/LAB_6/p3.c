#include <stdio.h>
#include <stdlib.h>
int count = 0;
void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int t1[n1], t2[n2];

    int i = 0, j = 0, k = l;
    for(int p = l; p<=m; p++){
        t1[i] = arr[p];
        i++;
    }
    for(int q = m+1; q<=r; q++){
        t2[j] = arr[q];
        j++;
    }
    i = j = 0;
    while(i<n1 && j<n2){
        if(t1[i]>t2[j]){
            arr[k] = t2[j];
            j++;
            k++;
        }
        else{
            arr[k] = t1[i];
            i++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = t1[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = t2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r){
    count++;
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n;
    printf("Enter no. of elems:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elems:\n");
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n-1);

    printf("Sorted array: \n");
    for(int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Count = %d\n", count);
}