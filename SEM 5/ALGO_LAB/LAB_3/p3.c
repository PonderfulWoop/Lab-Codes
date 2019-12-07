#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int powerSet[10000][10000];
unsigned pow_set_size;
int setsize;
int sum;

int getSetSum(int i){
    int setsum = 0;
    for(int l=0; l<setsize; l++){
        setsum += powerSet[i][l];
    }
    return setsum;
}
int isDisjoint(int i, int k){
    for(int q = 0; q<setsize; q++){
        if(powerSet[i][q] == powerSet[k][q] && powerSet[i][q] != 0 && powerSet[k][q] != 0)
            return 0;
    }
    return 1;
}
void genPowSet(int arr[]){

    pow_set_size = pow(2, setsize);
    int counter, j;
    for(counter = 0; counter<pow_set_size; counter++){
        for(j=0; j<setsize; j++){
            if(counter & (1<<j)){
                powerSet[counter][j] = arr[j];
            }
        }
    }
}

void printSubset(int i){
    for(int l=0; l<setsize; l++){
        if(powerSet[i][l])
            printf("%d ", powerSet[i][l]);
    }
    printf("\n");
}

int partition(){
    int flag = 0;
    for(int i = 0; i < pow_set_size-1; i++){
        for(int k = i+1; k < pow_set_size; k++){
            int sum1 = getSetSum(i);
            int sum2 = getSetSum(k);
            if(sum1+sum2 == sum && sum1 == sum2 && isDisjoint(i, k)){
                printSubset(i);
                printSubset(k);
                flag = 1;
                return flag;
            }
            
        }
    }
    return flag;
}

int main(){
    int arr[100];
    int n;
    sum = 0;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    setsize = n;
    printf("Enter elements: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    genPowSet(arr);
    int q = partition();
    if(q)
        printf("YASSSSSS\n");
    else
        printf("NOOOOOO\n");
}