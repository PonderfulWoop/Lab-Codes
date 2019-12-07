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

int getLRUpos(int used[]){
    int pos = 0;
    int count = used[0];
    for(int i = 1; i<frames; i++){
        if(used[i]>count){
            count = used[i];
            pos = i;
        }
    }

    return pos; // Least Recently Used
}

int LRU(){
    int pagefaults = frames;
    int used[frames];

    for(int i = 0; i<frames; i++)
        window[i] = requests[i];
    
    for(int i = 0; i<frames; i++){
        used[i] = frames-1-i;
    }
    
    int iterator;
    for(int i = frames; i<n; i++){
        if(!present(requests[i])){
            pagefaults++;

            iterator = getLRUpos(used);

            for(int k = 0; k<frames; k ++){
                if(k == iterator)
                    used[k] = 0; // Most Recently Used
                else
                    used[k]++;  //Update Use-time for others
            }

            window[iterator] = requests[i];
        }
        else{
            //Update Use-time
            for(int j = 0; j<frames; j++){
                if(window[j] == requests[i]){
                    used[j] = 0;
                }
                else{
                    used[j]++;
                }
            }
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
    
    LRU();
}