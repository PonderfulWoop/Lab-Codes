#include <stdio.h>
#include <stdlib.h>
#define N 50

int requests[N];
int n_req;

void sort_req(){
    for(int i = 0; i<n_req-1; i++){
        for(int j = 0; j<n_req-i-1; j++){
            if(requests[j+1]<requests[j]){
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }
}

int get_pos(int st){
    for(int i = 0; i<n_req; i++)
        if(requests[i]>st)
            return i-1;
}
int LOOK(int start){
    int visit_seq[N];
    visit_seq[0] = start;
    int k = 1;
    sort_req();
    int from = get_pos(start);

    for(int i = from; i>=0; i--)
        visit_seq[k++] = requests[i];
    for(int i = from+1; i<n_req; i++)
        visit_seq[k++] = requests[i];
    
    int tracks = 0;
    for(int i = 0; i<k-1; i++)
        tracks += abs(visit_seq[i] - visit_seq[i+1]);
    
    return tracks;
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

    printf("Tracks: %d \n", LOOK(st));
}