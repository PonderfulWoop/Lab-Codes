#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void BestFit(int part[], int proc[], int proc_n, int p){

    int allocs[proc_n];
    int parts[p];

    for(int i = 0; i<p; i++)
        parts[i] = part[i];

    for(int i = 0; i<proc_n; i++)
        allocs[i] = -1;

    for(int i = 0; i<proc_n; i++){
        int diff = (int) INFINITY;
        for(int j = 0; j<p; j++){
            int test = parts[j] - proc[i];
            if(test > 0 && test < diff){
                diff = test;
                allocs[i] = j;
            }
        }
        parts[allocs[i]]-=proc[i];
    }

    printf("Best-Fit Allocations: \n");
    for(int i = 0; i<proc_n; i++){
        if(allocs[i]>=0)
            printf("P%d with %dK req was allocated %dK partition.\n", i, proc[i], part[allocs[i]]);
        else
            printf("P%d with %dK req can't be fit.\n", i, proc[i]);
    }
    printf("\n");
}

void WorstFit(int part[], int proc[], int proc_n, int p){

    int allocs[proc_n];
    int parts[p];

    for(int i = 0; i<p; i++)
        parts[i] = part[i];

    for(int i = 0; i<proc_n; i++)
        allocs[i] = -1;

    for(int i = 0; i<proc_n; i++){
        int diff = (int)-INFINITY;
        for(int j = 0; j<p; j++){
            int test = parts[j] - proc[i];
            if(test > 0 && test > diff){
                diff = test;
                allocs[i] = j;
            }
        }
        parts[allocs[i]]-=proc[i];
    }

    printf("Worst-Fit Allocations: \n");
    for(int i = 0; i<proc_n; i++){
        if(allocs[i]>=0)
            printf("P%d with %dK req was allocated %dK partition.\n", i, proc[i], part[allocs[i]]);
        else
            printf("P%d with %dK req can't be fit.\n", i, proc[i]);
    }
    printf("\n");
}

void FirstFit(int part[], int proc[], int proc_n, int p){
    int allocs[proc_n];
    int parts[p];

    for(int i = 0; i<p; i++)
        parts[i] = part[i];

    for(int i = 0; i<proc_n; i++)
        allocs[i] = -1;

    for(int i = 0; i<proc_n; i++){
        for(int j = 0; j<p; j++){
            int test = parts[j] - proc[i];
            if(test > 0){
                allocs[i] = j;
                parts[j]-=proc[i];
                break;
            }
        }
    }

    printf("First-Fit Allocations: \n");
    for(int i = 0; i<proc_n; i++){
        if(allocs[i]>=0)
            printf("P%d with %dK req was allocated %dK partition.\n", i, proc[i], part[allocs[i]]);
        else
            printf("P%d with %dK req can't be fit.\n", i, proc[i]);
    }
    printf("\n");
}

int main(){
    int p, part[10], proc[10], proc_n;
    
    printf("Enter number of partitions: \n");
    scanf("%d", &p);

    printf("Enter number of processes: \n");
    scanf("%d", &proc_n);

    printf("Enter partitions: \n");
    for(int i = 0; i<p; i++)
        scanf("%d", &part[i]);
    
    printf("Enter Process sizes: \n");
    for(int i = 0; i<proc_n; i++)
        scanf("%d", &proc[i]);
    
    printf("\n");
    //BEST-FIT
    BestFit(part, proc, proc_n, p);

    //WORST-FIT
    WorstFit(part, proc, proc_n, p);

    //FIRST-FIT
    FirstFit(part, proc, proc_n, p);

    exit(0);
}