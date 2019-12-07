#include <stdio.h>
#include <stdlib.h>

int segs;
int SEG_TABLE[50][2];

int main(){
    printf("Enter number of segments: \n");
    scanf("%d", &segs);
    printf("Enter limits and bases for the SEGMENTS:\n");
    for(int i = 0; i<segs; i++){
        scanf("%d %d", &SEG_TABLE[i][0], &SEG_TABLE[i][1]);
    }

    int segment, offset;
    printf("Enter segment and offset: \n");
    scanf("%d %d", &segment, &offset);

    //Checking
    if(SEG_TABLE[segment][0]<offset){
        printf("TRAP\n");
        exit(0);
    }

    printf("Physical Address: %d", offset+SEG_TABLE[segment][1]);
    
}