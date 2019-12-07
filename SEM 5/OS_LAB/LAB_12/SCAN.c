#include <stdio.h>
#include <stdlib.h>
int requests[50];
int n_req;

void sort_req(){
    for(int i = 0; i<n_req-1; i++){
        for(int j = 0; j<n_req-i-1; j++){
            if(requests[j]>requests[j+1]){
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }
}

int getPos(int k){
    for(int i = 0; i<n_req; i++){
        if(requests[i]>k)
            return i-1;
    }
}

void SCAN(int start){
    int visit[n_req+1];
    visit[0] = start;
    int k = 1;
    sort_req();

    int from = getPos(start);
    printf("\n %d", from);
    for(int i = from; i>=0; i--){
        visit[k] = requests[i];
        k++;
    }

    visit[k] = 0;
    k++;

    for(int i = from+1; i<n_req; i++){
        visit[k] = requests[i];
        k++;
    }

    int cylinders = 0;
    for(int i = 0; i<k-1; i++)
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

    SCAN(st);
}