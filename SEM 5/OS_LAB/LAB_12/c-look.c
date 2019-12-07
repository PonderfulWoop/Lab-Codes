#include <stdio.h>
#include <stdlib.h>
#define N 50

int requests[N];
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

int find_start_pos(int start){
    for(int i = 0; i<n_req; i++){
        if(requests[i]>start)
            return i-1;
    }
}

int CLOOK(int start){
    int visit_seq1[N], visit_seq2[N];
    visit_seq1[0] = start;
    sort_req();
    int k = 1;
    int k1 = 0;

    int go_right = find_start_pos(start);

    for(int i = go_right+1; i<n_req; i++){
        visit_seq1[k++] = requests[i];
    }
    for(int i = 0; i<=go_right; i++){
        visit_seq2[k1++] = requests[i];
    }
    int tracks = 0;
    for(int i = 0; i<k-1; i++){
        tracks += abs(visit_seq1[i] - visit_seq1[i+1]);
    }
    for(int i = 0; i<k1-1; i++){
        tracks += abs(visit_seq2[i] - visit_seq2[i+1]);
    }

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

    printf("Tracks: %d \n", CLOOK(st));
}