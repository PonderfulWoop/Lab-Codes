#include <stdio.h>
#include <stdlib.h>

#define A 10
#define B 5
#define C 7

int Available[20], Max[20][20], Need[20][20], Allocation[20][20];
int n;

int chkSafe(){
    int Work[3];
    int Finish[n];

    for(int i = 0; i<3; i++)
        Work[i] = Available[i];
    for(int j = 0; j,n; j++)
        Finish[j] = 0;
    
    int p = 0;
    while(p<n){
        int count = 0;
        if(Finish[p] = 0){
            for(int i = 0; i<3; i++)
                if(Need[p][i] <= Work[i])
                    count++;
            if(count == 3){
                for(int i = 0; i<3; i++){
                    Work[i] = Work[i] + Allocation[p][i];
                }
                Finish[p] = 1;
                p = 0;
            }
            else
                p++;
        }
        else
            p++;
    }

    for(int i = 0; i<n; i++)
        if(!Finish[i])
            return 0;
    
    return 1;
}

int main(){
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    printf("Enter Allocation Matrix:\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            scanf("%d", &Max[i][j]);
        }
    }

    //Calculation of Need Matrix

    for(int i = 0; i<n; i++)
        for(int j = 0; j<3; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
    
    printf("Enter Available:\n");
    for(int i = 0; i<3; i++)
        scanf("%d", &Available[i]);
    
    if(chkSafe())
        printf("Safe");
    else
        printf("Unsafe");
}