#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define frames 3
#define req 100

#define fifo 1
#define optimal 2
#define lru 3

int requests[req];
int fr[frames];
int n;

int for_fifo = -1;
int for_optimal = 0;

int init(){
    for(int i = 0; i<frames; i++)
        fr[i] = -1;
}

int has(int request){
    for(int i = 0; i<frames; i++)
        if(fr[i] == request)
            return 1;
    
    return 0;
}

int getReplacement(int algNo){

    if(algNo == fifo){
        return (++for_fifo)%frames;
    }
    else if(algNo == optimal){
        int selection;
        int temp = INT_MIN;
        for(int i = 0; i<frames; i++){
            int curr = fr[i];
            int count = 0;
            int j = for_optimal;
            while(j < n && curr != requests[j]){
                count++;
                j++;
            }
            if(count > temp){
                selection = i;
                temp = count;
            }
        }

        return selection;
    }
}

void PageReplacement(int alg){
    int pagehits = 0, pagefaults = frames;

    for(int i = 0; i<frames; i++){
        fr[i] = requests[i];
    }
    for(int i = frames; i<n; i++){
        if(has(requests[i]))
            pagehits++;
        else{
            if(alg == optimal){
                for_optimal = i;
            }
            pagefaults++;
            fr[getReplacement(alg)] = requests[i];
        }
    }
    printf("Page Faults: %d \nPage Hits: %d\n", pagefaults, pagehits);
}

int main(){

    printf("Enter number of requests: \n");
    scanf("%d", &n);
    printf("Enter requests: \n");
    for(int i = 0; i<n; i++)
        scanf("%d", &requests[i]);

    //Page replacement algos:
    printf("FIFO: \n");
    init();
    PageReplacement(fifo);

    printf("OPTIMAL: \n");
    init();
    PageReplacement(optimal);

    exit(0);
}