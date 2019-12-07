#include <stdio.h>
#include <stdlib.h>

#define items 20

int item_vals[items];
int item_weights[items];
int opt_sub[items];

int max(int a, int b){
    return (a>b)? a:b;
}

int getKnap(int n, int capacity){
    int arr[n+1][capacity+1];

    for(int i = 0; i<=n; i++)
        arr[i][0] = 0;
    for(int j = 0; j<=capacity; j++)
        arr[0][j] = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=capacity; j++){
            if(item_weights[i]>j){
                arr[i][j] = arr[i-1][j];
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i-1][j-item_weights[i]] + item_vals[i]);
            }
        }
    }
    int k = 0;
    int cap = capacity;
    int point = n;
    while(cap>0){
        if(arr[point][cap] != arr[point-1][cap]){
            opt_sub[k] = point;
            k++;
            cap-=item_weights[point];
            point--;
        }
        else{
            point--;
        }
    }
    for(int i = 0; i<k; i++)
        printf("%d ", opt_sub[i]);
    printf("\n");
}

int main(){
    int n, capacity;

    printf("Enter number of items: \n");
    scanf("%d", &n);

    printf("Enter values of items: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &item_vals[i]);
    
    printf("Enter weights of items: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &item_weights[i]);
    
    printf("Enter Capacity:\n");
    scanf("%d", &capacity);

    getKnap(n, capacity);

    exit(0);
}