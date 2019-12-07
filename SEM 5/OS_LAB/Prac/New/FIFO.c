#include <stdio.h>
#include <stdlib.h>

int frames, n;
int requests[100], window[100];

int present(int n){
    for(int i = 0; i<frames; i++)
        if(window[i] == n)
            return 1;
    
    return 0;
}

int FIFO(){
    int pagefaults = frames;
    for(int i = 0; i<frames; i++)
        window[i] = requests[i];
    
    int iterator = 0;
    
    for(int i = frames; i<n; i++){
        if(!present(requests[i])){
            pagefaults++;
            window[iterator] = requests[i];
            iterator = (iterator + 1)%frames;
        }
    }

    printf("Page Faults: %d, Page Hits: %d\n", pagefaults, n - pagefaults);
}

int main(){
    printf("Enter number of requests & capacity: \n");
    scanf("%d %d", &n, &frames);

    printf("Enter requests: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &requests[i]);
    
    FIFO();
}