#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int partitions[10], processes[10];
int m, n;

void WorstFit(){
    int extra[m];
    int allocs[n];
    for(int i = 0; i<n; i++)
        allocs[i] = -1;
    for(int i = 0; i<m; i++)
        extra[i] = partitions[i];
    
    for(int i = 0; i<n; i++){
        int diff = INT_MIN;
        int pos = -1;
        for(int j = 0; j<m; j++){
            int test = extra[j] - processes[i];
            if(test>0 && test > diff){
                diff = test;
                pos = j;
            }
        }
        if(pos>-1){
            extra[pos]-=processes[i];
            allocs[i] = pos;
        }
    }

    for(int i = 0; i<n; i++)
        if(allocs[i] == -1){
            printf("Cannot accomodate all\n");
            exit(0);
        }
    printf("Strategy success: \n");
}

int main(){

    printf("Enter number of Partions and Processes: \n");
    scanf("%d %d", &m, &n);

    printf("Enter Processes: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &processes[i]);
    printf("Enter Partions: \n");
    for(int i = 0; i<m; i++)
        scanf("%d", &partitions[i]);
    
    WorstFit();
}