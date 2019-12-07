#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int frames, n;
int requests[100], window[100];

int present(int n){
    for(int i = 0; i<frames; i++)
        if(window[i] == n)
            return 1;
    
    return 0;
}

int getOptimalPOS(int from){
    int pos = -1;
    int test = INT_MIN;

    for(int i = 0; i<frames; i++){
        int count = 0;
        for(int j = from; j<n; j++){
            if(requests[j] != window[i])
                count++;
            else
                break;
        }
        if(count>test){
            test = count;
            pos = i;
        }
    }

    return pos;
}

int OPTIMAL(){
    int pagefaults = frames;
    for(int i = 0; i<frames; i++)
        window[i] = requests[i];
    
    int iterator;
    for(int i = frames; i<n; i++){
        if(!present(requests[i])){
            pagefaults++;

            iterator = getOptimalPOS(i);

            window[iterator] = requests[i];
        }
    }

    printf("Page Faults: %d, Page Hits: %d\n", pagefaults, n - pagefaults);
}

int main(){
    printf("Enter number of requests & frame_size: \n");
    scanf("%d %d", &n, &frames);

    printf("Enter requests: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &requests[i]);
    
    OPTIMAL();
}