#include <stdio.h>
#include <stdlib.h>

int counter = 0;

void inversions(int arr[], int l, int m, int h){
    int i = l;
    int j = m+1;
    for(i = l; i<=m; i++){
        for(j = m+1; j<=h; j++){
            if(arr[i]>arr[j])
                counter++;
        }
    }
}

void findInv(int arr[], int l, int h){
    if(l<h){
        int m = l + (h-l)/2;
        findInv(arr, l, m);
        findInv(arr, m+1, h);
        inversions(arr, l, m, h);
    }
}

int main(){
    int arr[20];
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Enter nos: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    findInv(arr, 0, n-1);
    printf("Counter: %d\n", counter);
    exit(0);
}