#include <stdio.h>
#include <stdlib.h>

int Allocation[20][20], Request[20][20], Available[20];
int m, n;

void chkDeadlock(){
    int Work[m];
    int Finish[n];

    for(int i = 0; i<m; i++)
        Work[i] = Available[i];
    
    for(int i = 0; i<n; i++){
        int req = 0;
        for(int j = 0; j<m; j++){
            req+=Allocation[i][j];
        }
        if(req == 0)
            Finish[i] = 1;
        else
            Finish[i] = 0;
    }

    int p = 0;
    while(p<n){
        int count = 0;
        if(!Finish[p]){
            for(int j = 0; j<m; j++)
                if(Request[p][j] < Work[j])
                    count++;
            
            if(count == m){
                for(int i = 0; i<m; i++){
                    Work[i] += Allocation[p][i];
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
    printf("Enter processes and instances: \n");
    scanf("%d", &n, &m);

    printf("Enter Allocation Matrix");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%d", &Allocation[i][j]);
    
    printf("Enter Request Matrix");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%d", &Request[i][j]);
    
    printf("Enter Available Vector:\n");
    for(int i = 0; i<n; i++)
        scanf("%d", &Available[i]);

    chkDeadlock();
}