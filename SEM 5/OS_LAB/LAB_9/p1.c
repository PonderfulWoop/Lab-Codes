#include <stdio.h>
#include <stdlib.h>

int n, m;
int Available[20], Max[20][20], Allocation[20][20], Need[20][20];

void calc_need(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

int isSafe(){
    int Work[m];
    int Finish[n];

    for(int i = 0; i<m; i++)
        Work[i] = Available[i];
    for(int i = 0; i<n; i++)
        Finish[i] = 0;

    int p = 0;
    while(p<n){
        int count = 0;
        if(Finish[p] == 0){   
            for(int j = 0; j<m; j++){
                if(Need[p][j] <= Work[j])
                    count++;
            }
            if(count == m){
                for(int k = 0; k<m; k++){
                    Work[k] = Work[k] + Allocation[p][k];
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
    
    int Done = 0;
    for(int i = 0; i<n; i++)
        if(Finish[i])
            Done++;
    
    if(Done == n)
        return 1;
    else
        return 0;
}

void ifAlloc(int proc, int req[]){
    for(int i = 0; i<m; i++)
        Need[proc][i] += req[i];
    
    if(isSafe())
        printf("Proc %d can be allocated the request.\n", proc);
    else
        printf("Proc %d cannot be allocated the request.\n", proc);

    for(int i = 0; i<m; i++)
        Need[proc][i] -= req[i];
    
}

int main(){
    printf("Enter number of Processes and Resource Types: \n");
    scanf("%d %d", &n, &m);

    printf("Enter the Available vector:\n");
    for(int i = 0; i<m; i++)
        scanf("%d", &Available[i]);
    
    printf("Enter the Max Matrix:\n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter Allocation Matrix:\n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%d", &Allocation[i][j]);
    
    //calculate NEED
    calc_need();

    //Check safe-state
    if(isSafe())
        printf("System in Safe State\n");
    else
        printf("System not in Safe State\n");

    //check if req by p1 can be granted
    int req[3] = {1,0,2};
    ifAlloc(1, req);

    //check if req by p4 can be granted
    int req2[3] = {3, 3, 0};
    ifAlloc(4, req2);

    //check if req by p0 can be granted
    int req3[3] = {0, 2, 0};
    ifAlloc(0, req3);
}