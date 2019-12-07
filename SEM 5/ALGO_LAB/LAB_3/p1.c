#include <stdlib.h>
#include <stdio.h>
int opcount = 0;
void bubblesort(int *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if (a[j]>a[j+1]){
                opcount++;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int *arr;
    int n;
    
    printf("Enter number of elems:\n");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n);
    printf("Enter elems: \n");
    for(int k = 0; k<n; k++){
        scanf("%d", &arr[k]);
    }
    bubblesort(arr, n);
    printf("Elems after sort:\n");
    for(int k = 0; k<n; k++){
        printf("%d ", arr[k]);
    }
    printf("\n %d \n", opcount);

    return 0;
}