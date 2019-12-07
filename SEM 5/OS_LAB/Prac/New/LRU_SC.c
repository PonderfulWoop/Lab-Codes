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

int getLRU_SCpos(int iterator, int reference[]){
    while(1){
            if(reference[iterator] == 0)
                return iterator;
            else{
                reference[iterator] = 0;
                iterator = (iterator+1)%frames;
            }
    }
}

int LRU_SC(){
    int pagefaults = frames;
    int reference[frames];

    for(int i = 0; i<frames; i++)
        window[i] = requests[i];
    
    for(int i = 0; i<frames; i++){
        reference[i] = 1;
    }
    
    int iterator = 0;
    for(int i = frames; i<n; i++){
        if(!present(requests[i])){
            pagefaults++;

            iterator = getLRU_SCpos(iterator, reference);
            window[iterator] = requests[i];
            reference[iterator] = 1;
        }
        else{
            //Update reference
            for(int j = 0; j<frames; j++){
                if(window[j] == requests[i]){
                    reference[j] = 1;
                }
            }
        }
        iterator = (iterator+1)%frames;
    }

    printf("Page Faults: %d, Page Hits: %d\n", pagefaults, n - pagefaults);
}

int main(){
    printf("Enter number of requests & frame_size: \n");
    scanf("%d %d", &n, &frames);

    printf("Enter requests: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &requests[i]);
    
    LRU_SC();
}