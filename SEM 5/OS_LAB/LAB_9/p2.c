#include <stdio.h>
#include <stdlib.h>

int n, m;
int Available[20], Allocation[20][20], Request[20][20];

int isDeadlock(){
    int Work[m];
    int Finish[n];

    for(int i = 0; i<m; i++)
        Work[i] = Available[i];

    for(int i = 0; i<n; i++){
        int flag = 0;
        for(int j = 0; j<m; j++){
            if(Allocation[i][j] != 0){
                flag = 1;
                break;
            }
        }
        if(flag)
            Finish[i] = 0;
    }

    int p = 0;
    while(p<n){
        int count = 0;
        if(Finish[p] == 0){   
            for(int j = 0; j<m; j++){
                if(Request[p][j] <= Work[j])
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

    int procs = 0;
    for(int i = 0; i<n; i++)
        if(Finish[i])
            procs++;
    
    if(procs == n)
        return 0;
    else
        return 1;

}

void stillSafe(int proc, int res){
    Request[proc][res]++;

    if(isDeadlock())
        printf("If p%d makes request for instance of %d, System will be deadlocked.\n", proc, res);
    else
        printf("If p%d makes request for instance of %d, System won't be deadlocked.\n", proc, res);
    
    Request[proc][res]--;
}

int main(){
    printf("Enter number of Processes and Resource Types: \n");
    scanf("%d %d", &n, &m);

    printf("Enter the Available vector:\n");
    for(int i = 0; i<m; i++)
        scanf("%d", &Available[i]);
    
    printf("Enter the Request Matrix:\n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%d", &Request[i][j]);

    printf("Enter Allocation Matrix:\n");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%d", &Allocation[i][j]);

    //Check deadlock-state
    if(isDeadlock())
        printf("System Deadlocked\n");
    else
        printf("System not Deadlocked\n");

    stillSafe(2, 2);
}