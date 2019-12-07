#include <stdio.h>
#include <stdlib.h>
int requests[50];
int n_req;

void FIFO(int start){
    int visit[n_req+1];
    visit[0] = start;
    int k = 1;
    for(int i = 0; i<n_req; i++){
        visit[k] = requests[i];
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
    for(int i = 0; i<n_req; i++)
        scanf("%d", &requests[i]);

    int st;
    printf("Enter start cylinder: \n");
    scanf("%d", &st);

    FIFO(st);
}