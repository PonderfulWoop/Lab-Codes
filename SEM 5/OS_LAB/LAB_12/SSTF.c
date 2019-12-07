#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int visted[50];
int requests[50];
int n_req;

int getNext(int curr){
    int val = INT_MAX;
    int next_pos = -1;

    for(int i = 0; i<n_req; i++){
        int test = abs(requests[i] - curr);
        if(test<val && !visted[i]){
            val = test;
            next_pos = i;
        }
    }
    visted[next_pos] = 1;
    return requests[next_pos];
}

void SSTF(int start){

    int visit[n_req+1];
    visit[0] = start;
    int k = 1;

    for(int i = 0; i<n_req; i++){
        visit[k] = getNext(visit[k-1]);
        k++;
    }

    int cylinders = 0;
    for(int i = 0; i<n_req; i++)
        cylinders+=abs(visit[i] - visit[i+1]);
    
    printf("No. of Cylinders: %d\n", cylinders);
}

int main(){
    printf("Enter no of requests: \n");
    scanf("%d", &n_req);

    printf("Enter requests: \n");
    for(int i = 0; i<n_req; i++){
        scanf("%d", &requests[i]);
        visted[i] = 0;
    }

    int st;
    printf("Enter start cylinder: \n");
    scanf("%d", &st);

    SSTF(st);
}