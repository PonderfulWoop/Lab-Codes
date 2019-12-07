#include <stdlib.h>
#include <stdio.h>

int perms[1000][1000];
int count = 0;
void gen(int arr[], int l, int r){
    if(l == r){
        for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
            perms[count][i] = arr[i];
        }
        count++;
    }
    else{
        for(int j = l; j<=r; j++){
            swap(arr+l, arr+j);
            gen(arr, l+1, r);
            swap(arr+l, arr+j);
        }
    }
}