#include <stdio.h>
#include <stdlib.h>

#define items 20

int arr[100][100];
int item_vals[items];
int item_weights[items];

int max(int a, int b){
    return (a>b)? a:b;
}

int Knap(int i, int j){
    if(arr[i][j]<0){
        int val;
        if(j<item_weights[i])
            val = Knap(i-1, j);
        else
            val = max(Knap(i-1, j), Knap(i-1, j-item_weights[i])+item_vals[i]);
        arr[i][j] = val;
    }
    return arr[i][j];
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

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=capacity; j++){
            arr[i][j] = -1;
        }
    }

    printf("Max Knapsack Value: %d\n", Knap(n, capacity));
    exit(0);
}